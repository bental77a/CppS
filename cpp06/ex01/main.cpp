#include "Data.hpp"
#include "Serializer.hpp"

int main()
{
    Data d;
    uintptr_t raw = Serializer::serialize(&d);
    Data* p = Serializer::deserialize(raw);
    
    if (p == &d)
        std::cout << "Same pointer! Serialization works.\n";
}
