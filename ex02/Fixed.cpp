#include "Fixed.hpp"

Fixed::Fixed(): _v(0)
{
}

Fixed::~Fixed()
{

}

Fixed::Fixed (const Fixed & src)
{
	*this = src;
}

Fixed & Fixed::operator=(const Fixed &src){

	if (this->_v == src._v)
		return *this;
	setRawBits(src.getRawBits());
	return *this;
}

int Fixed::getRawBits( void ) const
{
	return _v;
}

void Fixed::setRawBits( int const raw )
{
	this->_v = raw;
}

Fixed::Fixed(const int param)
{
	this->_v = param * (1 << this->_bytes);
}

Fixed::Fixed(const float param)
{
	this->_v = roundf(param * (1 << this->_bytes));
}

float Fixed::toFloat( void ) const
{
	return (float)this->_v / (1 << this->_bytes);
}

int Fixed::toInt( void ) const
{
	return this->_v >> this->_bytes;
}

std::ostream & operator<<(std::ostream &stream, const Fixed &val)
{
	std::cout << "oper<< ";
	return stream << val.toFloat();
}

Fixed & Fixed::operator++()
{
	this->_v++;
	return *this;
}

Fixed & Fixed::operator--()
{
	this->_v--;
	return *this;
}

Fixed  Fixed::operator++(int)
{
	Fixed	old(*this);

	this->setRawBits(this->getRawBits() + 1);
	return old;
}

Fixed  Fixed::operator--(int)
{
	Fixed	old(*this);

	this->setRawBits(this->getRawBits() - 1);
	return old;
}

Fixed & Fixed::operator*(const Fixed &src)
{
	this->_v =this->toFloat() * src._v;
	return *this;
}

Fixed & Fixed::operator/(const Fixed &src)
{
	this->_v =this->toFloat() / src._v;
	return *this;
}

Fixed & Fixed::operator-(const Fixed &src)
{
	this->_v =this->toFloat() - src._v;
	return *this;
}

Fixed & Fixed::operator+(const Fixed &src)
{
	this->_v =this->toFloat() + src._v;
	return *this;
}

bool Fixed::operator!=(const Fixed &src)
{
	if (this->_v == src._v)
		return false;
	return true;
}

bool Fixed::operator==(const Fixed &src)
{
	if (this->_v == src._v)
		return true;
	return false;
}

bool Fixed::operator<(const Fixed &src)
{
	return this->_v < src._v;
}

bool Fixed::operator<=(const Fixed &src)
{
	return this->_v <= src._v;
}

bool Fixed::operator>(const Fixed &src)
{
	return this->_v > src._v;
}

bool Fixed::operator>=(const Fixed &src)
{
	return this->_v >= src._v;
}

const  Fixed & Fixed:: min(Fixed & first, Fixed & second)
{
	if (second > first)
		return first;
	return second;
}

const  Fixed & Fixed:: max(Fixed & first, Fixed & second)
{
	if (second > first)
		return second;
	return first;
}

const Fixed& Fixed::max(const Fixed & first, const Fixed & second)
{
	if (first._v < second._v)
		return second;
	return first;
}

const Fixed & Fixed::min(const Fixed & first, const Fixed & second)
{
	if (first._v > second._v)
		return second;
	return first;
}

