#include "Classes.hpp"

Base * generate(void)
{
    enum    Classes { ClassA, ClassB, ClassC };
    int     random = std::rand();
    int     clas = random % 3;
    if (clas == ClassA)
        return new A();
    if (clas == ClassB)
        return new B();
    if (clas == ClassC)
        return new C();
    return NULL;
}

void    identify(Base * p)
{
    A * a = dynamic_cast<A *>(p);
    if (a != NULL)
        std::cout << "A" << std::endl;

    B * b = dynamic_cast<B *>(p);
    if (b != NULL)
        std::cout << "B" << std::endl;

    C * c = dynamic_cast<C *>(p);
    if (c != NULL)
        std::cout << "C" << std::endl;
}

void    identify(Base & p)
{
    try {
        A a = dynamic_cast<A &>(p);
        std::cout << "A" << std::endl;
    } catch(const std::bad_cast& e) {}

    try {
        B b = dynamic_cast<B &>(p);
        std::cout << "B" << std::endl;
    } catch(const std::bad_cast& e) {}

    try {
        C c = dynamic_cast<C &>(p);
        std::cout << "C" << std::endl;
    } catch(const std::bad_cast& e) {}
}

int main(void)
{
    std::srand(std::time(NULL));
    for (int i = 0; i < 50; ++i)
    {
        Base * clas = generate();
        identify(clas);
        identify(*clas);
    }
}