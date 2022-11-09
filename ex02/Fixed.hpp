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
	Fixed & operator+(const Fixed &src);
	Fixed  operator++(int);
	Fixed  operator--(int);
	Fixed & operator++();
	Fixed & operator--();
	Fixed & operator-(const Fixed &src);
	Fixed & operator*(const Fixed &src);
	Fixed & operator/(const Fixed &src);
	bool operator!=(const Fixed &src);
	bool operator<(const Fixed &src);
	bool operator>(const Fixed &src);
	bool operator<=(const Fixed &src);
	bool operator>=(const Fixed &src);
	bool operator==(const Fixed &src);
	int getRawBits( void ) const;
	void setRawBits( int const raw );
	float toFloat( void ) const;
	int toInt( void ) const;
	const static Fixed & min(Fixed & first, Fixed & second);
	const static Fixed & max(Fixed & first, Fixed & second);
	const static Fixed & min(const Fixed & first, const Fixed & second);
	const static Fixed & max(const Fixed & first, const Fixed & second);
};

std::ostream & operator<<(std::ostream &stream, const Fixed &val);

#endif