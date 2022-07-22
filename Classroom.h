#ifndef CLASSROOM_H
#define CLASSROOM_H

#include <string>
#include "Room.h"
#include "Reservation.h"

class Classroom: public Room
{
private:
    std::string stationaries[3];
    int no_of_chairs;
    int no_of_tables;
public:
    Classroom();
    Classroom(std::string name, int code, int no_of_chairs, int no_of_tables);
    
    std::string* get_stationaries();
    int get_no_of_chairs();
    int get_no_of_tables();

    void do_activity();
    ~Classroom();
};

#endif