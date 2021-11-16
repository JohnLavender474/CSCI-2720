#include "../hdr/String.h"

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

bool String::operator>(const String &other) const
{
	return s.compare(other.get()) > 0;
}

bool String::operator<(const String &other) const
{
	return s.compare(other.get()) < 0;
}

bool String::operator!=(const String &other) const
{
	return s.compare(other.get()) != 0;
}

bool String::operator==(const String &other) const
{
	return s.compare(other.get()) == 0;
}

bool String::operator>(const std::string &other) const
{
	return s.compare(other) > 0;
}

bool String::operator<(const std::string &other) const
{
	return s.compare(other) < 0;
}

bool String::operator!=(const std::string &other) const
{
	return s.compare(other) != 0;
}

bool String::operator==(const std::string &other) const
{
	return s.compare(other) == 0;
}

std::ostream &operator<<(std::ostream &stream, const String &string)
{
	return stream << string.get();
}





