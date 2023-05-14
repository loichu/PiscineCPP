#ifndef DOG_H
# define DOG_H

# include "Animal.hpp"

class Dog: public Animal
{
	public:
	Dog(void);
	Dog(const Dog & dog);

	~Dog(void);

	void	makeSound(void) const;
};

#endif
