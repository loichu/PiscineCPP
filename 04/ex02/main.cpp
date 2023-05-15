#include "Cat.hpp"
#include "Dog.hpp"

#define NB_ANIMALS 4

void	compare_animals(const Animal * animal1, const Animal * animal2)
{
	Brain * brain1 = animal1->getBrain();
	Brain * brain2 = animal2->getBrain();

	if (brain1 == brain2)
		std::cout << "Both have the same brain" << std::endl;
	else
		std::cout << "Brains are different" << std::endl;

	std::string * ideas1 = brain1->getIdeas();
	std::string * ideas2 = brain2->getIdeas();

	if (ideas1 == ideas2)
		std::cout << "Both have the same ideas" << std::endl;
	else
		std::cout << "Ideas are different" << std::endl;

	bool same_content = true;
	for (int i = 0; i < NB_IDEAS; ++i)
	{
		if (ideas1[i] != ideas2[i])
		{
			//std::cout << ideas1[i] << "\t" << ideas2[i] << std::endl;
			same_content = false;
		}
	}

	if (same_content)
		std::cout << "Content is identical" << std::endl;
	else
		std::cout << "Content is different" << std::endl;
}

int main()
{
	const Animal* i = new Cat();
	const Animal* j = new Dog();

	std::cout << i->getType() << std::endl;
	std::cout << j->getType() << std::endl;

	std::cout << std::endl;

	std::cout << "Compare i with j" << std::endl;
	compare_animals(i, j);

	std::cout << std::endl;

	delete i;

	std::cout << std::endl;

	Animal * animals[NB_ANIMALS];
	for (int i = 0; i < NB_ANIMALS; ++i)
	{
		if (i % 2 == 0)
			animals[i] = new Cat();
		else
			animals[i] = new Dog();
	}
	for (int i = 0; i < NB_ANIMALS; ++i)
	{
		delete animals[i];
	}

	std::cout << std::endl;

	{
		Dog basic;
		{
			Dog tmp = basic;
			std::cout << tmp.getType() << std::endl;
		}
	}

	std::cout << std::endl;

	Dog basic;
	Dog tmp = basic;

	std::cout << std::endl;

	std::cout << "Compare basic with tmp" << std::endl;
	compare_animals(&basic, &tmp);

	std::cout << std::endl;

	std::cout << "Compare basic with j" << std::endl;
	compare_animals(&basic, j);

	std::cout << std::endl;

	delete j;

	std::cout << std::endl;

	return 0;
}
