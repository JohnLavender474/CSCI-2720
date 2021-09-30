#include "GoAir.h"
#include "Passenger.h"
#include "Flight.h"
#include "SortedList.h"
#include "SortedList.cpp"

GoAir::GoAir() {
    this->flightSortedList = new SortedList<Flight>();
    this->bookingNum = 1;
} // constructor

void GoAir::addFlight(int flightno) {
    Flight flight(flightno);
    this->flightSortedList->insert(flight);
} // addFlight

void GoAir::removeFlight(int flightno) {
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

void GoAir::addPassenger(int flightno, string lastname, string firstname, int seatno) {
    Flight & flight = this->fetchFlight(flightno);
    if (flight.passengerIndex(lastname, firstname, seatno) != -1) {
        throw invalid_argument("Passenger already exists on this flight");
    } // if
    if (!flight.seatIsTaken(seatno)) {
        Passenger passenger(lastname, firstname, seatno, flight.getAndIncrementBookingNum());
        flight.addPassenger(passenger);
    } // if
} // addPassenger

void GoAir::removePassenger(int flightno, string lastname, string firstname, int seatno) {
    Flight & flight = this->fetchFlight(flightno);
    if (flight.passengerIndex(lastname, firstname, seatno) == -1) {
        throw invalid_argument("Passenger does not exist on this flight");
    } // if
    flight.removePassenger(lastname, firstname, seatno);
} // removePassenger

void GoAir::showPassenger(int flightno, string lastname, string firstname, int seatno) {
    Flight & flight = this->fetchFlight(flightno);
    int index = flight.passengerIndex(lastname, firstname, seatno);
    index != -1 ? cout << flight.getPassenger(index) : cout << "No such passenger on this flight";
} // showPassenger

void GoAir::showAllFlights() {
    cout << "Flights:" << endl;
    int i = 0;
    while (i < this->flightSortedList->getLength()) {
        cout << " Flight #" << flightSortedList->get(i).getFlightNo() << endl;
        i++;
    } // while
} // showAllFlights

void GoAir::showAllPassengers(int flightno) {
    cout << this->fetchFlight(flightno) << endl;
} // showAllPassengers

void GoAir::showNewPassengers(int flightno, int k) {

} // showNewPassengers

void GoAir::showFirstPassengers(int flightno, int k) {

} // showFirstPassengers

void GoAir::showAllFlightsAndPassengers() {
    int i = 0;
    while (i < this->flightSortedList->getLength()) {
        cout << flightSortedList->get(i);
        i++;
    } // while
} //  showAllFlightsAndPassengers

// Private
Flight & GoAir::fetchFlight(int flightno) {
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




