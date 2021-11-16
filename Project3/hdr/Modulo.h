#ifndef MODULO_HPP
#define MODULO_HPP

template<typename T>
class Modulo
{
public:
	virtual int operator%(T const &other) const = 0;
};

#endif