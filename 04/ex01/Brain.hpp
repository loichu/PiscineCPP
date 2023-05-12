#ifndef BRAIN_H
# define BRAIN_H
# include <string>
# include <iostream>

class Brain
{
	public:
	Brain(void);
	Brain(const Brain & brain);

	Brain & operator = (const Brain & brain);

	private:
	std::string _ideas[100];
}

#endif
