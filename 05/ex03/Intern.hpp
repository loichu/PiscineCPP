#ifndef INTERN_H
# define INTERN_H

# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

// typedef AForm * (*form_init)(std::string target);

class Intern 
{
    public:
    Intern();
    Intern(const Intern & intern);
    ~Intern();
    Intern & operator = (const Intern & intern);

    AForm * makeForm(std::string type, std::string target);

    private:
    AForm   *   makeShrubbery(std::string target);
    AForm   *   makeRobotomy(std::string target);
    AForm   *   makePresidential(std::string target);
};

typedef AForm * (Intern::*form_init)(std::string target);

#endif