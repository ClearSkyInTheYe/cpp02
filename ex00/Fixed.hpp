#ifndef FIXED_HPP
#define FIXED_HPP
#include <iostream>

class Fixed{
	static const int _bytes = 8;
	int _v;

public:
	Fixed();
	Fixed(const Fixed &src);
	~Fixed();

	Fixed & operator=(const Fixed &src);
	int getRawBits( void ) const;
	void setRawBits( int const raw );
};

#endif