#ifndef CSCI2720_PROJECT1_FLIGHT_H
#define CSCI2720_PROJECT1_FLIGHT_H

#include <iostream>

#include "SortedList.h"
#include "Passenger.h"

using namespace std;

class Flight {
public:
    Flight();
    Flight(int flightno);
    void addPassenger(Passenger passenger);
    void removePassenger(string lastname, string firstname, int seatno);
    int passengerIndex(string lastname, string firstname, int seatno);
    Passenger & getPassenger(int index);
    void changeFlightNo(int flightno);
    int getAndIncrementBookingNum();
    int getLastUsedBookingNum();
    bool seatIsTaken(int seatNo) const;
    int getFlightNo() const;
    int getNumPassengers() const;
    bool operator < (Flight & other);
    bool operator <= (Flight & other);
    bool operator > (Flight & other);
    bool operator >= (Flight & other);
    bool operator == (Flight & other);
    friend ostream & operator << (ostream & os, Flight & flight);
private:
    int flightno;
    int bookingNum;
    SortedList<Passenger> * passengerSortedList;
}; // Flight

#endif //CSCI2720_PROJECT1_FLIGHT_H
