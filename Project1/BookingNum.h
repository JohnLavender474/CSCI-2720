#ifndef CSCI2720_PROJECT1_BOOKINGNUM_H
#define CSCI2720_PROJECT1_BOOKINGNUM_H

#include <iostream>

using namespace std;

class BookingNum
{
public:
	BookingNum();
	
	int bookingNum;
	
	bool operator<(BookingNum &other);
	
	bool operator<=(BookingNum &other);
	
	bool operator>(BookingNum &other);
	
	bool operator>=(BookingNum &other);
	
	bool operator==(BookingNum &other);
	
	friend ostream &operator<<(ostream &os, BookingNum &flight);
};

#endif
