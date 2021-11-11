#pragma once

class Integer
		: public Comparable<Integer>
{
public:
	Integer() = default;
	
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
	
	friend std::ostream &operator<<(std::ostream &stream, const Integer &integer);

private:
	int i;
};

Integer::Integer(int _i) :
		i(_i)
{}

int Integer::get() const
{
	return i;
}

void Integer::set(int _i)
{
	i = _i;
}

bool Integer::operator>(const Integer &other) const
{
	return i > other.get();
}

bool Integer::operator>(const int &other) const
{
	return i > other;
}

bool Integer::operator<(const Integer &other) const
{
	return i < other.get();
}

bool Integer::operator<(const int &other) const
{
	return i < other;
}

bool Integer::operator!=(const Integer &other) const
{
	std::cout << "!= Integer" << std::endl;
	return i != other.get();
}

bool Integer::operator==(const Integer &other) const
{
	return i == other.get();
}

bool Integer::operator!=(const int &other) const
{
	return i != other;
}

bool Integer::operator==(const int &other) const
{
	return i == other;
}

std::ostream &operator<<(std::ostream &stream, const Integer &integer)
{
	return stream << integer.get();
}







