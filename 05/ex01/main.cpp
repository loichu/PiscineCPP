#include "Form.hpp"
#include "Form.hpp"

Form  *  fail_safe_form(std::string name, int grade_sign, int grade_exec)
{
    try {
        Form * form = new Form(name, grade_sign, grade_exec);
        return form;
    } 
    catch (Form::GradeTooHighException & e)
    {
        std::cout << "Grade is too high" << std::endl;
        return NULL;
    }
    catch (Form::GradeTooLowException & e)
    {
        std::cout << "Grade is too low" << std::endl;
        return NULL;
    }
}

void    try_sign(Form & form, Bureaucrat & bureaucrat)
{
    try
    {
        form.beSigned(bureaucrat);
        std::cout << form.getName() << " successfully signed by " << bureaucrat.getName() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cout << form.getName() << " could not be signed by " << bureaucrat.getName() << std::endl;
    }
}

void    print_form(Form * form)
{
    if (form)
        std::cout << *form << "\n" << std::endl;
    else
        std::cout << "Form is NULL\n" << std::endl;
}

int main()
{
    Form  default_form;
    print_form(&default_form);

    Form  copy_a("Copy A", 100, 100);
    print_form(&copy_a);
    Form  copy_b = copy_a;
    print_form(&copy_b);

    Form  copy_c("Copy C", 70, 70);
    print_form(&copy_c);
    copy_c = copy_a;
    print_form(&copy_c);

    Form  *  ok_form = fail_safe_form("OK", 20, 20);
    print_form(ok_form);

    Form  *  too_low_sign_form = fail_safe_form("Too Low Sign", 200, 20);
    print_form(too_low_sign_form);

    Form  *  too_low_exec_form = fail_safe_form("Too Low Exec", 20, 200);
    print_form(too_low_exec_form);

    Form  *  too_high_sign_form = fail_safe_form("Too High Sign", 0, 10);
    print_form(too_high_sign_form);

    Form  *  too_high_exec_form = fail_safe_form("Too High Exec", 10, 0);
    print_form(too_high_exec_form);

    Bureaucrat too_low("Too Low", 100);
    try_sign(*ok_form, too_low);
    print_form(ok_form);

    Bureaucrat ok("OK", 20);
    try_sign(*ok_form, ok);
    print_form(ok_form);

    try_sign(copy_a, ok);
    print_form(ok_form);

    copy_c = copy_a;
    print_form(&copy_c);

    Form a_form("A form", 30, 20);
    print_form(&a_form);

    too_low.signForm(a_form);
    print_form(&a_form);

    ok.signForm(a_form);
    print_form(&a_form);

    delete ok_form;
    delete too_low_exec_form;
    delete too_low_sign_form;
    delete too_high_exec_form;
    delete too_high_sign_form;
}
