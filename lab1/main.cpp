#include <iostream>
#include <vector>
#include <queue>

#include "EightPuzzle.hpp"

int main()
{
    EightPuzzle eP;

    std::cout << "start: " << std::endl;
    eP.print();
    eP.moveEmpty();

    std::cout << "end: " << std::endl;
    eP.print();

    return 0;
}
