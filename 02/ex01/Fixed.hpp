class Fixed
{
	public:
	Fixed();
	Fixed(const Fixed &t);
	~Fixed();
	Fixed	&operator = (const Fixed &t);
	int		getRawBits(void) const;
	void	setRawBits(int const raw);

	private:
	int					_raw;
	static const int	_dec_bits;
};
