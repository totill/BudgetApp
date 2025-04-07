#include "UserManager.h"

    void findUserByLogin(const string &login, vector<User>::iterator &itr);
    void findUserById(vector<User>::iterator &itr);

bool UserManager::checkIfLoginExists(const string &login)
{
    for(int i=0; i < users.size(); i++)
    {
        if(users[i].login == login)
        {
            cout << endl << "User's login already exists." << endl;
            return true;
        }
    }
    return false;
}

User UserManager::enterUserData()
{
    User user;
    user.id = getNewUserId();

    string login, password, firstName, lastName;

    do
    {
        cout << "Enter login: ";
        login = Utils::readLine();
        user.login = login;
    }
    while (checkIfLoginExists(user.login) == true);

    cout << "Enter password: ";
    password = Utils::readLine();
    user.password = password;

    cout << "Enter first name: ";
    firstName = Utils::readLine();
    user.firstName = firstName;

    cout << "Enter last name: ";
    lastName = Utils::readLine();
    user.lastName = lastName;

    return user;
}

int UserManager::getNewUserId()
{
    if(users.empty() == true)
        return 1;
    else
        return users.back().id + 1;
}

void UserManager::registerUser()
{
    User user = enterUserData();

    users.push_back(user);
    userFile.addUserToFile(user);

    cout << endl << "Account's been successfully created." << endl << endl;
    system("pause");
}

void UserManager::loginUser()
{
    User user;
    string login = "", password = "";

    cout << endl << "Enter login: ";
    login = Utils::readLine();

    for(int i=0; i < users.size(); i++)
    {
        if(users[i].login == login)
        {
            for(int attemptsNumber = 3; attemptsNumber > 0; attemptsNumber--)
            {
                cout << "Enter password. Attempts remain: " << attemptsNumber << ": ";
                password = Utils::readLine();

                if (users[i].password == password)
                {
                    cout << endl << "You have successfully logged in." << endl << endl;
                    system("pause");
                    loggedUserId = users[i].id;
                    return;
                }
            }
            cout << "You have entered wrong password 3 times in a row." << endl;
            system("pause");
            return;
        }
    }

    cout << "This user's login doesn't exist." << endl << endl;
    system("pause");
}

void UserManager::changeUserPassword()
{
    string newPassword = "";
    cout << "Enter new password: ";
    newPassword = Utils::readLine();

    for(int i=0; i < users.size(); i++)
    {
        if(users[i].id == loggedUserId)
        {
            users[i].password = newPassword;
            cout << "Password has been changed." << endl << endl;
            system("pause");
        }
    }
    userFile.changePasswordInFile(loggedUserId, newPassword);
}

void UserManager::logoutUser()
{
    char character;

    cout << endl << "To confirm logging out, press button 'y': ";
    character = Utils::getCharacter();
    if(character == 'y')
    {
        loggedUserId = 0;
        cout << "You've been logged out." << endl;
    }
}

bool UserManager::isUserLoggedIn()
{
    if(loggedUserId > 0)
        return true;
    else
        return false;
}

int UserManager::getLoggedUserId()
{
    return loggedUserId;
}
