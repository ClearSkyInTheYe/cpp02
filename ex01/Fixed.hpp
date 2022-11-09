#ifndef FIXED_HPP
#define FIXED_HPP
#include <iostream>
#include <cmath>

class Fixed{
	static const int _bytes = 8;
	int _v;

public:
	Fixed();
	Fixed(const int param);
	Fixed(const float param);
	Fixed(const Fixed &src);
	~Fixed();

	Fixed & operator=(const Fixed &src);
	int getRawBits( void ) const;
	void setRawBits( int const raw );
	float toFloat( void ) const;
	int toInt( void ) const;
};

	std::ostream & operator<<(std::ostream &stream, const Fixed &val);

#endif