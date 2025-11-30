#include <iostream>

// using std::cout;
// using std::endl;
// using std::toupper;

int main(int argc, char **argv)
{
    if (argc < 2 )
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
        return (0);
    }
    int i = 1;
    while (argv[i])
    {
        for(int j = 0; argv[i][j]; j++)
            std::cout << (char )std::toupper((int )argv[i][j]);
        i++;
    }
    std::cout << std::endl;
    
    return 0;
}