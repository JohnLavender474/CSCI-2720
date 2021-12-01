#ifndef COMPARABLE_H
#define COMPARABLE_H

template<typename T>
class Comparable
{
	virtual bool operator>(T const &other) const = 0;
	
	virtual bool operator<(T const &other) const = 0;
	
	virtual bool operator==(T const &other) const = 0;
	
	virtual bool operator!=(T const &other) const = 0;
};

#endif