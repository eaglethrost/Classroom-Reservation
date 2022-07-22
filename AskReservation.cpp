/* Function to ask user if they want a user to reserve a room
   Check user's input, accept only Y/y/N/n
   Return true if user accepts and vice versa
*/
#include <iostream>

bool ask_reservation()
{
    char reserve_input;
    std::cout << "Would you like to reserve this room? press (y/n) ";
    std::cin >> reserve_input;
    // valid inputs = Y,y,N,n
    while (reserve_input != 'Y' && reserve_input != 'y' && reserve_input != 'N' && reserve_input != 'n')
    {
        std::cout << "Please type in Y/y/N/n ";
        std::cin >> reserve_input; 
    }
    // if yes, commence making reservation process
    if (reserve_input == 'Y' || reserve_input == 'y')
    {
        return 1;
    }
    return 0;

}