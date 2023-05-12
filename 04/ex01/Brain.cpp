#include "Brain.hpp"

Brain::Brain(void)
{
	std::cout << "Brain default constructor" << std::endl;
}

Brain & Brain::operator = (const Brain & brain)
{
	std::cout << "Brain copy constructor" << std::endl;
	_ideas = brain._ideas;
	return *this;
}
