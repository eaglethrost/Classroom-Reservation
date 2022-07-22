#include <string>
#include <iostream>

#include "Reservation.h"
#include "User.h"

int Reservation::IDtracker = 0;

// default constructor for reservation, sets attributes to empty/0/NULL and increments ID tracker
Reservation::Reservation()
{
    date = "?";
    start_time_hour = "00";
    start_time_minute = "00";
    end_time_hour = "00";
    end_time_minute = "00";
    id = IDtracker;
    description = "?";
    requester = NULL;
    IDtracker++;
}

/*  custom constructor for reservations
    takes in date, start time, end time of reservation, reason for reservation, the room requested and user who requested it
    assigns those arguments to their corresponding attribute and increments ID tracker
*/
Reservation::Reservation(std::string Date, std::string Start_time_hour, std::string Start_time_minute, std::string End_time_hour, std::string End_time_minute, std::string Description, User* Requester)
{
    date = Date;
    start_time_hour = Start_time_hour;
    start_time_minute = Start_time_minute;
    end_time_hour = End_time_hour;
    end_time_minute = End_time_minute;
    id = IDtracker;
    description = Description;
    
    //equestedRoom = RequestedRoom;
    requester = Requester;
    IDtracker++;
}

// returns reservation id
int Reservation::get_id()
{
    return id;
}

// returns start time hour of reservation
std::string Reservation::get_start_time_hour()
{
    return start_time_hour;
}

// returns start time minute of reservation
std::string Reservation::get_start_time_minute()
{
    return start_time_minute;
}

// returns end time hour of reservation
std::string Reservation::get_end_time_hour()
{
    return end_time_hour;
}

// returns end time minute of reservation
std::string Reservation::get_end_time_minute()
{
    return end_time_minute;
}


// returns date of reservation
std::string Reservation::get_date()
{
    return date;
}

// returns reason of reservation
std::string Reservation::get_description()
{
    return description;
}
// returns user who requested room
User* Reservation::get_user()
{
    return requester;
}

void Reservation::print_reservation()
{
    std::cout << "ID:" << id << " Requester:";
    if (requester == NULL)
    {
        std::cout << "Unknown";
    }
    else
    {
        std::cout << requester->get_name();
    }
    std::cout << " Date:" << date << " Time:" << start_time_hour << ":" << start_time_minute << "-" << end_time_hour << ":" << end_time_minute <<
        " Reason:" << description << std::endl;
    
}

// destructor
Reservation::~Reservation()
{
}