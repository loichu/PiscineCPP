#ifndef BRAIN_H
# define BRAIN_H

# include <string>
# include <iostream>
# include <cstdlib>

# define NB_IDEAS 100

class Brain
{
	public:
	Brain(void);
	Brain(const Brain & brain);

	~Brain(void);

	Brain & operator = (const Brain & brain);

	std::string * getIdeas(void);

	private:
	std::string _ideas[NB_IDEAS];
};

#endif
