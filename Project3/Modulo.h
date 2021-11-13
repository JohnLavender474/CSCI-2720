#pragma once

template<typename T>
class Modulo
{
public:
	virtual int operator%(T const &other) const = 0;
};