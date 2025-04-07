#include "UserFile.h"

void UserFile::addUserToFile(const User &user)
{
    bool fileExists = xml.Load("users.xml");

    if (!fileExists)
    {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Users");
    }

    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("User");
    xml.IntoElem();
    xml.AddElem("UserId", user.id);
    xml.AddElem("Login", user.login);
    xml.AddElem("Password", user.password);
    xml.AddElem("FirstName", user.firstName);
    xml.AddElem("LastName", user.lastName);

    xml.Save("users.xml");
}

vector <User> UserFile::loadUsersFromFile()
{
    User user;
    vector <User> users;
    bool fileExists = xml.Load("users.xml");

    if (!fileExists)
    {
        cout << "There aren't any users yet. Users file has been created." << endl;
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
            user.id = atoi(xml.GetData().c_str());

            xml.FindElem();
            user.login = xml.GetData();

            xml.FindElem();
            user.password = xml.GetData();

            xml.FindElem();
            user.firstName = xml.GetData();

            xml.FindElem();
            user.lastName = xml.GetData();

            users.push_back(user);
            xml.OutOfElem();
        }
        while(xml.FindElem());


    }
    return users;
}

void UserFile::changePasswordInFile(int id, const string &password)
{
    bool fileExists = xml.Load("users.xml");

    if (!fileExists)
    {
        cout << "There aren't any users yet. Users file has been created." << endl;
        system("pause");
    }
    else
    {
        xml.FindElem();
        xml.IntoElem();

        while(xml.FindElem("User"))
        {
            xml.FindChildElem("UserId");
            string userId = xml.GetChildData();
            if(Utils::convertToInt(userId) == id)
            {
                xml.FindChildElem("Password");
                xml.SetChildData(password);
            }
        }
    }
    xml.Save("users.xml");
}



