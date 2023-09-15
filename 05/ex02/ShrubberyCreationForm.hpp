#ifndef FORM_H
# define FORM_H

# include <fstream>
# include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
    public:
        ShrubberyCreationForm(std::string target);

        virtual void    action() const;

    private:
        std::string _target;
};

#endif