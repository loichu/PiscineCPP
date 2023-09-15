#include "Bureaucrat.hpp"
#include "AForm.hpp"

AForm::AForm() : _signed(false), _grade_sign(150), _grade_exec(150)
{
	std::cout << "AForm default constructor" << std::endl;
}

AForm::AForm(std::string name, int grade_sign, int grade_exec) : _name(name),
															   _signed(false),
															   _grade_sign(grade_sign),
															   _grade_exec(grade_exec)
{
	std::cout << "Creating AForm " << name
			  << ", Grade to sign: " << grade_sign
			  << ", Grade to execute: " << grade_exec
			  << std::endl;
	if (grade_sign > MIN_GRADE || grade_exec > MIN_GRADE)
	{
		throw AForm::GradeTooLowException();
	}
	if (grade_sign < MAX_GRADE || grade_exec < MAX_GRADE)
	{
		throw AForm::GradeTooHighException();
	}
}

AForm::AForm(const AForm &form) : _name(form._name), _grade_sign(form._grade_sign), _grade_exec(form._grade_exec)
{
	std::cout << "AForm copy constructor" << std::endl;
	_signed = false;
	*this = form;
}

AForm::~AForm()
{
	std::cout << "AForm destructor" << std::endl;
}

AForm &AForm::operator=(const AForm &form)
{
    _signed = form._signed;
	return *this;
}

const std::string AForm::getName() const
{
    return _name;
}

bool AForm::getSigned() const
{
    return _signed;
}

int AForm::getGradeSign() const
{
    return _grade_sign;
}

int AForm::getGradeExec() const
{
    return _grade_exec;
}

void AForm::beSigned(Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > getGradeSign())
		throw GradeTooLowException();
	_signed = true;
}

std::ostream &operator<<(std::ostream &out, AForm const &form)
{
	out << (form.getSigned() ? "\033[1;32m" : "\033[1;31m")
		<< "AForm " << form.getName()
		<< ", grade to sign: " << form.getGradeSign()
		<< ", grade to execute: " << form.getGradeExec()
		<< "\033[0m"
		<< std::endl;
	return out;
}
