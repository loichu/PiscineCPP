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
	Fixed	&operator = (const Fixed &t);
	float	toFloat(void) const;
	int		toInt(void) const;
	int		getRawBits(void) const;
	void	setRawBits(int const raw);

	private:
	int					_raw;
	static const int	_dec_bits;
};

std::ostream	&operator << (std::ostream &stream, Fixed const &f);
