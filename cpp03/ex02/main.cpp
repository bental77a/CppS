#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
    ClapTrap ct("Alpha");
    ClapTrap ct_copy = ct;

    ct.attack("Target");
    ct.takeDamage(5);
    ct.beRepaired(3);

    ScavTrap st("Bravo");
    st.attack("Alpha");
    st.guardGate();
    st.takeDamage(50);
    st.beRepaired(10);

    ScavTrap st2;
    st2 = st;
    FragTrap st3("czar");
    st3.attack("Alpha");
    st3.guardGate();
    st3.takeDamage(50);
    st3.beRepaired(10);
    st3.highFivesGuys();
    return 0;
}
