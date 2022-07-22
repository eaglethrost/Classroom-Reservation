// Function to print list of classrooms in Menu
#include <iostream>
#include <unistd.h>

void print_main_menu()
{
    // list rooms and test user inputs
    std::cout << "Please type in between 1-5 to do one of these actions:" << std::endl;
    std::cout << "1) Check and book Classroom 1" << std::endl;
    std::cout << "2) Check and book Classroom 2" << std::endl;
    std::cout << "3) Check and book Hall 1" << std::endl;
    std::cout << "4) Check and book Hall 2" << std::endl;
    std::cout << "5) Exit" << std::endl;
}