#include <string>
#include <iostream>

#include "Room.h"
#include "Hall.h"

// default constructor for hall
Hall::Hall():Room()
{
    // fills in equipments array
    for (int i = 0; i < 3;i++)
    {
        equipments[i] = "Equipment";
    }
}

// constructor for hall, takes in hall name and hall code and assign them to corresponding attributes
Hall::Hall(std::string name, int code):Room(name, code)
{
    equipments[0] = "Microphone";
    equipments[1] = "Speaker";
    equipments[2] = "Mixer";
}

// returns pointer to vector of equipments
std::string* Hall::get_equipments()
{
    return equipments;
}

// prints a description of an activity happening in a hall
void Hall::do_activity()
{
    std::cout << "An event is taking place in the hall" << std::endl;
}

// class destructor
Hall::~Hall()
{
}