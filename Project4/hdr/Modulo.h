#ifndef MODULO_H
#define MODULO_H

template<typename T>
class Modulo
{
public:
	virtual int operator%(T const &other) const = 0;
};

#endif