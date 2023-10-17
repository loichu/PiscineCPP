#ifndef BUREAUCRAT_H
# define BUREAUCRAT_H

# define MAX_GRADE 1
# define MIN_GRADE 150

# include <string>
# include <iostream>
# include <exception>

class Bureaucrat
{
	public:
	Bureaucrat();
	Bureaucrat(std::string name, int grade);
	Bureaucrat(const Bureaucrat & bureaucrat);

	~Bureaucrat();

	Bureaucrat & operator = (const Bureaucrat & bureaucrat);

    const std::string   getName() const;
    int                 getGrade() const;

    void    incrementGrade();
    void    decrementGrade();

    class   GradeTooHighException   : public std::exception {};
    class   GradeTooLowException    : public std::exception {};

    private:
    const std::string	_name;
    int	                _grade;
};

std::ostream	&operator<<(std::ostream &out, Bureaucrat const &bureaucrat);

#endif
