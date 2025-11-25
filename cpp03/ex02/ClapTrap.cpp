#include "ClapTrap.hpp"

ClapTrap::ClapTrap() :  _Name("") , _HitPoints(10) , _EnergyPoints(10), _AttackDamage(0)
{
    std::cout << "Default contractor it's called!" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _Name(name) , _HitPoints(10) , _EnergyPoints(10), _AttackDamage(0)
{
    std::cout << "ClapTrap " << name << " created" << std::endl;
}
ClapTrap::~ClapTrap() {std::cout << "ClapTrap " << _Name << " has been destroyed!" << std::endl;}

ClapTrap::ClapTrap(const ClapTrap& other)
{
    this->_Name = other._Name;
    this->_EnergyPoints = other._EnergyPoints;
    this->_HitPoints = other._HitPoints;
    this->_AttackDamage = other._AttackDamage;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
    if (this != &other)
    {
        this->_Name = other._Name;
        this->_EnergyPoints = other._EnergyPoints;
        this->_HitPoints = other._HitPoints;
        this->_AttackDamage = other._AttackDamage;
    }
    return (*this);
}

void ClapTrap::attack(const std::string &target)
{
    if (_HitPoints <= 0 || _EnergyPoints <= 0)
    {
        std::cout << "ClapTrap " << _Name << " cannot attack!" << std::endl;
        return;
    }
    _EnergyPoints--;
    std::cout << "ClapTrap " << _Name << " attacks " << target
              << ", causing " << _AttackDamage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    _HitPoints -= amount;

    std::cout << "ClapTrap " << _Name << " takes " << amount << " damage!" << std::endl;

    if (_HitPoints <= 0)
        std::cout << "ClapTrap " << _Name << " has died!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (_HitPoints <= 0 || _EnergyPoints <= 0) {
        std::cout << "ClapTrap " << _Name << " cannot repair itself!" << std::endl;
        return;
    }
    _HitPoints += amount;
    _EnergyPoints--;
    std::cout << "ClapTrap " << _Name << " repairs itself, recovering "
              << amount << " hit points!" << std::endl;
}
