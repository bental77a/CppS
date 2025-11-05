#include "HumanB.hpp"

HumanB::HumanB(std::string HumanName)
{
    name = HumanName;
    weapon = NULL;
}
void HumanB::setWeapon(Weapon& weaponRef) {weapon = &weaponRef;}
void HumanB::attack()
{
    if (weapon)
        std::cout << name << " attacks with their " << weapon->getType() << std::endl;
    else
        std::cout << name << " has no weapon" << std::endl;
}