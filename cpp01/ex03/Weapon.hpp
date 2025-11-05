#include <iostream>

class Weapon
{
    private :
        std::string type;
    public :
        Weapon(std::string str);
        const std::string &getType();
        void setType( std::string weapon_name);
};