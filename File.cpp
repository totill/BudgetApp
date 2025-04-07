#include "File.h"

string File::getFileName()
{
    return FILE_NAME;
}

bool File::isFileEmpty()
{
    CMarkup xml;
    bool fileExists = xml.Load(FILE_NAME);

    return fileExists;
}
