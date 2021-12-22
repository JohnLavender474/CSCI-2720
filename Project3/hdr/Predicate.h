#ifndef PREDICATE_HPP
#define PREDICATE_HPP

template<typename T> class Predicate {
	virtual bool test(T const &object) const = 0;
};

#endif