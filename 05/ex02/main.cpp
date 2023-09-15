#include "ShrubberyCreationForm.hpp"

int main()
{
    Bureaucrat  signer("Universal Signer", 1);
    Bureaucrat  too_low("Too Low", 138);
    Bureaucrat  ok("OK", 24);

    ShrubberyCreationForm   shrubbery_form("A Target");
    std::cout << shrubbery_form << std::endl;
    signer.signForm(shrubbery_form);
    std::cout << shrubbery_form << std::endl;
    too_low.executeForm(shrubbery_form);
    ok.executeForm(shrubbery_form);
}