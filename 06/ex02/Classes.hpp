#ifndef CLASSES_HPP
# define CLASSES_HPP

# include <iostream>
# include <ctime>
# include <cstdlib>
# include <typeinfo>

class Base
{
    public:
    virtual ~Base();
};

class A : public Base {};

class B : public Base {};

class C : public Base {};

#endif