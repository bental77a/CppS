#include "Weapon.hpp"

class HumanB
{
    private:
        std::string name;
        Weapon *weapon;
    public:
    HumanB(std::string HumanName);
    void setWeapon(Weapon& weaponRef);
    void attack();
};

