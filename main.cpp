/* CLASSROOM RESERVATION PROGRAM 
   v.1.0
   by Dimas Putra Anugerah

   SIMULATES THE PROCESS OF MAKING A RESERVATION FOR A CLASSROOM
   PROCESS:
   1. USER WILL LOGIN THEIR NAME AND ID TO THE SYSTEM
   2. USER WILL BE DIRECTED TO A MAIN MENU WHERE THEY CAN SEE THE LIST OF ROOMS
   3. AFTER A USER CHOOSES AND OPTION, THE ROOM'S NAME, CODE AND LIST OF RESERVATIONS WILL BE SHOWN. USER IS ASKED TO MAKE A RESERVATION
   4. IF YES, USER WILL BE PROMPTED TO FILL IN THEIR PREFERRED RESERVATION DATE, START HOUR, START MINUTE, END HOUR AND END MINUTE
   5. IF THE PREFERRED RESERVATION CLASHES WITH EXISTING RESERVATIONS, THE USER WILL BE REDIRECTED TO THE CLASS'S DETAILS MENU
   6. USER WILL BE REDIRECTED TO MAIN MENU WHERE THEY CAN EXIT OR REPEAT THE PROCESS
*/

#include <iostream>
#include <unistd.h>

// header files for classes
#include "User.h"
#include "Reservation.h"
#include "Room.h"
#include "Classroom.h"
#include "Hall.h"

// external functions
extern User user_login();
extern void print_main_menu();
int get_menu_input(std::string);
extern bool check_input_validity(std::string, int, int, int);
extern void print_room_details(Room*);
extern bool ask_reservation();
extern bool make_reservation(Room*, User*);
void delete_reservations(Room*);

int main(void)
{
    // 1. USER LOGIN

    User student = user_login();
    std::cout << std::endl;


    // 2. MAIN MENU
    
    // create room objects and store them in array
    Classroom** classes = new Classroom*[2];
    classes[0] = new Classroom("Class 1A", 101, 20, 20);
    classes[1] = new Classroom("Class 1B", 102, 30, 30);
    Hall** halls = new Hall*[2];
    halls[0] = new Hall("MPH1", 001);
    halls[1] = new Hall("MPH2", 002);
    
    // introduction
    std::cout << "Welcome to the room reservation system for this school " << student.get_name() << "!" << std::endl;
    sleep(1);
    print_main_menu();
    
    // get a valid user response
    std::string temp_input;
    std::cin >> temp_input;
    int input = get_menu_input(temp_input);


    // 3. SELECTED ROOM'S DETAILS AND MAKE RESERVATION OPTION

    // enclose the whole process in a while loop
    while (input != 5)
    {
        Room* selected_room;
        // do actions according to input
        switch (input)
        {   
        case 1:
            selected_room = classes[0];
            break;
        case 2:
            selected_room = classes[1];
            break;
        case 3:
            selected_room = halls[0];
            break;
        case 4:
            selected_room = halls[1];
            break;
        }
        std::cout << std::endl;
        print_room_details(selected_room);
        std::cout << std::endl;


        // 4. ASK FOR RESERVATION

        while (ask_reservation() == 1)
        {
            // 5. RESERVATION PROCESS

            if (make_reservation(selected_room, &student))
            {
                // if success, do activity of room
                std::cout << std::endl;
                std::cout << "Thank you! Your reservation is complete." << std::endl;
                sleep(1);
                selected_room->do_activity();
            }
            // if reservation fails, ask user for reservation again
            std::cout << std::endl;
            print_room_details(selected_room);
            std::cout << std::endl;
        }
        
        // 6. REDIRECTION TO MAIN MENU

        print_main_menu();
        std::cin >> temp_input;
        input = get_menu_input(temp_input);
    }

    std::cout << "Thank you! Good luck in your activities! " << std::endl;

    // delete reservations in rooms and rooms
    for (int i = 0;i < 2;i++)
    {
        delete_reservations(halls[i]);
        delete_reservations(classes[i]);
        delete halls[i];
        delete classes[i];
    }
    delete[] halls;
    delete[] classes;

    return 0;
}



/* function to obtain a valid input for menu commands
   takes in user's input
   asks user for input until they give an integer from 1-5
   returns the correct  input
*/
int get_menu_input(std::string input)
{
    while (check_input_validity(input, 1, 5, 0) == 0)
    {
        std::cout << "Please type an integer from 1-5: ";
        std::cin >> input;
    }
    int input_int = std::stoi(input);
    return input_int;
}

/* function to delete dynamic memory of reservations
   takes in room pointer as argument
*/
void delete_reservations(Room* room)
{
    // get array of reservations
    Reservation** reservations = room->get_reservations();
    int no_reservations = room->get_no_of_reservations();

    //delete reservations
    for (int i = 0; i < no_reservations; i++)
    {
        delete reservations[i];
    }
}