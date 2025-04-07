#include "CashMethods.h"

bool CashMethods::validateAmount(string amount)
{
    bool ifDotIs = false, isAmountDigit = false;
    int numberOfDecimalPlaces = 0;

    for (int i = 0; i < amount.size(); i++)
    {
        if (amount[i] == '.' || amount[i] == ',' )
            ifDotIs = true;

        if(ifDotIs)
            numberOfDecimalPlaces++;

        if(amount[i] == '.' || amount[i] == ',')
            continue;

        else if(isdigit(amount[i]))
            isAmountDigit = true;

        else
        {
            isAmountDigit = false;
            break;
        }
    }

    if (!isAmountDigit)
    {
        cout << "Wrong amount format. Enter amount again two decimal places, using digits and dot or coma as separator" << endl;
        return false;
    }
    else if (!ifDotIs)
    {
        cout << "Wrong amount format." << endl;
        return false;
    }
    else if((1 == numberOfDecimalPlaces)|| (numberOfDecimalPlaces == 2))
    {
        cout << "Wrong amount format." << endl;
        return false;
    }
    else if(numberOfDecimalPlaces > 3)
    {
        cout << "Wrong amount format." << endl;
        return false;
    }
    else
    {
        return true;
    }
}

