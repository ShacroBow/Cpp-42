#include "ClapTrap.hpp"
#include "DiamondTrap.hpp"

int main()
{
    {
        DiamondTrap a("Hybrid");
        std::cout << std::endl;
        
        DiamondTrap b(a);
        std::cout << std::endl;

        DiamondTrap c;
        std::cout << std::endl;

        DiamondTrap d("Chimera");
        std::cout << std::endl;

        c = b;
        std::cout << std::endl;
        std::cout << std::endl;

    }
    std::cout << std::endl;
    std::cout << "========================="<< std::endl;
    std::cout << std::endl;
    
    {
        DiamondTrap diamond("Nexus");

        diamond.whoAmI();
        diamond.attack("Killer boto");
        diamond.takeDamage(30);
        diamond.beRepaired(15);
        diamond.attack("Diggy miner");
    }
    std::cout << std::endl;
    {
        ClapTrap *clap = new DiamondTrap("Fusion");

        clap->attack("Death machine");
        clap->takeDamage(30);
        clap->beRepaired(15);
        clap->attack("Bexodiax");

        delete clap;
    }

    return 0;
}
