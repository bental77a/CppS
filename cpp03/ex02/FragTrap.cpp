#include "FragTrap.hpp"


FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
    this->_EnergyPoints = 100;
    this->_HitPoints = 100;
    this->_AttackDamage = 30;
    std::cout << "FragTrap " << name << "is created" << std::endl;
}




FragTrap::FragTrap() : ClapTrap()
{
    this->_EnergyPoints = 100;
    this->_HitPoints = 100;
    this->_AttackDamage = 30;
    std::cout << "FragTrap default constractor is created" << std::endl;
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap " << _Name << " has been destroyed!" << std::endl;
}
void FragTrap::guardGate()
{
    std::cout << "FragTrap is now in Gate keeper mode" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &other)
{
	std::cout << "FragTrap Assignation operator called" << std::endl;
	this->_Name = other._Name;
	this->_HitPoints = other._HitPoints;
	this->_AttackDamage = other._AttackDamage;
	this->_EnergyPoints = other._EnergyPoints;
	return *this;
}

FragTrap::FragTrap (const FragTrap &other)
{
    this->_Name = other._Name;
    this->_EnergyPoints = other._EnergyPoints;
    this->_HitPoints = other._HitPoints;
    this->_AttackDamage = other._AttackDamage;
}

void FragTrap::attack(const std::string& target)
{
    if (_HitPoints <= 0 || _EnergyPoints <= 0)
    {
        std::cout << "FragTrap " << _Name << " cannot attack!" << std::endl;
        return;
    }
    _EnergyPoints--;
    std::cout << "FragTrap " << _Name << " attacks " << target
              << ", causing " << _AttackDamage << " points of damage!" << std::endl;
}

void FragTrap::highFivesGuys(void)
{
    std::cout << "High five !!!" << std::endl;
}
