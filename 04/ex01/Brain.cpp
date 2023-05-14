#include "Brain.hpp"

std::string gen_random(const int len) {
	static const char alphanum[] =
		"0123456789"
		"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
		"abcdefghijklmnopqrstuvwxyz";
	std::string tmp_s;
	tmp_s.reserve(len);

	for (int i = 0; i < len; ++i)
		tmp_s += alphanum[std::rand() % (sizeof(alphanum) - 1)];

	return tmp_s;
}

Brain::Brain(void)
{
	std::cout << "Brain default constructor" << std::endl;
	for (int i = 0; i < NB_IDEAS; ++i)
		_ideas[i] = gen_random(12);
}

Brain::Brain(const Brain & brain)
{
	std::cout << "Brain copy constructor" << std::endl;
	*this = brain;
}
Brain::~Brain(void)
{
	std::cout << "Brain destructor" << std::endl;
}

Brain & Brain::operator = (const Brain & brain)
{
	for (int i = 0; i < NB_IDEAS; ++i)
		_ideas[i] = brain._ideas[i];
	return *this;
}

std::string *	Brain::getIdeas(void)
{
	return _ideas;
}
