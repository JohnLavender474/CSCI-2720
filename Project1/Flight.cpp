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
}

Flight::Flight(int flightno) {
	this->flightno = flightno;
	this->bookingNum = 1;
	this->passengerSortedList = new SortedList<Passenger>();
}

void Flight::addPassenger(Passenger passenger) {
	this->passengerSortedList
			->insert(passenger);
}

void Flight::removePassenger(string lastname, string firstname, int seatno) {
	int i = 0;
	Passenger passenger(lastname, firstname, seatno, -1);
	while (1) {
		if (passenger == this->passengerSortedList
				->get(i)) {
			break;
		}
		i++;
		if (i >= this->passengerSortedList
				->getLength()) {
			throw invalid_argument("No such passenger that can be removed");
		}
	}
	this->passengerSortedList
			->remove(i);
}

int Flight::passengerIndex(string lastname, string firstname, int seatno) {
	Passenger passenger(lastname, firstname, seatno, -1);
	int i = 0;
	while (1) {
		if (passenger == this->passengerSortedList
				->get(i)) {
			break;
		}
		i++;
		if (i >= this->passengerSortedList
				->getLength()) {
			return -1;
		}
	}
	return i;
}

Passenger &Flight::getPassenger(int index) {
	return this->passengerSortedList
			->get(index);
}

void Flight::changeFlightNo(int _flightno) {
	this->flightno = _flightno;
}

int Flight::getAndIncrementBookingNum() {
	int i = bookingNum;
	this->bookingNum++;
	return i;
}

int Flight::getLastUsedBookingNum() {
	int i = bookingNum;
	i--;
	return i;
}

bool Flight::seatIsTaken(int seatNo) const {
	int i = 0;
	while (1) {
		if (seatNo == this->passengerSortedList
				->get(i)
				.getSeatNo()) {
			return true;
		}
		i++;
		if (i >= this->passengerSortedList
				->getLength()) {
			break;
		}
	}
	return false;
}

int Flight::getFlightNo() const {
	return this->flightno;
}

int Flight::getNumPassengers() const {
	return this->passengerSortedList
			->getLength();
}

bool Flight::operator<(Flight &other) {
	return this->flightno < other.getFlightNo();
}

bool Flight::operator<=(Flight &other) {
	return this->flightno <= other.getFlightNo();
}

bool Flight::operator>(Flight &other) {
	return this->flightno > other.getFlightNo();
}

bool Flight::operator>=(Flight &other) {
	return this->flightno >= other.getFlightNo();
}

bool Flight::operator==(Flight &other) {
	return this->flightno == other.getFlightNo();
}

ostream &operator<<(ostream &os, Flight &flight) {
	os << "Flight No: " << flight.getFlightNo() << endl;
	int i = 0;
	while (i < flight.getNumPassengers()) {
		os << " " << flight.getPassenger(i);
		i++;
	}
	os << endl;
	return os;
}

