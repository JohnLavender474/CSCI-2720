#ifndef FUNCTION_HPP
#define FUNCTION_HPP

template<typename T>
class Function
{
public:
	Function() = default;
	
	virtual ~Function() = default;
	
	virtual void function(T t) = 0;
};

#endif