//
// Created by lhu on 23.11.23.
//

#ifndef EX00_EASYFIND_HPP
# define EX00_EASYFIND_HPP

# include <iostream>
# include <algorithm>
# include <vector>
# include <deque>
# include <list>

template <typename T> void easyfind(T & c, int i)
{
	if (std::find(c.begin(), c.end(), i) != c.end())
		std::cout << "Found" << std::endl;
	else
		std::cout << "Not Found" << std::endl;
}

#endif //EX00_EASYFIND_HPP
