#ifndef WRONG_ANIMAL_H
# define WRONG_ANIMAL_H

# include <string>
# include <iostream>

class WrongAnimal
{
	public:
	WrongAnimal();
	WrongAnimal(const WrongAnimal & animal);

	~WrongAnimal();

	WrongAnimal & operator = (const WrongAnimal & animal);

	std::string	getType(void) const;

	void makeSound(void) const;

	protected:
	std::string	_type;
};

#endif
