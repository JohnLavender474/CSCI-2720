#pragma once

#include <string>

#include "Comparable.h"

class String : public Comparable<String>
{
public:
	String() = default;
	String(std::string _s);
	~String() = default;
	std::string get() const;
	void set(std::string _s);
	bool operator > (String const & other) const override;
	bool operator > (std::string const & other) const;
	bool operator < (String const & other) const override;
	bool operator < (std::string const & other) const;
	bool operator != (String const & other) const override;
	bool operator != (std::string const & other) const;
	bool operator == (String const & other) const override;
	bool operator == (std::string const & other) const;
	friend std::ostream & operator << (std::ostream & stream, const String & string);
private:
	std::string s;
};

String::String(std::string _s) :
		s(_s)
{}

std::string String::get() const
{
	return s;
}

void String::set(std::string _s)
{
	s = _s;
}

bool String::operator > (const String & other) const
{
	return s.compare(other.get()) > 0;
}

bool String::operator < (const String & other) const
{
	return s.compare(other.get()) < 0;
}

bool String::operator != (const String & other) const
{
	return s.compare(other.get()) != 0;
}

bool String::operator == (const String & other) const
{
	return s.compare(other.get()) == 0;
}

bool String::operator > (const std::string & other) const
{
	return s.compare(other) > 0;
}

bool String::operator < (const std::string & other) const
{
	return s.compare(other) < 0;
}

bool String::operator != (const std::string & other) const
{
	return s.compare(other) != 0;
}

bool String::operator == (const std::string & other) const
{
	return s.compare(other) == 0;
}

std::ostream & operator << (std::ostream & stream, const String & string)
{
	return stream << string.get();
}





