/*  Script to test every methods of Reservation Class that doesn't involve other class and check if values are stored properly
    - Create 2 reservations, 1 default
    - Ask user for date, start time, end time, description
    - Print attributes
*/

#include "Reservation.h"
#include <iostream>
#include "User.h"

int main(void)
{
    // make default reservation
    Reservation reservation1 = Reservation();
    // prompt user for reservation details
    User* user = new User();
    std::string date, start_hour, start_minute, end_hour, end_minute;
    std::string description;
    char x = ':';
    
    std::cout << "Please enter date: " << std::endl;
    std::cin >> date;
    std::cout << "Please enter start date (HH:MM) and end date (HH:MM): " << std::endl;
    std::cin >> start_hour >> start_minute >> end_hour >> end_minute;
    std::cout << "Please enter your reason for reservation: " << std::endl;
    std::getline(std::cin >> std::ws, description);
        
    // make reservation
    Reservation reservation2 = Reservation(date, start_hour, start_minute, end_hour, end_minute, description, user);
    
    // print attributes
    std::cout << "ID:" << reservation1.get_id() <<  " Date:" << reservation1.get_date() << " Start Time:" << reservation1.get_start_time_hour() << reservation1.get_start_time_minute() 
    << " End Time:" << reservation1.get_end_time_hour() << reservation1.get_end_time_minute() << " Description:" << reservation1.get_description() << std::endl;
    
    std::cout << "ID:" << reservation2.get_id() <<  " Date:" << reservation2.get_date() << " Start Time:" << reservation2.get_start_time_hour() << reservation2.get_start_time_minute()
    << " End Time:" << reservation2.get_end_time_hour() << reservation2.get_end_time_minute() << " Description:" << reservation2.get_description();
    delete user;

    return 0;
}