#ifndef DATEMETHODS_H
#define DATEMETHODS_H

#include "Utils.h"
#include <iostream>
#include <ctime>
#include <regex>
#include <chrono>
#include <map>
#include <sstream>
#include <string>
#include <algorithm>

using namespace std;

class DateMethods
{
    static void calculateCurrentDate(map<string, int> &currentDate);
    static bool isYearLeap(int year);
    static int getNumberOfDaysInMonth(string &date);

public:
    static bool validateDate(string &date);

    static int convertStringDateToInt(string date);
    static string convertIntDateToStringWithDashes(int dateAsInt);
    static int getCurrentDate();

    static int getCurrentMonthFirstDayDate();
    static int getPreviousMonthLastDayDate();
    static int getPreviousMonthFirstDayDate();
};

#endif // DATEMETHODS_H
