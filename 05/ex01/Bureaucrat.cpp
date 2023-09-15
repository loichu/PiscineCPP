#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _grade(MIN_GRADE)
{
	std::cout << "Bureaucrat default constructor" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade)
{
	std::cout << "Creating Bureaucrat " << name
			  << ", Grade: " << grade
			  << std::endl;
	if (grade > MIN_GRADE)
	{
		throw Bureaucrat::GradeTooLowException();
	}
	if (grade < MAX_GRADE)
	{
		throw Bureaucrat::GradeTooHighException();
	}
}

Bureaucrat::Bureaucrat(const Bureaucrat & bureaucrat) : _name(bureaucrat._name)
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
    _grade = bureaucrat._grade;
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
	if (_grade - 1 < MAX_GRADE)
	{
		throw Bureaucrat::GradeTooHighException();
	}
    _grade--;
}

void    Bureaucrat::decrementGrade()
{
	if (_grade + 1 > MIN_GRADE)
	{
		throw Bureaucrat::GradeTooLowException();
	}
    _grade++;
}

std::ostream	&operator<<(std::ostream &out, Bureaucrat const &bureaucrat)
{
	out << "Bureaucrat " << bureaucrat.getName() << ", grade " << bureaucrat.getGrade();
	return (out);
}


void Bureaucrat::signForm(Form &form)
{
	std::cout << getName();
	try
	{
		form.beSigned(*this);
		std::cout << " signed " << form.getName() << std::endl;
	}
	catch (Form::GradeTooLowException & e)
	{
		std::cout << " couldn't sign " << form.getName()
				  << " because " << getName() << "'s grade is too low"
				  << " (" << getGrade() << " but " << form.getGradeSign() << " required)"
				  << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << getName() << " couldn't sign " << form.getName()
				  << " because something unexpected happend"
				  << std::endl;
	}
}