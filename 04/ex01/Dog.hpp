#ifndef DOG_H
# define DOG_H

# include "Animal.hpp"

class Dog: public Animal
{
	public:
	Dog(void);
	Dog(const Dog & dog);

	~Dog(void);

	Dog & operator = (const Dog & dog);

	void		makeSound(void) const;
	Brain *		getBrain(void) const;

	private:
	Brain * _brain;
};

#endif
