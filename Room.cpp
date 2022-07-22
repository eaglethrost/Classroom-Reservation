#include <string>
#include <vector>

#include "Room.h"
#include "Reservation.h"

// default constructor of room, set attributes to empty/0
Room::Room()
{
    name = "?";
    roomCode = 0;
}

// constructor of room, takes in room name and room code as parameters and stores them in their corresponding attribute
Room::Room(std::string Name, int RoomCode)
{
    name = Name;
    roomCode = RoomCode;
}

// returns name of the room
std::string Room::get_name()
{
    return name;
}

// returns code of room
int Room::get_roomCode()
{
    return roomCode;
}

// returns pointer to vector of reservations made for room
Reservation** Room::get_reservations()
{
    return reservations.data();
}

// returns number of reservations
int Room::get_no_of_reservations()
{
    return reservations.size();
}

// takes in a reservation object as parameter and adds it to the vector of reservations of the room
void Room::add_reservation(Reservation* reservation)
{
    reservations.push_back(reservation);
}

// function that checks if a candidate reservation clashes with existing reservations in a room
// takes in the date, start hour, start minute, end hour and end minute of candidate reservation
// compares the date and time with every reservations made in the room
// returns true if the candidate reservation doesn't clash with existing reservations and vice versa
bool Room::check_reservation(std::string date, int start_hour, int start_minute, int end_hour, int end_minute)
{
    // loop through each reservation
    for (int i = 0;i < reservations.size();i++)
    {
        // get existing's reservation time in integers
        int resv_start_hour = std::stoi(reservations[i]->get_start_time_hour());
        int resv_start_minute = std::stoi(reservations[i]->get_start_time_minute());
        int resv_end_hour = std::stoi(reservations[i]->get_end_time_hour());
        int resv_end_minute = std::stoi(reservations[i]->get_end_time_minute());

        // compare date, if not the same, continue to next reservation
        if (reservations[i]->get_date().compare(date) != 0)
        {  
            continue;
        }
        // case 1: input start hour between existing reservation's start and end hour
        if (start_hour > resv_start_hour && start_hour < resv_end_hour)
        {
            return 0;
        }
        // case 2: input start hour == exisiting reservation's start hour 
        else if (start_hour == resv_start_hour)
        {
            // compare input start minute with existing reservation's start minute
            if (start_minute >= resv_start_minute)
            {
                return 0;
            }
            // if input start minute is less than existing reservation's start minute
            else if (end_hour > resv_start_hour)
            {
                return 0;
            }
            // if input end hour is same as existing reservation's start hour
            else if (end_hour == start_hour && end_minute > resv_start_minute)
            {
                return 0;
            } 
        }
        // case 3: input start hour < existing reservation's start hour
        else if (start_hour < resv_start_hour)
        {
            // compare input end hour with existing reservation's start hour
            if (end_hour > resv_start_hour)
            {
                return 0;
            }
            // if input end hour = existing reservation's start hour
            else if (end_hour == resv_start_hour && end_minute > resv_start_minute)
            {
                return 0;
            }
        }
        // case 4: input start hour == existing reservation's end hour
        else if (start_hour == resv_end_hour && start_minute < resv_end_minute)
        {
            return 0;
        }
    }
    return 1;
}

// destructor
Room::~Room()
{
}

