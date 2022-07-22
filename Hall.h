#ifndef HALL_H
#define HALL_H

#include <string>
#include "Room.h"
#include "Reservation.h"

class Hall: public Room
{
private:
    std::string equipments[3];
public:
    Hall();
    Hall(std::string name, int code);
    std::string* get_equipments();
    
    void do_activity();
    ~Hall();
};

#endif
