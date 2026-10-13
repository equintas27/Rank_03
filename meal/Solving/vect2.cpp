#include "vect2.hpp"

vect2::vect2()
{
	this->_x = 0;
	this->_y = 0;
}
		
vect2::vectt2(int x, int y)
{
	this->_x = x;
	this->_y = y;
}
		
vect2::vect2(const vect2& src)
{
	this->_x = src._x;
	this->_y = src._y;
}

vect2::vect2&operator=(const vect2& rhs)
{
	if (this != &rhs)
	{
		this->_x = rhs._x;
		this->_y = rhs._y;
	}
	return (*this);
}

vect2::~vect2()
{}

