#ifndef BUDGETMANAGER_H
#define BUDGETMANAGER_H

#include <iostream>
#include <iomanip>
#include <vector>
#include <windows.h>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdlib>

#include "Utils.h"
#include "Type.h"
#include "DateMethods.h"
#include "CashMethods.h"
#include "Operation.h"
#include "OperationFile.h"
#include "Menus.h"


using namespace std;

class BudgetManager
{
    const int LOGGED_USER_ID;
    OperationFile incomeFile;
    OperationFile expenseFile;
    vector <Operation> incomes;
    vector <Operation> expenses;

    Operation addOperationDetails(const Type &type);
    void showBalance(int startDate, int endDate);
    double calculateBalance(int startDate, int endDate, const Type &type);

public:
    BudgetManager(string incomeFileName, string expenseFileName, int loggedUserId)
    : LOGGED_USER_ID(loggedUserId),
    incomeFile(incomeFileName),
    expenseFile(expenseFileName)
    {
        incomes = incomeFile.loadIncomesFromFile(LOGGED_USER_ID);
        expenses = expenseFile.loadExpensesFromFile(LOGGED_USER_ID);
    };

    void addIncome();
    void addExpense();
    void showCurrentMonthBalance();
    void showPreviousMonthBalance();
    void showCustomPeriodBalance();
};

#endif // BUDGETMANAGER_H
