#include "Intern.hpp"

Intern::Intern() {}

Intern::Intern(const Intern &intern)
{
    *this = intern;
}

Intern::~Intern() {}

Intern &Intern::operator=(const Intern &intern)
{
    (void) intern;
    return *this;
}

AForm *Intern::makeForm(std::string type, std::string target)
{
    std::string form_names[3] = { 
        "shrubbery creation", 
        "robotomy request", 
        "presidential pardon" 
    };
    AForm * (Intern::*form_calls[3])(std::string target) = { 
        &Intern::makeShrubbery,
        &Intern::makeRobotomy,
        &Intern::makePresidential,
    };
    for (long unsigned int i = 0; i < form_names->length(); ++i)
    {
        if (type == form_names[i])
            return (this->*form_calls[i])(target);
    }
    return NULL;
}

AForm * Intern::makeShrubbery(std::string target)
{
    return new ShrubberyCreationForm(target);
}

AForm * Intern::makeRobotomy(std::string target)
{
    return new RobotomyRequestForm(target);
}

AForm * Intern::makePresidential(std::string target)
{
    return new PresidentialPardonForm(target);
}
