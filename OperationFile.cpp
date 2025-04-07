#include "OperationFile.h"

void OperationFile::addOperationToFile(Operation &operation, const Type &type)
{
    string fileName = "";
    string operationType = "";

    switch(type)
    {
    case INCOME:
        fileName = "incomes.xml";
        operationType = "Income";
        break;
    case EXPENSE:
        fileName = "expenses.xml";
        operationType = "Expense";
        break;
    }

    if (!xml.Load(fileName))
    {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem(fileName);
    }

    xml.ResetPos();
    xml.FindElem();
    xml.IntoElem();
    xml.AddElem(operationType);
    xml.IntoElem();
    xml.AddElem("Id", operation.id);
    xml.AddElem("UserId", operation.userId);
    xml.AddElem("Date", operation.date);
    xml.AddElem("Item", operation.item);
    xml.AddElem("Amount", operation.amount);

    xml.Save(fileName);
}

vector <Operation> OperationFile::loadIncomesFromFile(const int loggedUserId)
{
    Operation income;
    vector <Operation> incomes;

    bool fileExists = xml.Load("incomes.xml");
    if (!fileExists)
    {
        system("cls");
        cout << "There aren't any incomes yet. Incomes file has been created." << endl;
        system("pause");
    }
    else
    {
        xml.ResetPos();
        xml.IntoElem();
        xml.FindElem();
        xml.IntoElem();
        xml.FindElem();

        do
        {
            xml.IntoElem();

            xml.FindElem();
            income.id = atoi(xml.GetData().c_str());

            xml.FindElem();
            income.userId = atoi(xml.GetData().c_str());

            xml.FindElem();
            income.date = atoi(xml.GetData().c_str());

            xml.FindElem();
            income.item = xml.GetData();

            xml.FindElem();
            income.amount = xml.GetData().c_str();

            if(income.userId == loggedUserId)
                incomes.push_back(income);

            xml.OutOfElem();
        }
        while(xml.FindElem());
    }
    return incomes;
}

vector <Operation> OperationFile::loadExpensesFromFile(const int loggedUserId)
{
    Operation expense;
    vector <Operation> expenses;

    bool fileExists = xml.Load("expenses.xml");
    if (!fileExists)
    {
        system("cls");
        cout << "There aren't any expenses yet. Expenses file has been created." << endl;
        system("pause");
    }
    else
    {
        xml.ResetPos();
        xml.IntoElem();
        xml.FindElem();
        xml.IntoElem();
        xml.FindElem();

        do
        {
            xml.IntoElem();

            xml.FindElem();
            expense.id = atoi(xml.GetData().c_str());

            xml.FindElem();
            expense.userId = atoi(xml.GetData().c_str());

            xml.FindElem();
            expense.date = atoi(xml.GetData().c_str());

            xml.FindElem();
            expense.item = xml.GetData();

            xml.FindElem();
            expense.amount = xml.GetData().c_str();

            if(expense.userId == loggedUserId)
                expenses.push_back(expense);

            xml.OutOfElem();
        }
        while(xml.FindElem());
    }
    return expenses;
}

int OperationFile::getLastId(const Type &type)
{
    int lastId = 1;
    string fileName = "";

    switch (type) {
    case INCOME:
        fileName = "incomes.xml";
        break;
    case EXPENSE:
        fileName = "expenses.xml";
        break;
    }

    if (!xml.Load(fileName))
    {
        return lastId;
    }
    else
    {
        xml.ResetPos();
        xml.IntoElem();
        xml.FindElem();
        xml.IntoElem();
        xml.FindElem();

        do
        {
            xml.IntoElem();
            xml.FindElem();
            lastId = atoi(xml.GetData().c_str());
            xml.FindElem();
            xml.FindElem();
            xml.FindElem();
            xml.FindElem();
            xml.OutOfElem();
        }
        while (xml.FindElem());

        return lastId + 1;
    }
}
