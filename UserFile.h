#ifndef USERFILE_H
#define USERFILE_H

#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>

#include "User.h"
#include "Utils.h"
#include "File.h"
#include "Markup.h"


using namespace std;

class UserFile :public File
{
    CMarkup xml;

public:
    UserFile(string fileName) : File(fileName) {};

    void addUserToFile(const User &user);
    vector <User> loadUsersFromFile();
    void changePasswordInFile(int id, const string &password);
};

#endif // USERFILE_H
