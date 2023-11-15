//
// Created by lhu on 15.11.23.
//

#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>

template <typename T>
void iter(T *a, size_t len, void (*f)(T &))
{
	for (size_t i = 0; i < len; ++i)
		f(a[i]);
}

template < typename T >
void    print( T &i )
{
	std::cout << i << std::endl;
}

#endif
