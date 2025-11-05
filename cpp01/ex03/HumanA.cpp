#include "HumanA.hpp"

HumanA::HumanA(std::string str, Weapon &WeaponRef) : name(str) , weapon(WeaponRef)
{
}
void HumanA::attack()
{
    std::cout << name << " attacks with their " << weapon.getType() << std::endl;
}
