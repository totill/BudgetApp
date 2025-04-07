#ifndef USERMANAGER_H
#define USERMANAGER_H

#include <iostream>
#include <vector>
#include <windows.h>
#include <fstream>
#include <sstream>

#include "Utils.h"
#include "User.h"
#include "UserFile.h"

using namespace std;

class UserManager
{
    int loggedUserId;
    vector <User> users;
    UserFile userFile;

    bool checkIfLoginExists(const string &login);
    User enterUserData();
    int getNewUserId();
    void findUserByLogin(const string &login, vector<User>::iterator &itr);
    void findUserById(vector<User>::iterator &itr);

public:
    UserManager(string userFileName) : userFile(userFileName)
    {
        users = userFile.loadUsersFromFile();
        loggedUserId = 0;
    };

    void registerUser();
    void loginUser();
    void changeUserPassword();
    void logoutUser();

    bool isUserLoggedIn();
    int getLoggedUserId();
};

#endif // USERMANAGER_H
