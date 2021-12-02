#ifndef INTEGER_H
#define INTEGER_H

#include "Comparable.h"

class Integer
		: public Comparable<Integer>,
{
public:
	Integer();
	
	Integer(int _i);
	
	~Integer() = default;
	
	int get() const;
	
	void set(int _i);
	
	bool operator>(Integer const &other) const override;
	
	bool operator>(int const &other) const;
	
	bool operator<(Integer const &other) const override;
	
	bool operator<(int const &other) const;
	
	bool operator!=(Integer const &other) const override;
	
	bool operator!=(int const &other) const;
	
	bool operator==(Integer const &other) const override;
	
	bool operator==(int const &other) const;
	
	int operator%(Integer const &other) const;
	
	int operator%(int const &other) const;
	
	friend std::ostream &operator<<(std::ostream &stream, const Integer &integer);

private:
	int i;
};

#include "../src/Integer.tpp"

#endif