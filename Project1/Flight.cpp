#include <iostream>

#include "Flight.h"
#include "Passenger.h"
#include "SortedList.h"
#include "SortedList.cpp"

using namespace std;

Flight::Flight() {
    this->flightno = -1;
    this->bookingNum = 1;
    this->passengerSortedList = new SortedList<Passenger>();
} // Flight

Flight::Flight(int flightno) {
    this->flightno = flightno;
    this->bookingNum = 1;
    this->passengerSortedList = new SortedList<Passenger>();
} // constructor

void Flight::addPassenger(Passenger passenger) {
    this->passengerSortedList->insert(passenger);
} // addPassenger

void Flight::removePassenger(string lastname, string firstname, int seatno) {
    int i = 0;
    Passenger passenger(lastname, firstname, seatno, -1);
    while (1) {
        if (passenger == this->passengerSortedList->get(i)) {
            break;
        } // if
        i++;
        if (i >= this->passengerSortedList->getLength()) {
            throw invalid_argument("No such passenger that can be removed");
        } // if
    } // while
    this->passengerSortedList->remove(i);
} // removePassenger

int Flight::passengerIndex(string lastname, string firstname, int seatno) {
    Passenger passenger(lastname, firstname, seatno, -1);
    int i = 0;
    while (1) {
        if (passenger == this->passengerSortedList->get(i)) {
            break;
        } // if
        i++;
        if (i >= this->passengerSortedList->getLength()) {
            return -1;
        } // if
    } // while
    return i;
} // getIndexOf

Passenger & Flight::getPassenger(int index) {
    return this->passengerSortedList->get(index);
} // getPassenger

void Flight::changeFlightNo(int _flightno) {
    this->flightno = _flightno;
} // changeFlightNo

int Flight::getAndIncrementBookingNum() {
    int i = bookingNum;
    this->bookingNum++;
    return i;
} // getAndIncrementBookingNum

int Flight::getLastUsedBookingNum() {
    int i = bookingNum;
    i--;
    return i;
} // getLastUsedBookingNum

bool Flight::seatIsTaken(int seatNo) const {
    int i = 0;
    while (1) {
        if (seatNo == this->passengerSortedList->get(i).getSeatNo()) {
            return true;
        } // if
        i++;
        if (i >= this->passengerSortedList->getLength()) {
            break;
        } // if
    } // while
    return false;
} // checkIfSeatIsTaken

int Flight::getFlightNo() const {
    return this->flightno;
} // getFlightNo

int Flight::getNumPassengers() const {
    return this->passengerSortedList->getLength();
} // getNumPassengers

bool Flight::operator < (Flight & other) {
    return this->flightno < other.getFlightNo();
} // <

bool Flight::operator <= (Flight & other) {
    return this->flightno <= other.getFlightNo();
} // <=

bool Flight::operator > (Flight & other) {
    return this->flightno > other.getFlightNo();
} // >

bool Flight::operator >= (Flight & other) {
    return this->flightno >= other.getFlightNo();
} // >=

bool Flight::operator == (Flight & other) {
    return this->flightno == other.getFlightNo();
} // ==

ostream & operator << (ostream & os, Flight & flight) {
    os << "Flight No: " << flight.getFlightNo() << endl;
    int i = 0;
    while (i < flight.getNumPassengers()) {
        os << " " << flight.getPassenger(i);
        i++;
    } // while
    os << endl;
    return os;
} // <<

// display
