#ifndef ROBOTOMY_REQUEST_FORM_H
# define FORM_H

# include <cstdlib>
# include <ctime>
# include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
    public:
        RobotomyRequestForm(std::string target);

        virtual void    action() const;

    private:
        std::string _target;
};

#endif