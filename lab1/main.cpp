#include <iostream>
#include <vector>

#include "EightPuzzle.hpp"

struct puzzleNode{
    int puzzleState[9];
};

int main()
{
    EightPuzzle eP;
    std::vector<puzzleNode> expandedNodes;

    std::cout << "start: " << std::endl;
    eP.print();
    eP.moveEmpty();

    std::cout << "end: " << std::endl;
    eP.print();

    return 0;
}
