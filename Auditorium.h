#ifndef AUDITORIUM_H
#define AUDIOTRIUM_H

#include <string>
#include "Room.h"
#include "Hall.h"
#include "Reservation.h"

class Auditorium: public Hall
{
public:
    Auditorium();
    Auditorium(std::string name, int code);

    void do_activity();
    ~Auditorium();
};

#endif


