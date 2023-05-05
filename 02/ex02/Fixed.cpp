#include "Fixed.hpp"

const int Fixed::_dec_bits = 8;

Fixed::Fixed() : _raw(0)
{
	//std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &t) 
{
	//std::cout << "Copy constructor called" << std::endl;
	*this = t;
} 

Fixed::Fixed(const int v)
{
	std::cout << "Int constructor called" << std::endl;
	_raw = v << _dec_bits;
}

Fixed::Fixed(const float v)
{
	std::cout << "Float constructor called" << std::endl;
	_raw = (int)roundf(v * (1 << _dec_bits));
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed &	Fixed::operator = (const Fixed &t)
{
	//std::cout << "Copy assignment operator called" << std::endl;
	_raw = t.getRawBits();
	return *this;
}

Fixed &	Fixed::operator ++ ()
{
	_raw += 1;
	return *this;
}

Fixed	Fixed::operator ++ (int)
{
	Fixed old = *this;
	operator++();
	return old;
}

Fixed &	Fixed::operator -- ()
{
	_raw -= 1;
    return *this;
}

Fixed	Fixed::operator -- (int)
{
    Fixed old = *this;
    operator--();
    return old;
}

float	Fixed::toFloat() const
{
	return (float)_raw / (1 << _dec_bits);
}

int		Fixed::toInt() const
{
	return _raw >> _dec_bits;
}

int		Fixed::getRawBits() const
{
	//std::cout << "getRawBits member function called" << std::endl;
	return _raw;
}

void	Fixed::setRawBits(int const raw)
{
	//std::cout << "setRawBits member function called" << std::endl;
	_raw = raw;
}

std::ostream &operator << (std::ostream &stream, Fixed const &f)
{
	return stream << f.toFloat();
}

Fixed	Fixed::operator + (Fixed const &f) const
{
	Fixed res;
	res.setRawBits(_raw + f.getRawBits());
	return res;
}

Fixed	Fixed::operator - (Fixed const &f) const
{
	Fixed res;
	res.setRawBits(_raw - f.getRawBits());
	return res;
}

Fixed	Fixed::operator * (Fixed const &f) const
{
	Fixed	res;
	res.setRawBits((_raw * f.getRawBits()) >> _dec_bits);
	return res;
}

Fixed	Fixed::operator / (Fixed const &f) const
{
	Fixed res;
	res.setRawBits(float(_raw << _dec_bits) / f.getRawBits());
	return res;
}

bool	Fixed::operator == (Fixed const &f) const
{
	return _raw == f.getRawBits();
}

bool	Fixed::operator != (Fixed const &f) const
{
	return _raw != f.getRawBits();
}

bool	Fixed::operator > (Fixed const &f) const
{
	return _raw > f.getRawBits();
}

bool	Fixed::operator < (Fixed const &f) const
{
	return _raw < f.getRawBits();
}

bool	Fixed::operator >= (Fixed const &f) const
{
	return _raw >= f.getRawBits();
}

bool	Fixed::operator <= (Fixed const &f) const
{
	return _raw <= f.getRawBits();
}

Fixed &	Fixed::min(Fixed& f1, Fixed& f2)
{
	if (f1 < f2)
		return f1;
	else
		return f2;
}

const Fixed &	Fixed::min(const Fixed& f1, const Fixed& f2)
{
	if (f1 < f2)
		return f1;
	else
		return f2;
}

Fixed &	Fixed::max(Fixed& f1, Fixed& f2)
{
	if (f1 > f2)
		return f1;
	else
		return f2;
}

const Fixed &	Fixed::max(const Fixed& f1, const Fixed& f2)
{
	if (f1 > f2)
		return f1;
	else
		return f2;
}
