/* Function to check if an input is valid (correct type and in the required interval)
   Takes in input, lower bound and upper bound as parameter
   If input is not integer, print please type an integer
   If input is off-range, print please input between 1-5
   Returns bool, 1 if input is valid and vice versa
*/

#include <iostream>

bool check_input_validity(std::string input, int min, int max, int required_digits)
{
    // if required digits' value is 0, there is no requirements
    if (required_digits > 0 && input.length() != required_digits)
    {
        return 0;
    }
    // check if input is integer (https://www.geeksforgeeks.org/program-check-input-integer-string/)
    for (int i = 0; i < input.length(); i++)
    {
        if (isdigit(input[i]) == 0)
        {
            return 0;
        }
    }
    // check if input is in required interval
    int int_input = std::stoi(input);
    if (int_input > max || int_input < min)
    {
        return 0;
    }
 
    return 1;
}