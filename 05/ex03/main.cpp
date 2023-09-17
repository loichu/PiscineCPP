#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

void    test_and_sign_form(AForm & form, Bureaucrat & signer, Bureaucrat & wrong_executor)
{
    std::cout << form << std::endl;
    signer.signForm(form);
    std::cout << form << std::endl;
    wrong_executor.executeForm(form);
}

int main()
{
    Bureaucrat  signer("Universal Signer", 1);
    Bureaucrat  too_low("Too Low", 138);
    Bureaucrat  ok("OK", 5);

    ShrubberyCreationForm   shrubbery_form("Target A");
    test_and_sign_form(shrubbery_form, signer, too_low);
    ok.executeForm(shrubbery_form);

    std::srand(std::time(NULL));
    RobotomyRequestForm     robotomy_form("Target B");
    test_and_sign_form(robotomy_form, signer, too_low);
    ok.executeForm(robotomy_form);
    ok.executeForm(robotomy_form);
    ok.executeForm(robotomy_form);

    PresidentialPardonForm  presidential_form("Target C");
    test_and_sign_form(presidential_form, signer, too_low);
    ok.executeForm(presidential_form);
}