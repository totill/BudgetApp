#ifndef FILE_H
#define FILE_H

#include <iostream>
#include <fstream>

#include "Markup.h"
#include "Type.h"


using namespace std;

class File
{
    const string FILE_NAME;

protected:
    File(string fileName): FILE_NAME(fileName) {}
    int lastId;
    CMarkup xml;

    string getFileName();

public:
    bool isFileEmpty();
};

#endif // FILE_H
