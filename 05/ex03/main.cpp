#include "Intern.hpp"

int main()
{
    Intern intern = Intern();

    AForm * shrubbery = intern.makeForm("shrubbery creation", "Target A");
    std::cout << *shrubbery << std::endl;
    AForm * robotomy = intern.makeForm("robotomy request", "Target B");
    std::cout << *robotomy << std::endl;
    AForm * presidential = intern.makeForm("presidential pardon", "Target C");
    std::cout << *presidential << std::endl;
    AForm * wrong = intern.makeForm("wrong", "Target C");
    std::cout << wrong << std::endl;
    delete shrubbery;
    delete robotomy;
    delete presidential;
}