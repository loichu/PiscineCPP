#include <iostream>
#include <Array.hpp>
#include <cstdlib>

#define MAX_VAL 750
int main(int, char**)
{
	Array<int> empty;
	if (empty.size() == 0)
		std::cout << "Properly created empty array" << std::endl;

    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];

	if (numbers.size() == MAX_VAL)
		std::cout << "Array size properly set to " << MAX_VAL << std::endl;

    std::srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = std::rand();
        numbers[i] = value;
        mirror[i] = value;
    }

	for (int i = 0; i < 5; i++)
		std::cout << numbers[i] << ", " << std::flush;
	std::cout << numbers[5] << std::endl;

    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << "Exception with negative index" << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << "Exception with index equal to total size" << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }

	for (int i = 0; i < 5; i++)
		std::cout << numbers[i] << ", " << std::flush;
	std::cout << numbers[5] << std::endl;

    delete [] mirror;//
    return 0;
}
