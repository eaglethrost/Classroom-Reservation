#ifndef RESERVATION_H
#define RESERVATION_H

#include <string>
#include "User.h"

class Reservation
{
private:
    std::string start_time_hour;
    std::string start_time_minute;
    std::string end_time_hour;
    std::string end_time_minute;
    std::string date;
    // user's motives for reserving the room
    std::string description;
    // unique identified for a reservation
    static int IDtracker;
    int id;
    User* requester;
public:
    Reservation();
    Reservation(std::string Date, std::string Start_time_hour, std::string Start_time_minute, std::string End_time_hour, std::string End_time_minute, std::string Description, User* Requester);

    int get_id();
    std::string get_start_time_hour();
    std::string get_start_time_minute();
    std::string get_end_time_hour();
    std::string get_end_time_minute();
    std::string get_date();
    std::string get_description();
    User* get_user();
    
    void print_reservation(); // for the meantime this function is for testing purposes, prints attributes of reservation
    ~Reservation();
};

#endif