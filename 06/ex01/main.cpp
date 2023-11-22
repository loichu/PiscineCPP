#include "Serializer.hpp"

void    test_random_number(uintptr_t number)
{
    Data data = {number};
    uintptr_t serialized = Serializer::serialize(&data);
    Data *  deserialized = Serializer::deserialize(serialized);
    std::cout << deserialized->value << std::endl;
    std::cout << (deserialized == &data ? "Same pointers" : "Different pointers") << std::endl;
}

void    test_str_pointer(uintptr_t pointer)
{
    Data data = {pointer};
    uintptr_t serialized = Serializer::serialize(&data);
    Data *  deserialized = Serializer::deserialize(serialized);
    std::string * str = (std::string *)deserialized->value;
    std::cout << *str << std::endl;
    std::cout << (deserialized == &data ? "Same pointers" : "Different pointers") << std::endl;
}

int main()
{
    test_random_number(0);
    test_random_number(1);
    test_random_number(45);
    test_random_number(44343);
    test_random_number(-2);
    test_random_number(438957345987349587);
    test_random_number(-438957345987349587);
    test_random_number((uintptr_t)439875838484864.534665);
    
    std::string can_i_be_serialized = "Can I be serialized ?";
    test_str_pointer((uintptr_t)&can_i_be_serialized);
}
