#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

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

    return 0;
}
