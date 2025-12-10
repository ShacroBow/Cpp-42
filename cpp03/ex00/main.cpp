#include "ClapTrap.hpp"

int main()
{
    ClapTrap clap("Clunky");
    ClapTrap clap2("BOOORK");
    ClapTrap clap3("Mechanicus");
    std::cout << std::endl;
    
    clap.attack("Poor civilian");
    clap.takeDamage(15);
    clap.beRepaired(10);
    std::cout << std::endl;
    
    clap2.attack("stray dog");
    clap2.takeDamage(6);
    clap2.beRepaired(4);
    std::cout << std::endl;
    
    clap3.attack("Brick wall");
    clap3.takeDamage(3);
    clap3.beRepaired(4);
    clap3.attack("Brick wall");
    clap3.takeDamage(3);
    clap3.beRepaired(2);
    clap3.attack("Brick wall");
    clap3.takeDamage(3);
    clap3.beRepaired(4);
    clap3.attack("Brick wall");
    clap3.takeDamage(3);
    clap3.beRepaired(2);
    clap3.beRepaired(42);
    clap3.beRepaired(42);
    clap3.beRepaired(42);
    clap3.beRepaired(42);
    clap3.beRepaired(42);
    clap3.beRepaired(42);
    std::cout << std::endl;
    
    clap.attack("the slightest inconvience");
    clap.takeDamage(25);
    std::cout << std::endl;
    
    clap2.attack("The concept of clean code");
    clap2.takeDamage(999999);
    clap2.beRepaired(5);
    clap2.takeDamage(5);
    std::cout << std::endl;
    
    clap3.attack("Schoolyard bully");
    clap3.takeDamage(18);
    clap3.beRepaired(5);

    std::cout << std::endl;

    return 0;
}
