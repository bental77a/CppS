#include "Weapon.hpp"


Weapon::Weapon(std::string str){type = str;}
const std::string &Weapon::getType(){ return (type);}
void Weapon::setType( std::string weapon_name){type = weapon_name;}

