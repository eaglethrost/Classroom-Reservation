#ifndef GYM_H
#define GYM_H

#include <string>
#include "Room.h"
#include "Hall.h"
#include "Reservation.h"

class Gym: public Hall
{
public:
    Gym();
    Gym(std::string name, int code);
    
    void do_activity();
    ~Gym();
};

#endif