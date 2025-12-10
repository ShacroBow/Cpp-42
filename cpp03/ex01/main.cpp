#include "ScavTrap.hpp"

int main()
{
    {
    ScavTrap a("deez");
    std::cout << std::endl;
    
    ScavTrap b(a);
    std::cout << std::endl;

    ScavTrap c;
    std::cout << std::endl;

    ScavTrap d("Figma");
    std::cout << std::endl;

    c = b;
    std::cout << std::endl;
    std::cout << std::endl;

    }
    std::cout << std::endl;
    std::cout << "========================="<< std::endl;
    std::cout << std::endl;
    
    {
        ScavTrap scav("Scag");

        scav.guardGate();
        scav.attack("Killer boto");
        scav.takeDamage(30);
        scav.beRepaired(15);
        scav.attack("Diggy miner");
    }
    std::cout << std::endl;
    {
        ClapTrap *clap = new ScavTrap("Pookie");

        clap->attack("Death machine");
        clap->takeDamage(30);
        clap->beRepaired(15);
        clap->attack("Bexodiax");

        delete clap;
    }

    return 0;
}

