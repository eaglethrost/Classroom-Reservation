#include <vector>
#include <string>

#include "User.h"


// default constructor for user, sets attributes to empty/0
User::User()
{
    name = "?";
    id = 0;
}

// constructor for user, takes in 2 arguments to be stored in name and id
User::User(std::string Name, int ID)
{
    name = Name;
    id = ID;
}

// returns user's name
std::string User::get_name()
{
    return name;
}

// returns user's id
int User::get_id()
{
    return id;
}
/*
// returns pointer to list of reservations the user have made
Reservation* User::get_reservations()
{
    return reservationsHistory.data();
}

// adds a reservation to vector of reservartions made by user. Takes in a reservation as argument
void User::add_reservation(Reservation booking)
{
    reservationsHistory.push_back(booking);
}
*/
// destructor
User::~User()
{
}