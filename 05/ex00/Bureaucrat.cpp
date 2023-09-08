#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _grade(150)
{
	std::cout << "Bureaucrat default constructor" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade)
{
	std::cout << "Bureaucrat name, grade constructor" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat & bureaucrat)
{
	std::cout << "Bureaucrat copy constructor" << std::endl;
	*this = bureaucrat;
}

Bureaucrat::~Bureaucrat(void)
{
	std::cout << "Bureaucrat destructor" << std::endl;
}

Bureaucrat & Bureaucrat::operator = (const Bureaucrat & bureaucrat)
{
    _grade = bureaucrat.getGrade();
	return *this;
}

// ACCESSORS

const std::string   Bureaucrat::getName(void) const
{
    return _name;
}

int                 Bureaucrat::getGrade(void) const
{
    return _grade;
}

// GRADE METHODS

void    Bureaucrat::incrementGrade()
{
    _grade--;
}

void    Bureaucrat::decrementGrade()
{
    _grade++;
}