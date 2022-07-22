#include <string>
#include <iostream>

#include "Room.h"
#include "Hall.h"
#include "Gym.h"

// default constructor, sets everything to 0/empty
Gym::Gym():Hall()
{
}

// constructor for gym, takes in gym name and gym code and assign them to corresponding attributes
Gym(std::string name, int code):Room(name, code)
{
    equipments[0] = "Treadmill";
    equipments[1] = "Barbel";
    equipments[2] = "Bench";
}

// prints a description of an activity happening in a gym
void Gym::do_activity()
{
    std::cout << "User is sitting on a bench using barbels and then used the treadmill" << std::endl;
}

// class destructor
Gym::~Gym()
{
}