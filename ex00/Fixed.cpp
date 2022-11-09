#include "Fixed.hpp"

Fixed::Fixed(): _v(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed (const Fixed & src) {
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Fixed & Fixed::operator=(const Fixed &src){
	std::cout << "Copy assignment operator called" << std::endl;
	if (this->_v == src._v)
		return *this;
	setRawBits(src.getRawBits());
	return *this;
}

int Fixed::getRawBits( void ) const{
	std::cout << "getRawBits member function called" << std::endl;
	return _v;
}

void Fixed::setRawBits( int const raw ){
	this->_v = raw;
}