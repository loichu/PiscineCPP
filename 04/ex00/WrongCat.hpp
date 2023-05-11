#ifndef WRONG_CAT_H
# define WRONG_CAT_H

# include "WrongAnimal.hpp"

class WrongCat: public WrongAnimal
{
	public:
	WrongCat(void);
	WrongCat(const WrongCat & cat);

	~WrongCat(void);

	void	makeSound(void) const;
};

#endif
