#include "GoAirImplementation.h"
#include "Passenger.h"
#include "Flight.h"
#include "BookingNum.h"
#include "SortedList.h"
#include "SortedList.cpp"

GoAirImplementation::GoAirImplementation() {
    this->flightSortedList = new SortedList<Flight>();
    this->removedBookingNos = new SortedList<BookingNum>();
    this->bookingNum = 1;
} // constructor

void GoAirImplementation::addFlight(int flightno) {
    Flight flight(flightno);
    this->flightSortedList->insert(flight);
} // addFlight

void GoAirImplementation::removeFlight(int flightno) {
    int i = 0;
    while (1) {
        if (flightno == this->flightSortedList->get(i).getFlightNo()) {
            break;
        } // if
        i++;
        if (i >= this->flightSortedList->getLength()) {
            throw invalid_argument("invalid index");
        } // if
    } // while
    this->flightSortedList->remove(i);
} // removeFlight

void GoAirImplementation::addPassenger(int flightno, string lastname, string firstname, int seatno) {
    Flight & flight = this->fetchFlight(flightno);
    if (flight.passengerIndex(lastname, firstname, seatno) != -1) {
        throw invalid_argument("Passenger already exists on this flight");
    } // if
    Passenger passenger(lastname, firstname, seatno, flight.getAndIncrementBookingNum());
    if (!flight.seatIsTaken(seatno)) {
        flight.addPassenger(passenger);
        for (int i = 0; i < removedBookingNos->getLength(); i++) {
            if (removedBookingNos->get(i).bookingNum == passenger.getBookingNo()) {
                removedBookingNos->remove(i);
                break;
            } // if
        } // for
    } // if
} // addPassenger

void GoAirImplementation::removePassenger(int flightno, string lastname, string firstname, int seatno) {
    Flight & flight = this->fetchFlight(flightno);
    int index = flight.passengerIndex(lastname, firstname, seatno);
    if (index == -1) {
        throw invalid_argument("Passenger does not exist on this flight");
    } // if
    Passenger passenger = flight.getPassenger(index);
    BookingNum bookingNumObj;
    bookingNumObj.bookingNum = passenger.getBookingNo();
    this->removedBookingNos->insert(bookingNumObj);
    flight.removePassenger(lastname, firstname, seatno);
} // removePassenger

void GoAirImplementation::showPassenger(int flightno, string lastname, string firstname, int seatno) {
    Flight & flight = this->fetchFlight(flightno);
    int index = flight.passengerIndex(lastname, firstname, seatno);
    index != -1 ? cout << flight.getPassenger(index) : cout << "No such passenger on this flight";
} // showPassenger

void GoAirImplementation::showAllFlights() {
    cout << "Flights:" << endl;
    int i = 0;
    while (i < this->flightSortedList->getLength()) {
        cout << " Flight #" << flightSortedList->get(i).getFlightNo() << endl;
        i++;
    } // while
} // showAllFlights

void GoAirImplementation::showAllPassengers(int flightno) {
    cout << this->fetchFlight(flightno) << endl;
} // showAllPassengers

void GoAirImplementation::showNewPassengers(int flightno, int a) {
    Flight & flight = this->fetchFlight(flightno);
    BookingNumSortedList bookingNumSortedList;
    for (int i = 0; i < flight.getNumPassengers(); i++) {
        bookingNumSortedList.insertForNewPassengers(flight.getPassenger(i));
    } // for
    for (int i = 0; i < a; i++) {
        cout << bookingNumSortedList.get(i);
    } // fo
} // showNewPassengers

void GoAirImplementation::showFirstPassengers(int flightno, int a) {
    Flight & flight = this->fetchFlight(flightno);
    BookingNumSortedList bookingNumSortedList;
    for (int i = 0; i < flight.getNumPassengers(); i++) {
        bookingNumSortedList.insertForFirstPassengers(flight.getPassenger(i));
    } // for
    for (int i = 0; i < a; i++) {
        cout << bookingNumSortedList.get(i);
    } // for
} // showFirstPassengers

void GoAirImplementation::showAllFlightsAndPassengers() {
    int i = 0;
    while (i < this->flightSortedList->getLength()) {
        cout << flightSortedList->get(i);
        i++;
    } // while
} //  showAllFlightsAndPassengers

// Private
Flight & GoAirImplementation::fetchFlight(int flightno) {
    int i = 0;
    while (1) {
        if (flightno == this->flightSortedList->get(i).getFlightNo()) {
            break;
        } // if
        i++;
        if (i >= this->flightSortedList->getLength()) {
            throw invalid_argument("No flight with corresponding flightno");
        } // if
    } // while
    return this->flightSortedList->get(i);
} // fetchFlight




