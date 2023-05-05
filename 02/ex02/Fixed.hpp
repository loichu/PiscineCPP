#include <iostream>
#include <cmath>

class Fixed
{
	public:
	Fixed();
	Fixed(const Fixed &t);
	Fixed(const int v);
	Fixed(const float v);

	~Fixed();

	Fixed &	operator = (const Fixed &t);

	Fixed &	operator ++ (void);
	Fixed	operator ++ (int);
	Fixed &	operator -- (void);
	Fixed	operator -- (int);

	Fixed	operator + (Fixed const &f) const;
	Fixed	operator - (Fixed const &f) const;
	Fixed	operator * (Fixed const &f) const;
	Fixed	operator / (Fixed const &f) const;

	bool	operator == (Fixed const &f) const;
	bool	operator != (Fixed const &f) const;
	bool	operator >= (Fixed const &f) const;
	bool	operator <= (Fixed const &f) const;
	bool	operator > (Fixed const &f) const;
	bool	operator < (Fixed const &f) const;

	float	toFloat(void) const;
	int		toInt(void) const;
	int		getRawBits(void) const;
	void	setRawBits(int const raw);

	static Fixed& min(Fixed& f1, Fixed& f2);
	static const Fixed& min(const Fixed& f1, const Fixed& f2);
	static Fixed& max(Fixed& f1, Fixed& f2);
	static const Fixed& max(const Fixed& f1, const Fixed& f2);

	private:
	int					_raw;
	static const int	_dec_bits;
};

std::ostream	&operator << (std::ostream &stream, Fixed const &f);
