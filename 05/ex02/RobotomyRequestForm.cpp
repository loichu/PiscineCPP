#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequest", 72, 45)
{
    std::cout << "Creating RobotomyRequestForm, target: " << target << std::endl;
    _target = target;
}

void RobotomyRequestForm::action() const
{
    if (std::rand() % 2)
        std::cout << _target << " has been robotomized" << std::endl;
    else
        std::cout << "Robotomy failed" << std::endl;
}