#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <stdint.h>
# include <iostream>

typedef struct Data
{
    uintptr_t   value;
}   Data;

class Serializer
{
    public:
    static uintptr_t    serialize(Data * ptr);
    static Data *       deserialize(uintptr_t raw);

    private:
    Serializer();
};

#endif
