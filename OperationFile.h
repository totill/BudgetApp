#ifndef OPERATIONFILE_H
#define OPERATIONFILE_H

#include <iostream>
#include <vector>

#include "Type.h"
#include "Operation.h"
#include "Markup.h"
#include "Utils.h"
#include "File.h"


using namespace std;

class OperationFile :public File
{
    CMarkup xml;

public:
    OperationFile(string fileName) : File(fileName) {};

    void addOperationToFile(Operation &operation, const Type &type);
    vector <Operation> loadIncomesFromFile(const int loggedUserId);
    vector <Operation> loadExpensesFromFile(const int loggedUserId);
    int getLastId(const Type &type);
};

#endif // OPERATIONFILE_H
