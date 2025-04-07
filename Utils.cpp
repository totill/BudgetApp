#include "Utils.h"


char Utils::getCharacter()
{
    string input = "";
    char character  = {0};

    while (true)
    {
        getline(cin, input);

        if (input.length() == 1)
        {
            character = input[0];
            break;
        }
        cout << "This isn't single character. Enter again." << endl;
    }
    return character;
}

string Utils::readLine()
{
    string input = "";
    cin.sync();
    getline(cin, input);
    return input;
}

string Utils::convertToString(int number)
{
    ostringstream ss;
    ss << number;
    string str = ss.str();
    return str;
}

int Utils::convertToInt(string text)
{
    int number;
    istringstream iss(text);
    iss >> number;
    return number;
}

double Utils::convertStringToDouble(string text)
{
    stringstream ss(text);
    double result;
    if (ss >> result)
    {
        return result;
    }
    else
    {
        cout << "Conversion failed." << endl;
    }
}

string Utils::replaceCommaByDot(string text)
{
    replace(text.begin(), text.end(), ',', '.');
    return text;
}

