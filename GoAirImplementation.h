#ifndef CSCI2720_PROJECT1_GOAIRIMPLEMENTATION_H
#define CSCI2720_PROJECT1_GOAIRIMPLEMENTATION_H

#include "Flight.h"
#include "Passenger.h"
#include "BookingNum.h"

using namespace std;

class BookingNumSortedList : public SortedList<Passenger> {
public:
    void insertForFirstPassengers(Passenger passenger)  {
        if (this->length == 0) {
            this->head->data = passenger;
            this->length++;
        } else {
            for (int i = 0; i < getLength(); i++) {
                if (passenger.getBookingNo() < this->get(i).getBookingNo()) {
                    this->indexedInsert(i, passenger);
                    return;
                } // if
            } // for
            this->indexedInsert(this->getLength(), passenger);
        } // if
    } // insertForFirstPassengers
    void insertForNewPassengers(Passenger passenger) {
        if (this->length == 0) {
            this->head->data = passenger;
            this->length++;
        } else {
            for (int i = 0; i < getLength(); i++) {
                if (passenger.getBookingNo() > this->get(i).getBookingNo()) {
                    this->indexedInsert(i, passenger);
                    return;
                } // if
            } // for
            this->indexedInsert(this->getLength(), passenger);
        } // if
    } // insertForNewPassengers
}; // BookingNumSortedList

class GoAirImplementation {
public:
    GoAirImplementation();
    void addFlight(int flightno);
    void removeFlight(int flightno);
    void addPassenger(int flightno, string lastname, string firstname, int seatno);
    void removePassenger(int flightno, string lastname, string firstname, int seatno);
    void showPassenger(int flightno, string lastname, string firstname, int seatno);
    void showAllFlights();
    void showAllPassengers(int flightno);
    void showNewPassengers(int flightno, int a);
    void showFirstPassengers(int flightno, int a);
    void showAllFlightsAndPassengers();
private:
    SortedList<Flight> * flightSortedList;
    SortedList<BookingNum> * removedBookingNos;
    int bookingNum;
    Flight & fetchFlight(int flightno);
}; // GoAir

#endif //CSCI2720_PROJECT1_GOAIRIMPLEMENTATION_H
