#ifndef FORM_H
# define FORM_H

# define MAX_GRADE 1
# define MIN_GRADE 150

# include <string>
# include <iostream>
# include <exception>

# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	public:
	AForm();
	AForm(std::string name, int grade_sign, int grade_exec);
	AForm(const AForm & form);

	~AForm();

	AForm & operator = (const AForm & form);

    const std::string   getName() const;
    bool                getSigned() const;
    int                 getGradeSign() const;
    int                 getGradeExec() const;

    void    beSigned(Bureaucrat & bureaucrat);

    class   GradeTooHighException   : public std::exception {};
    class   GradeTooLowException    : public std::exception {};

    private:
    const std::string	_name;
    bool                _signed;
    const int	        _grade_sign;
    const int	        _grade_exec;
};

std::ostream	&operator<<(std::ostream &out, AForm const &form);

#endif