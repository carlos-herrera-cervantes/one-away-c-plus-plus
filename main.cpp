#include <iostream>
#include <string>

using namespace std;

/**
 * Checks if a character is replaced to the first string, it becomes the second.
 * @param str1 First string
 * @param str2 Second string
 * @returns If possible to convert the first string to the second it returns true, otherwise false
 */
bool is_one_edit_replace(string str1, string str2)
{
    bool foundDifference = false;

    for (int i = 0; i < str1.length(); i++)
    {
        if (str1.at(i) != str2.at(i))
        {
            if (foundDifference) return false;
            foundDifference = true;
        }
    }

    return true;
}

/**
 * Checks if a character is added to the first string, it becomes the second.
 * @param str1 First string
 * @param str2 Second string
 * @returns If possible to convert the first string to the second it returns true, otherwise false
 */
bool is_one_edit_insert(string str1, string str2)
{
    int index1 = 0, index2 = 0;

    while (index2 < str2.length() && index1 < str1.length())
    {
        if (str1.at(index1) != str2.at(index2))
        {
            if (index1 != index2) return false;
            index2++;
        }
        else
        {
            index1++;
            index2++;
        }
    }

    return true;
}

/**
 * Checks if the first string is one away edition or insertion to become the second
 * @param str1 First string
 * @param str2 Second string
 * @returns If possible to convert the first string to the second it returns true, otherwise false
 */
bool is_one_edit_away(string str1, string str2)
{
    if (str1.length() == str2.length())
    {
        return is_one_edit_replace(str1, str2);
    }
    else if (str1.length() + 1 == str2.length())
    {
        return is_one_edit_insert(str1, str2);
    }
    else if (str1.length() - 1 == str2.length())
    {
        return is_one_edit_insert(str1, str2);
    }

    return false;
}

int main()
{
    cout << "THIS PROGRAM TAKES TWO STRINGS AND CHECKS IF ONE OF THE BOTH IS ONE AWAY EDITION OF INSERTION TO BECOME THE OTHER" << endl << endl;
    string str1;

    cout << "Enter the first string: ";
    cin >> str1;
    
    string str2;
    cout << "Enter the secong string: ";
    cin >> str2;
    
    cout << endl << endl;

    string first = str1.length() < str2.length() ? str1 : str2;
    string second = str1.length() > str2.length() ? str1 : str2;
    
    bool isOneAway = is_one_edit_away(first, second);

    cout << "Is one away edit?: " << isOneAway;
    return 0;
}