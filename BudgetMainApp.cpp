#include "BudgetMainApp.h"

bool BudgetMainApp::isUserLoggedIn()
{
    return userManager.isUserLoggedIn();
}

void BudgetMainApp::registerUser()
{
    userManager.registerUser();
}

void BudgetMainApp::loginUser()
{
    userManager.loginUser();

    if(userManager.isUserLoggedIn())
    {
        budgetManager = new BudgetManager(INCOME_FILE_NAME, EXPENSE_FILE_NAME, userManager.getLoggedUserId());
    }
}

void BudgetMainApp::changeUserPassword()
{
    userManager.changeUserPassword();
}

void BudgetMainApp::logoutUser()
{
    userManager.logoutUser();
    delete budgetManager;
    budgetManager = NULL;
}

void BudgetMainApp::addIncome()
{
    if(userManager.isUserLoggedIn())
    {
        budgetManager -> addIncome();
    }
    else
    {
        cout << "Log in to add an income." << endl;
        system("pause");
    }
}

void BudgetMainApp::addExpense()
{
    if(userManager.isUserLoggedIn())
    {
        budgetManager -> addExpense();
    }
    else
    {
        cout << "Log in to add an expense." << endl;
        system("pause");
    }
}

void BudgetMainApp::showCurrentMonthBalance()
{
    budgetManager -> showCurrentMonthBalance();
}

void BudgetMainApp::showPreviousMonthBalance()
{
    budgetManager -> showPreviousMonthBalance();
}

void BudgetMainApp::showCustomPeriodBalance()
{
    budgetManager -> showCustomPeriodBalance();
}
