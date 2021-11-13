#pragma once

template<typename T>
class Predicate
{
	virtual bool test(T const &object) const = 0;
};
