#include <string>
#include <iostream>

#include "Room.h"
#include "Hall.h"
#include "Audiotrium.h"

// default constructor, sets everything to 0/empty
Auditorium::Auditorium():Hall()
{
}

// constructor for auditorium, takes in auditorium name and auditorium code and assign them to corresponding attributes
Auditorium::Auditorium(std::string name, int code):Room(name, code)
{
    equipments[0] = "Speaker";
    equipments[1] = "Microphone";
    equipments[2] = "Sound system";
}

// prints a description of an activity happening in an auditorium
void Auditorium::do_activity()
{
    std::cout << "User is using the microphone, connected to a speaker in the sound system, to hold a gathering" << std::endl;
}

// class destructor
Auditorium::~Auditorium()
{
}