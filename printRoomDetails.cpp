/* Function to print room details (name, code and reservations) when chosen in main menu
   Takes in a room pointer
   Prints room details
*/
#include <iostream>
#include "Room.h"
#include "Reservation.h"

void print_room_details(Room* room)
{
    // print room details
    std::cout << room->get_name() << std::endl;
    std::cout << "Room code: " << room->get_roomCode() << std::endl;
    std::cout << "Reservations: " << std::endl;
    // print reservations
    Reservation** reservations = room->get_reservations();
    for (int i = 0;i < room->get_no_of_reservations(); i++)
    {
        std::cout << i + 1 << ") ";
        reservations[i]->print_reservation();
    } 
}