#ifndef ROOM_H
#define ROOM_H

#include <string>
#include <vector>

#include "Reservation.h"

class Room
{
private:
    std::string name;
    int roomCode;
protected:
    std::vector<Reservation*> reservations;  // vector of reservations made in a particular room
public:
    Room();
    Room(std::string Name, int RoomCode);

    std::string get_name();
    int get_roomCode();
    Reservation** get_reservations();
    int get_no_of_reservations();

    void add_reservation(Reservation* reservation); 
    bool check_reservation(std::string date, int start_hour, int start_minute, int end_hour, int end_minute); // checks to see if a particular reservation clashes with exsitsing reservations
    virtual void do_activity() = 0; // prints out a statement explaining an activity carried out, subject to room type
    virtual ~Room();
};

#endif