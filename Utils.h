#ifndef UTILS_H
#define UTILS_H

#include <iostream>
#include <sstream>
#include <algorithm>
#include <string>

using namespace std;

class Utils
{
public:
    static string readLine();
    static char getCharacter();
    static string convertToString(int number);
    static int convertToInt(string text);
    static double convertStringToDouble(string text);
    static string replaceCommaByDot(string text);
};

#endif // UTILS_H
