#include "ClapTrap.hpp"
#include "FragTrap.hpp"

int main()
{
    {
    FragTrap a("deez");
    std::cout << std::endl;
    
    FragTrap b(a);
    std::cout << std::endl;

    FragTrap c;
    std::cout << std::endl;

    FragTrap d("Figma");
    std::cout << std::endl;

    c = b;
    std::cout << std::endl;
    std::cout << std::endl;

    }
    std::cout << std::endl;
    std::cout << "========================="<< std::endl;
    std::cout << std::endl;
    
    {
        FragTrap fragy("Ferag");

        fragy.highFivesGuys();
        fragy.attack("Killer boto");
        fragy.takeDamage(30);
        fragy.beRepaired(15);
        fragy.attack("Diggy miner");
    }
    std::cout << std::endl;
    {
        ClapTrap *clap = new FragTrap("Grenade");

        clap->attack("Death machine");
        clap->takeDamage(30);
        clap->beRepaired(15);
        clap->attack("Bexodiax");

        delete clap;
    }

    return 0;
}
