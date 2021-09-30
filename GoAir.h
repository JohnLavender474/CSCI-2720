#ifndef CSCI2720_PROJECT1_GOAIR_H
#define CSCI2720_PROJECT1_GOAIR_H

#include "Flight.h"

using namespace std;

class GoAir {
public:
    GoAir();
    void addFlight(int flightno);
    void removeFlight(int flightno);
    void addPassenger(int flightno, string lastname, string firstname, int seatno);
    void removePassenger(int flightno, string lastname, string firstname, int seatno);
    void showPassenger(int flightno, string lastname, string firstname, int seatno);
    void showAllFlights();
    void showAllPassengers(int flightno);
    void showNewPassengers(int flightno, int k);
    void showFirstPassengers(int flightno, int k);
    void showAllFlightsAndPassengers();
private:
    SortedList<Flight> * flightSortedList;
    int bookingNum;
    Flight & fetchFlight(int flightno);
}; // GoAir

#endif //CSCI2720_PROJECT1_GOAIR_H
