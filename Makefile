all: project Tests

project: main.cpp User.o Reservation.o Room.o Classroom.o Hall.o Login.cpp MainMenu.cpp CheckInputValidity.cpp printRoomDetails.cpp AskReservation.cpp MakeReservation.cpp CheckDateInput.cpp
	g++ -std=c++11 main.cpp User.o Reservation.o Room.o Classroom.o Hall.o Login.cpp MainMenu.cpp CheckInputValidity.cpp printRoomDetails.cpp AskReservation.cpp MakeReservation.cpp CheckDateInput.cpp -o project

User.o: User.cpp User.h 
	g++ -std=c++11 -c User.cpp 

Reservation.o: Reservation.cpp Reservation.h
	g++ -std=c++11 -c Reservation.cpp

Room.o: Room.h Room.cpp
	g++ -std=c++11 -c Room.cpp

Classroom.o: Classroom.cpp Classroom.h
	g++ -std=c++11 -c Classroom.cpp

Hall.o: Hall.cpp Hall.h
	g++ -std=c++11 -c Hall.cpp 

Gym.o: Gym.cpp Gym.h
	g++ -std=c++11 -c Gym.cpp

Auditorium.o: Auditorium.cpp Auditorium.h
	g++ -std=c++11 -c Auditorium.cpp

UserTest: UserTest.cpp User.o
	g++ -std=c++11 UserTest.cpp User.o -o UserTest

ReservationTest: ReservationTest.cpp Reservation.o User.o
	g++ -std=c++11 ReservationTest.cpp Reservation.o User.o -o ReservationTest

ClassroomTest: ClassroomTest.cpp Classroom.o Room.o Reservation.o User.o
	g++ -std=c++11 ClassroomTest.cpp Classroom.o Room.o Reservation.o User.o -o ClassroomTest

HallTest: HallTest.cpp Hall.o Room.o Reservation.o User.o
	g++ -std=c++11 HallTest.cpp Hall.o Room.o Reservation.o User.o -o HallTest

GymTest: GymTest.cpp Gym.o
	g++ -std=c++11 GymTest.cpp Gym.o -o GymTest

AudiotriumTest: AuditoriumTest.cpp Auditorium.o
	g++ -std=c++11 AuditoriumTest.cpp Auditorium.o -o AuditoriumTest

ReservationUserTest: ReservationUserTest.cpp Reservation.o User.o
	g++ -std=c++11 ReservationUserTest.cpp Reservation.o User.o -o ReservationUserTest

ReservationRoomTest: ReservationRoomTest.cpp Classroom.o Hall.o Room.o Reservation.o User.o
	g++ -std=c++11 ReservationRoomTest.cpp Classroom.o Hall.o Room.o Reservation.o User.o -o ReservationRoomTest

ClashScheduleTest: ClashScheduleTest.cpp Reservation.o Classroom.o User.o Room.o
	g++ -std=c++11 ClashScheduleTest.cpp Reservation.o Classroom.o User.o Room.o -o ClashScheduleTest

CheckDateTest: CheckDateTest.cpp CheckDateInput.cpp
	g++ -std=c++11 CheckDateTest.cpp CheckDateInput.cpp -o CheckDateTest

MenuTest: MenuTest.cpp MainMenu.cpp CheckInputValidity.cpp
	g++ MenuTest.cpp MainMenu.cpp CheckInputValidity.cpp -o MenuTest

MenuLoginTest: MenuLoginTest.cpp User.o Login.cpp CheckInputValidity.cpp
	g++ -std=c++11 MenuLoginTest.cpp User.o Login.cpp CheckInputValidity.cpp -o MenuLoginTest

MenuRoomsTest: MenuRoomsTest.cpp User.o Classroom.o Hall.o Room.o Reservation.o printRoomDetails.cpp
	g++ -std=c++11 MenuRoomsTest.cpp User.o Classroom.o Hall.o Room.o Reservation.o printRoomDetails.cpp -o MenuRoomsTest

MenuReservationTest: MenuReservationTest.cpp User.o Hall.o Reservation.o Room.o printRoomDetails.cpp AskReservation.cpp CheckInputValidity.cpp CheckDateInput.cpp MakeReservation.cpp
	g++ -std=c++11 MenuReservationTest.cpp User.o Hall.o Reservation.o Room.o printRoomDetails.cpp AskReservation.cpp CheckInputValidity.cpp CheckDateInput.cpp MakeReservation.cpp -o MenuReservationTest

UnitTests: UserTest ReservationTest ClassroomTest HallTest
	bash testUser
	bash testReservation
	bash testHall
	bash testClassroom

IntegrationTests: ClashScheduleTest ReservationRoomTest ReservationUserTest MenuTest MenuLoginTest MenuReservationTest
	bash testClashSchedule
	bash testReservationRoom
	bash testReservationUser
	bash testMenu
	bash testMenuLogin
	bash testMenuRooms
	bash testMenuReservation

Tests: UnitTests IntegrationTests