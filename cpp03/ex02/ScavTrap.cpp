#include "ScavTrap.hpp"


ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
    this->_EnergyPoints = 50;
    this->_HitPoints = 100;
    this->_AttackDamage = 20;
    std::cout << "ScavTrap " << name << "is created" << std::endl;
}




ScavTrap::ScavTrap() : ClapTrap()
{
    this->_EnergyPoints = 50;
    this->_HitPoints = 100;
    this->_AttackDamage = 20;
    std::cout << "ScavTrap default constractor is created" << std::endl;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap " << _Name << " has been destroyed!" << std::endl;
}
void ScavTrap::guardGate()
{
    std::cout << "ScavTrap is now in Gate keeper mode" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other)
{
	std::cout << "ScavTrap Assignation operator called" << std::endl;
	this->_Name = other._Name;
	this->_HitPoints = other._HitPoints;
	this->_AttackDamage = other._AttackDamage;
	this->_EnergyPoints = other._EnergyPoints;
	return *this;
}

ScavTrap::ScavTrap (const ScavTrap &other)
{
    this->_Name = other._Name;
    this->_EnergyPoints = other._EnergyPoints;
    this->_HitPoints = other._HitPoints;
    this->_AttackDamage = other._AttackDamage;
}

void ScavTrap::attack(const std::string& target)
{
    if (_HitPoints <= 0 || _EnergyPoints <= 0)
    {
        std::cout << "ScavTrap " << _Name << " cannot attack!" << std::endl;
        return;
    }
    _EnergyPoints--;
    std::cout << "ScavTrap " << _Name << " attacks " << target
              << ", causing " << _AttackDamage << " points of damage!" << std::endl;
}
