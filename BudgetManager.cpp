#include "BudgetManager.h"

Operation BudgetManager::addOperationDetails(const Type &type)
{
    string typeDescription, tempDate, tempAmount;
    Operation operation;

    Menus::showTitle("ADD OPERATION DETAILS");

    switch(type)
    {
    case INCOME:
        operation.id = incomeFile.getLastId(INCOME);
        typeDescription = "income";
        break;
    case EXPENSE:
        operation.id = expenseFile.getLastId(EXPENSE);
        typeDescription = "expense";
        break;
    }

    operation.userId = LOGGED_USER_ID;

    do
    {
        cout << "Enter " << typeDescription << " date. Press 't' if you want to enter current date: ";
        tempDate = Utils::readLine();
    }
    while(!DateMethods::validateDate(tempDate));

    operation.date = DateMethods::convertStringDateToInt(tempDate);

    cout << "Enter " << typeDescription << " name: ";
    operation.item = Utils::readLine();

    do
    {
        cout << "Add " << typeDescription << " amount with two decimal places: ";
        tempAmount = Utils::readLine();
    }
    while(!CashMethods::validateAmount(tempAmount));

    operation.amount = Utils::replaceCommaByDot(tempAmount);

    return operation;
}

void BudgetManager::showBalance(int startDate, int endDate)
{
    system("cls");
    double balance = 0.00;
    balance = calculateBalance(startDate, endDate, INCOME) - calculateBalance(startDate, endDate, EXPENSE);

    cout << "The balance is: " << setprecision(2) << fixed << balance << endl;

    system("pause");
}

double BudgetManager::calculateBalance(int startDate, int endDate, const Type &type)
{
    double budgetAmount = 0.00;

    switch(type)
    {
    case INCOME:
        for(size_t i=0; i < incomes.size(); i++)
        {
            if((incomes[i].date >= startDate) && (incomes[i].date <= endDate))
                budgetAmount += Utils::convertStringToDouble(incomes[i].amount);
        }
        break;

    case EXPENSE:
        for(size_t i=0; i < expenses.size(); i++)
        {
            if((expenses[i].date >= startDate) && (expenses[i].date <= endDate))
                budgetAmount += Utils::convertStringToDouble(expenses[i].amount);
        }
        break;
    }

    return budgetAmount;
}

void BudgetManager::addIncome()
{
    system("cls");
    cout << "ADDING NEW INCOME" << endl;

    Operation income = addOperationDetails(INCOME);
    incomes.push_back(income);
    incomeFile.addOperationToFile(income, INCOME);

    cout << "Income has been added." << endl;
    system("pause");
}

void BudgetManager::addExpense()
{
    system("cls");
    cout << "ADDING NEW EXPENSE" << endl;

    Operation expense = addOperationDetails(EXPENSE);
    expenses.push_back(expense);
    expenseFile.addOperationToFile(expense, EXPENSE);

    cout << "Expense has been added." << endl;
    system("pause");
}

void BudgetManager::showCurrentMonthBalance()
{
    showBalance(DateMethods::getCurrentMonthFirstDayDate(), DateMethods::getCurrentDate());
}

void BudgetManager::showPreviousMonthBalance()
{
    showBalance(DateMethods::getPreviousMonthFirstDayDate(), DateMethods::getPreviousMonthLastDayDate());
}

void BudgetManager::showCustomPeriodBalance()
{
    system("cls");
    string startDate, endDate = "";

    cout << "Enter start date: ";
    startDate = Utils::readLine();

    cout << "Enter end date: ";
    endDate = Utils::readLine();

    showBalance(DateMethods::convertStringDateToInt(startDate), DateMethods::convertStringDateToInt(endDate));
    }

