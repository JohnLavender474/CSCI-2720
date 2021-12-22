#ifndef COMPARABLE_HPP
#define COMPARABLE_HPP

template<typename K> class Comparable {
public:
	virtual bool operator>(K const &other) const = 0;
	
	virtual bool operator<(K const &other) const = 0;
	
	virtual bool operator!=(K const &other) const = 0;
	
	virtual bool operator==(K const &other) const = 0;
};

#endif