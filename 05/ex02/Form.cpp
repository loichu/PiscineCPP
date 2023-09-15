#include "Bureaucrat.hpp"
#include "Form.hpp"

Form::Form() : _signed(false), _grade_sign(150), _grade_exec(150)
{
	std::cout << "Form default constructor" << std::endl;
}

Form::Form(std::string name, int grade_sign, int grade_exec) : _name(name),
															   _signed(false),
															   _grade_sign(grade_sign),
															   _grade_exec(grade_exec)
{
	std::cout << "Creating Form " << name
			  << ", Grade to sign: " << grade_sign
			  << ", Grade to execute: " << grade_exec
			  << std::endl;
	if (grade_sign > MIN_GRADE || grade_exec > MIN_GRADE)
	{
		throw Form::GradeTooLowException();
	}
	if (grade_sign < MAX_GRADE || grade_exec < MAX_GRADE)
	{
		throw Form::GradeTooHighException();
	}
}

Form::Form(const Form &form) : _name(form._name), _grade_sign(form._grade_sign), _grade_exec(form._grade_exec)
{
	std::cout << "Form copy constructor" << std::endl;
	_signed = false;
	*this = form;
}

Form::~Form()
{
	std::cout << "Form destructor" << std::endl;
}

Form &Form::operator=(const Form &form)
{
    _signed = form._signed;
	return *this;
}

const std::string Form::getName() const
{
    return _name;
}

bool Form::getSigned() const
{
    return _signed;
}

int Form::getGradeSign() const
{
    return _grade_sign;
}

int Form::getGradeExec() const
{
    return _grade_exec;
}

void Form::beSigned(Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > getGradeSign())
		throw GradeTooLowException();
	_signed = true;
}

std::ostream &operator<<(std::ostream &out, Form const &form)
{
	out << (form.getSigned() ? "\033[1;32m" : "\033[1;31m")
		<< "Form " << form.getName()
		<< ", grade to sign: " << form.getGradeSign()
		<< ", grade to execute: " << form.getGradeExec()
		<< "\033[0m"
		<< std::endl;
	return out;
}
