#ifndef VECT2_HPP
#define VECT2_HPP

#include <iostream>

class vect2
{
	private:
		int _x;
		int _y;
		
	public:
		// Canonic Ortodox
		vect2();
		vect2(int x, int y);
		vect2(const vect2& src);
		vect2&operator=(const vect2& rhs);
		~vect2();
		
		// Operators
		int operator[](int index) const;
		int &operator[](int index);
		
		vect2 operator++(int);
		vect2& operator++();
		vect2 operator--(int);
		vect2& operator--();
		
		vect2& operator+=(const vect2& obj);
		vect2& operator-=(const vect2& obj);
		
		vect2& operator*=(int num);
		
		vect2 operator*(int num) const;
		vect2 operator+(const vect2& obj) const;
		vect2 operator-(const vect2& obj) const;
		
		vect2 operator-() const;
		bool operator==(const vect2& obj) const;
		bool operator!=(const vect2& obj) const;
};

vect2 operator*(int num, const vect2& obj);

std::ostream& operator<<(std::ostream& os, const vect2& obj);

#endif

