#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardon", 25, 5)
{
    std::cout << "Creating PresidentialPardonForm, target: " << target << std::endl;
    _target = target;
}

void PresidentialPardonForm::action() const
{
    std::cout << _target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}