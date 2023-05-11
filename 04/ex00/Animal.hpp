#ifndef ANIMAL_H
# define ANIMAL_H

# include <string>
# include <iostream>

class Animal
{
	public:
	Animal();
	Animal(const Animal & animal);

	~Animal();

	Animal & operator = (const Animal & animal);

	std::string	getType(void) const;

	void	makeSound(void) const;

	protected:
	std::string	_type;
};

#endif
