#include "Menus.h"

void Menus::showTitle(string menuName)
{
    cout << menuName << endl;
}

void Menus::showHomeMenu()
{
    cout << "---------------------------" << endl;
    cout << "1. User login" << endl;
    cout << "2. User registration" << endl;
    cout << "9. Program exit" << endl;
    cout << "---------------------------" << endl;
    cout << "Your choice: ";
}

void Menus::showMainMenu()
{
    cout << "---------------------------" << endl;
    cout << "1. Add income" << endl;
    cout << "2. Add expense" << endl;
    cout << "3. Show current month balance" << endl;
    cout << "4. Show previous month balance" << endl;
    cout << "5. Show custom period balance" << endl;
    cout << "---------------------------" << endl;
    cout << "6. Change user password" << endl;
    cout << "8. Logout user" << endl;
    cout << "---------------------------" << endl;
    cout << "Your choice: ";
}
