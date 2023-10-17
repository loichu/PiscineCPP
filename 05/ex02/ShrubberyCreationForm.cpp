#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreation", 145, 137)
{
    std::cout << "Creating ShrubberyCreationForm, target: " << target << std::endl;
    _target = target;
}

void ShrubberyCreationForm::action() const
{
    std::ofstream   shrubbery;

    shrubbery.open((_target + "_shrubbery").c_str());
    shrubbery << "ASCII trees\n";
    shrubbery.close();
}
