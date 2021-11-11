#pragma once

template<typename T>
class Function
{
public:
	Function() = default;
	
	virtual ~Function() = default;
	
	virtual void function(T t) = 0;
};