#include "Bureaucrat.hpp"

Bureaucrat  *  fail_safe_bureaucrat(std::string name, int grade)
{
    try {
        Bureaucrat * bureaucrat = new Bureaucrat(name, grade);
        return bureaucrat;
    } 
    catch (Bureaucrat::GradeTooHighException & e)
    {
        std::cout << "Grade is too high" << std::endl;
        return NULL;
    }
    catch (Bureaucrat::GradeTooLowException & e)
    {
        std::cout << "Grade is too low" << std::endl;
        return NULL;
    }
}

void    print_bureaucrat(Bureaucrat * bureaucrat)
{
    if (bureaucrat)
        std::cout << *bureaucrat << "\n" << std::endl;
    else
        std::cout << "Bureaucrat is NULL\n" << std::endl;
}

void    safe_increment(Bureaucrat & bureaucrat)
{
    try
    {
        bureaucrat.incrementGrade();
    }
    catch (Bureaucrat::GradeTooHighException & e)
    {
        std::cout << "Grade is too high" << std::endl;
    }
    
}

void    safe_decrement(Bureaucrat & bureaucrat)
{
    try
    {
        bureaucrat.decrementGrade();
    }
    catch (Bureaucrat::GradeTooLowException & e)
    {
        std::cout << "Grade is too low" << std::endl;
    }
    
}

int main()
{
    Bureaucrat  default_bureaucrat;
    print_bureaucrat(&default_bureaucrat);

    Bureaucrat  copy_a("Copy A", 100);
    print_bureaucrat(&copy_a);
    Bureaucrat  copy_b = copy_a;
    print_bureaucrat(&copy_b);

    Bureaucrat  copy_c("Copy C", 70);
    print_bureaucrat(&copy_c);
    copy_c = copy_a;
    print_bureaucrat(&copy_c);

    Bureaucrat  *  ok_bureaucrat = fail_safe_bureaucrat("OK", 20);
    print_bureaucrat(ok_bureaucrat);

    Bureaucrat  *  too_low_bureaucrat = fail_safe_bureaucrat("Too Low", 200);
    print_bureaucrat(too_low_bureaucrat);

    Bureaucrat  *  too_high_bureaucrat = fail_safe_bureaucrat("Too High", 0);
    print_bureaucrat(too_high_bureaucrat);

    Bureaucrat  max_grade("Just Above", 2);
    safe_increment(max_grade);
    print_bureaucrat(&max_grade);

    safe_increment(max_grade);
    print_bureaucrat(&max_grade);

    Bureaucrat  min_grade("Just Below", 149);
    safe_decrement(min_grade);
    print_bureaucrat(&min_grade);

    safe_decrement(min_grade);
    print_bureaucrat(&min_grade);

    delete ok_bureaucrat;
    delete too_low_bureaucrat;
    delete too_high_bureaucrat;
}