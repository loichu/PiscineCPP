#ifndef CAT_H
# define CAT_H

# include "Animal.hpp"

class Cat: public Animal
{
	public:
	Cat(void);
	Cat(const Cat & cat);

	~Cat(void);

	Cat & operator = (const Cat & cat);

	void		makeSound(void) const;
	Brain *		getBrain(void) const;

	private:
	Brain * _brain;
};

#endif
