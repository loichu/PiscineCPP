#ifndef BUREAUCRAT_H
# define BUREAUCRAT_H

# include <string>
# include <iostream>

class Bureaucrat
{
	public:
	Bureaucrat();
	Bureaucrat(std::string name, int grade);
	Bureaucrat(const Bureaucrat & bureaucrat);

	virtual ~Bureaucrat();

	virtual Bureaucrat & operator = (const Bureaucrat & bureaucrat);

    const std::string   getName() const;
    int                 getGrade() const;

    void    incrementGrade();
    void    decrementGrade();

    private:
    const std::string	_name;
    int	                _grade;
};

#endif