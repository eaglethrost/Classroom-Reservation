/* Function to check if date inputed by user follows DD/MM/YYYY format
   Takes in a user input of date
   Checks the presence of / in the input
   Checks presence of integer
   If the input fails one of those tests, return false
*/
#include <iostream>

bool check_date_input(std::string date)
{
    // the required format has 10 characters
    if (date.length() != 10)
    {
        return 0;
    }
    // check if / is where it should be
    if (date[2] != '/' && date[5] != '/')
    {
        return 0;
    }
    // check if the characters are integers
    for (int i = 0; i < date.length(); i++)
    {
        if (isdigit(date[i]) == 0 && i != 2 && i != 5)
        {
            return 0;
        }
    }
    return 1;
}