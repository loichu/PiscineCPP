//
// Created by lhu on 06.12.23.
//

#ifndef EX02_MUTANTSTACK_HPP
# define EX02_MUTANTSTACK_HPP

# include <iostream>
# include <deque>
# include <stack>

template<
		class T,
		class Container = std::deque<T>
> class MutantStack : public std::stack<T>
{
	public:
	typedef typename Container::iterator    iterator;

	iterator    begin() { return this->c.begin(); }
	iterator    end() { return this->c.end(); }
};

#endif //EX02_MUTANTSTACK_HPP
