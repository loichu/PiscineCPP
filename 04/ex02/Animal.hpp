#ifndef ANIMAL_H
# define ANIMAL_H

# include <string>
# include <iostream>

# include "Brain.hpp"

class Animal
{
	public:
	Animal();
	Animal(const Animal & animal);

	virtual ~Animal();

	virtual Animal & operator = (const Animal & animal);

	std::string		getType(void) const;

	virtual void 	makeSound(void) const = 0;
	virtual Brain *	getBrain(void) const = 0;

	protected:
	std::string	_type;
};

#endif
