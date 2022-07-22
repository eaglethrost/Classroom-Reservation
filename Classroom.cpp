#include <string>
#include <iostream>

#include "Room.h"
#include "Classroom.h"

// default constructor of classroom, sets every attribute to empty/0
Classroom::Classroom():Room()
{
    no_of_chairs = 0;
    no_of_tables = 0;
    // fills in equipments array
    for (int i = 0; i < 3;i++)
    {
        stationaries[i] = "Equipment";
    }
}

// constructor of classroom, takes in class name, class code, number of chairs and number of ables as parameters, and sets them to their corresponding attributes
Classroom::Classroom(std::string name, int code, int No_of_chairs, int No_of_tables):Room(name, code)
{
    no_of_chairs = No_of_chairs;
    no_of_tables = No_of_tables;
    stationaries[0] = "Marker";
    stationaries[1] = "Pen";
    stationaries[2] = "Whiteboard";
}

// returns pointer to array of stationaries in classroom
std::string* Classroom::get_stationaries()
{
    return stationaries;
}

// returns no.of chairs
int Classroom::get_no_of_chairs()
{
    return no_of_chairs;
}

// returns no.of tables
int Classroom::get_no_of_tables()
{
    return no_of_tables;
}

// prints out a statement describing the activites carried out in the classroom
void Classroom::do_activity()
{
    std::cout << "User is writing with a pen. User is drawing on the whiteboard using a marker." << std::endl;
}

// class destructor
Classroom::~Classroom()
{
}