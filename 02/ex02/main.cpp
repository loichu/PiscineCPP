#include "Fixed.hpp"
#include <iostream>

int	subject_main(void)
{
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;
	return 0;
}

int main( void ) {
	Fixed a;
	Fixed b( 10 );
	Fixed const c( 42.42f );
	Fixed const d( b );
	a = Fixed( 1234.4321f );
	Fixed const e( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "d is " << d << std::endl;
	std::cout << "a is " << a.toInt() << " as integer" << std::endl;
	std::cout << "b is " << b.toInt() << " as integer" << std::endl;
	std::cout << "c is " << c.toInt() << " as integer" << std::endl;
	std::cout << "d is " << d.toInt() << " as integer" << std::endl;
	std::cout << "++b is " << ++b << std::endl;
	std::cout << "b++ is " << b++ << std::endl;
	std::cout << "then b is " << b << std::endl;
	std::cout << "--b is " << --b << std::endl;
	std::cout << "b-- is " << b-- << std::endl;
	std::cout << "then b is " << b << std::endl;
	std::cout << "b == b is " << (b == b) << std::endl;
	std::cout << "b == d is " << (b == d) << std::endl;
	std::cout << "b == a is " << (b == a) << std::endl;
	std::cout << "b >= d is " << (b >= d) << std::endl;
	std::cout << "b <= a is " << (b <= a) << std::endl;
	std::cout << "a <= b is " << (a <= b) << std::endl;
	std::cout << "b + a is " << (b + a) << std::endl;
	std::cout << "e is " << e << std::endl;
	std::cout << "c + d is " << (c + d) << std::endl;
	std::cout << "c - d is " << (c - d) << std::endl;
	std::cout << "c * d is " << (c * d) << std::endl;
	std::cout << "c / d is " << (c / d) << std::endl;
	std::cout << "max(c, d) is " << Fixed::max(c, d) << std::endl;
	std::cout << "min(c, d) is " << Fixed::min(c, d) << std::endl;
	return subject_main();
}
