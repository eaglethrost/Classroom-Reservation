/* Function for user login
   Prompt user for name
   Prompt user for valid ID 
   If user types in a decimal number, only the number before decimal is taken

   Create a user object and return it
*/
#include <iostream>
#include <string>

#include "User.h"

extern bool check_input_validity(std::string, int, int, int);

User user_login()
{
    // description
    std::cout << "Student Login Page" << std::endl;

    // get student name and id
    std::string name, temp_id;

    std::cout << "Please enter your name: ";
    std::getline (std::cin,name);
    // id constrains: not negative
    std::cout << "Please enter your ID: ";
    std::cin >> temp_id;
    while (check_input_validity(temp_id, 0, INT_MAX, 0) == 0)
    {
        std::cout << "Please type a valid ID: ";
        std::cin >> temp_id;
    }
    int id = std::stoi(temp_id);

    // create user
    User student = User(name, id);
    std::cout << "Name:" << student.get_name() << " ID:" << student.get_id() << std::endl;
    return student;
}