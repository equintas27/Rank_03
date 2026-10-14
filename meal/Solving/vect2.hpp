#ifndef VECT2_HPP
#define VECT2_HPP


class vect2
{
	private:
		int _x;
		int _y;
		
	public:
		// Canonic Ortodox
		vect2();
		vectt2(int x, int y);
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
		
		int &operator-() const;
}









#endif

