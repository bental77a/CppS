#include "ClapTrap.hpp"


int main()
{
		ClapTrap a("gerboooz");
		ClapTrap b("dash");

		a.attack("some other robot");
		a.takeDamage(10);
		a.takeDamage(10);
		a.beRepaired(5);
		a.attack("some other other robot");
		b.beRepaired(3);
		b.attack("dash 7akmha");
		b.beRepaired(3);
	return (0);
}