#include "DateMethods.h"

void DateMethods::calculateCurrentDate(map<string, int>& currentDate)
{
    auto currentTime = chrono::system_clock::now();
    time_t currentDateTime = chrono::system_clock::to_time_t(currentTime);

    tm currentTm;
    localtime_s(&currentTm, &currentDateTime);

    currentDate["year"] = currentTm.tm_year + 1900;
    currentDate["month"] = currentTm.tm_mon + 1;
    currentDate["day"] = currentTm.tm_mday;
}

bool DateMethods::isYearLeap(int year)
{
    if (year % 400 == 0)
        return true;
    if (year % 100 == 0)
        return false;
    if (year % 4 == 0)
        return true;

    return false;
}

bool DateMethods::validateDate(string &date)
{
    int year, month, day;
    map<string, int> currentDate;
    stringstream ss;

    calculateCurrentDate(currentDate);

    if(date == "t" || date == "T")
    {
        ss << currentDate["year"] << '-' << (currentDate["month"] < 10 ? "0" : "") << currentDate["month"] << '-' << (currentDate["day"] < 10 ? "0" : "") << currentDate["day"];
        date = ss.str();
        return true;
    }

    if(date.length() != 10)
    {
        cout << "Incorrect date format. Enter again." << endl;
        return false;
    }

    if(!regex_match(date, regex("[0-9]{4}-[0-9]{2}-[0-9]{2}")))
    {
        cout << "Incorrect date format. Enter again." << endl;
        return false;
    }

    try
    {
        year = Utils::convertToInt(date.substr(0, 4));
        month = Utils::convertToInt(date.substr(5, 2));
        day = Utils::convertToInt(date.substr(8, 2));
    }
    catch(const exception& e)
    {
        cout << "Exception occured: " << e.what() << endl;
        return false;
    }

    if(year < 2000)
    {
        cout << "Invalid year. Enter again." << endl;
        return false;
    }

    if(month < 1 || month > 12)
    {
        cout << "Invalid month. Enter again." << endl;
        return false;
    }

    switch(month)
    {
    case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            if(day > 31)
            {
                cout << "Invalid day. Enter again." << endl;
                return false;
            }
            break;
    case 4: case 6: case 9: case 11:
            if(day > 30)
            {
                cout << "Invalid day. Enter again." << endl;
                return false;
            }
            break;
    case 2:
            if(isYearLeap(year))
            {
                if(day > 28)
                {
                    cout << "Invalid day. Enter again." << endl;
                    return false;
                }
            }
            else
            {
                if(day > 29)
                {
                    cout << "Invalid day. Enter again." << endl;
                    return false;
                }
            }
            break;
    default:
        cout << "Invalid day. Enter again." << endl;
        return false;
        break;

    }
    return true;
}

int DateMethods::convertStringDateToInt(string date)
{
    int dateAsInt = 0;
    string year, month, day;

    year = date.substr(0,4);
    month = date.substr(5,2);
    day = date.substr(8,2);

    dateAsInt = Utils::convertToInt(year + month + day);

    return dateAsInt;
}

string DateMethods::convertIntDateToStringWithDashes(int dateAsInt)
{
    string dateWithDashes = Utils::convertToString(dateAsInt);
    dateWithDashes.insert(4, "-");
    dateWithDashes.insert(7, "-");

    return dateWithDashes;
}

int DateMethods::getCurrentDate()
{
    string dateAsString = "";
    int currentDate = 0;

    time_t timestamp = time(0);
    struct tm datetime = *localtime(&timestamp);

    char output[11];
    strftime(output, 11, "%Y-%m-%d", &datetime);

    dateAsString = output;
    currentDate = convertStringDateToInt(dateAsString);

    return currentDate;
}

int DateMethods::getCurrentMonthFirstDayDate()
{
    string dateAsString = "";
    int dateAsInt = 0;
    map<string, int> currentDate;
    stringstream ss;

    calculateCurrentDate(currentDate);
    ss << currentDate["year"] << (currentDate["month"] < 10 ? "0" : "") << currentDate["month"] << "01";
    dateAsString = ss.str();
    dateAsInt = Utils::convertToInt(dateAsString);

    return dateAsInt;
}

int DateMethods::getPreviousMonthFirstDayDate()
{
    string dateAsString = "";
    int dateAsInt = 0;
    map<string, int> currentDate;
    stringstream ss;

    calculateCurrentDate(currentDate);

    if(currentDate["month"] == 1)
    {
        ss << currentDate["year"] - 1 << "12" << "01";
    }
    else
    {
        ss << currentDate["year"] << ((currentDate["month"] - 1) < 10 ? "0" : "") << (currentDate["month"] - 1) << "01";
    }

    dateAsString = ss.str();
    dateAsInt = Utils::convertToInt(dateAsString);

    return dateAsInt;
}

int DateMethods::getPreviousMonthLastDayDate()
{
    string dateAsString = "";
    int lastDayNumber = 0;
    int dateAsInt = 0;
    map<string, int> currentDate;
    stringstream ss;

    calculateCurrentDate(currentDate);

    if(currentDate["month"] == 1)
    {
        ss << (currentDate["year"] - 1) << "12" << "31";
    }
    else
    {
        ss << currentDate["year"] << ((currentDate["month"] - 1) < 10 ? "0" : "") << (currentDate["month"] - 1) << (currentDate["day"] < 10 ? "0" : "") << currentDate["day"];
        dateAsString = ss.str();
        lastDayNumber = getNumberOfDaysInMonth(dateAsString);

        ss.str("");
        dateAsString = "";

        ss << currentDate["year"] << ((currentDate["month"] - 1) < 10 ? "0" : "") << (currentDate["month"] - 1) << lastDayNumber;
    }

    dateAsString = ss.str();
    dateAsInt = Utils::convertToInt(dateAsString);

    return dateAsInt;
}

int DateMethods::getNumberOfDaysInMonth(string &date)
{
    int numberOfDaysInMonth = 0;
    int year, month;

    year = Utils::convertToInt(date.substr(0, 4));
    month = Utils::convertToInt(date.substr(4, 2));

    if(month == 2 && ((year%400 == 0) || ((year%100 != 0) && (year%4 == 0))))
        numberOfDaysInMonth = 29;
    else
        numberOfDaysInMonth = 28;

        if(month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
            numberOfDaysInMonth = 31;
        else
            numberOfDaysInMonth = 30;

    return numberOfDaysInMonth;
}
