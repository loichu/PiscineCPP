#include <iostream>
#include "Fixed.hpp"

const int Fixed::_dec_bits = 8;

Fixed::Fixed() : _raw(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &t) 
{
	std::cout << "Copy constructor called" << std::endl;
	*this = t;
} 

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed &	Fixed::operator = (const Fixed &t)
{
	std::cout << "Copy assignment operator called" << std::endl;
	_raw = t.getRawBits();
	return *this;
}

int		Fixed::getRawBits() const
{
	std::cout << "getRawBits member function called" << std::endl;
	return _raw;
}

void	Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	_raw = raw;
}
