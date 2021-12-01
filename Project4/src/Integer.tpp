#include "../hdr/Integer.h"

#include <iostream>

Integer::Integer(int _i) :
i(_i)
{}

int Integer::get() const
{
	return i;
}

void Integer::set(int _i)
{
	i = _i;
}

bool Integer::operator>(const Integer &other) const
{
	return i > other.get();
}

bool Integer::operator>(const int &other) const
{
	return i > other;
}

bool Integer::operator<(const Integer &other) const
{
	return i < other.get();
}

bool Integer::operator<(const int &other) const
{
	return i < other;
}

bool Integer::operator!=(const Integer &other) const
{
	std::cout << "!= Integer" << std::endl;
	return i != other.get();
}

bool Integer::operator==(const Integer &other) const
{
	return i == other.get();
}

bool Integer::operator!=(const int &other) const
{
	return i != other;
}

bool Integer::operator==(const int &other) const
{
	return i == other;
}

std::ostream &operator<<(std::ostream &stream, const Integer &integer)
{
	return stream << integer.get();
}

int Integer::operator%(const Integer &other) const
{
	return i % other.get();
}

int Integer::operator%(const int &other) const
{
	return i % other;
}







