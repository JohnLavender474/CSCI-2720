#ifndef STRING_HPP
#define STRING_HPP

#include <string>

#include "Comparable.h"

class String : public Comparable<String> {
public:
	String() = default;
	
	String(std::string _s);
	
	~String() = default;
	
	std::string get() const;
	
	void set(std::string _s);
	
	bool operator>(String const &other) const override;
	
	bool operator>(std::string const &other) const;
	
	bool operator<(String const &other) const override;
	
	bool operator<(std::string const &other) const;
	
	bool operator!=(String const &other) const override;
	
	bool operator!=(std::string const &other) const;
	
	bool operator==(String const &other) const override;
	
	bool operator==(std::string const &other) const;
	
	friend std::ostream &operator<<(std::ostream &stream, const String &string);

private:
	std::string s;
};

#include "../src/String.tpp"

#endif
