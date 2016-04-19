#include "EightPuzzle.hpp"

#include <iostream>

EightPuzzle::EightPuzzle(){
    puzzleNode temp;

    temp.puzzleState[0] = 1; temp.puzzleState[1] = 2; temp.puzzleState[2] = 3;
    temp.puzzleState[3] = 4; temp.puzzleState[4] = 5; temp.puzzleState[5] = -1;
    temp.puzzleState[6] = 7; temp.puzzleState[7] = 8; temp.puzzleState[8] = 6;

    temp.g = 0;
    temp.h = 0;
    temp.f = 0;

    finalState.puzzleState[0] = 1; finalState.puzzleState[1] = 2; finalState.puzzleState[2] = 3;
    finalState.puzzleState[3] = 4; finalState.puzzleState[4] = 5; finalState.puzzleState[5] = 6;
    finalState.puzzleState[6] = 7; finalState.puzzleState[7] = 8; finalState.puzzleState[8] = -1;

    for (int i = 0; i < 9; i++)
        temp.f += wrongPlace(i, temp);

    openNodes = puzzlePQ(puzzleNodeComp(true));

    openNodes.push(temp);

}

int EightPuzzle::findEmpty(puzzleNode _node){
    for(int i = 0; i < 9; i++) {
        if(_node.puzzleState[i] == -1)
            return i;
    }
}

void EightPuzzle::moveEmpty() {

    int nrOfMoves = 0;
    //while(wrongAmount != 0)
    while(true)
    {
        expandedNodes.push_back(openNodes.top());
        openNodes.pop();

        switch(findEmpty(expandedNodes.back())) {
        case 0:
            //Move 1 ============================================
            pushMove(0, 1);
            //Move 2 ============================================
            pushMove(0, 3);
            break;
        case 1:
            //Move 1 ============================================
            pushMove(1, 0);
            //Move 2 ============================================
            pushMove(1, 2);
            //Move 3 ============================================
            pushMove(1, 4);
            break;
        case 2:
            //Move 1 ============================================
            pushMove(2, 1);
            //Move 2 ============================================
            pushMove(2, 5);

            break;
        case 3:
             //Move 1 ============================================
            pushMove(3, 0);
            //Move 2 ============================================
            pushMove(3, 4);
            //Move 3 ============================================
            pushMove(3, 6);
            break;
        case 4:
             //Move 1 ============================================
            pushMove(4, 1);
            //Move 2 ============================================
            pushMove(4, 3);
            //Move 3 ============================================
            pushMove(4, 5);
            //Move 4 ============================================
            pushMove(4, 7);
            break;
        case 5:
           //Move 1 ============================================
            pushMove(5, 2);
            //Move 2 ============================================
            pushMove(5, 4);
            //Move 3 ============================================
            pushMove(5, 8);
            break;
        case 6:
          //Move 1 ============================================
            pushMove(6, 3);
            //Move 2 ============================================
            pushMove(6, 7);
            break;
        case 7:
             //Move 1 ============================================
            pushMove(7, 4);
            //Move 2 ============================================
            pushMove(7, 6);
            //Move 3 ============================================
            pushMove(7, 8);
            break;
        case 8:
            //Move 1 ============================================
            pushMove(8, 5);
            //Move 2 ============================================
            pushMove(8, 7);
            break;
        }

        print();
        nrOfMoves++;

        if(gridEquals(openNodes.top(), finalState))
           break;
    }

    std::cout << std::endl <<"This heuristic took " <<  nrOfMoves << " moves." <<  std::endl;
}

bool EightPuzzle::wrongPlace(int _pos, puzzleNode _node) {
    return _node.puzzleState[_pos] != finalState.puzzleState[_pos];
}

bool EightPuzzle::rightPlace(int _pos, puzzleNode _node) {
    return _node.puzzleState[_pos] == finalState.puzzleState[_pos];
}

bool EightPuzzle::isExpanded(puzzleNode _node ){
    for (int i = 0; i < expandedNodes.size(); i++){
        if(gridEquals(_node, expandedNodes[i]))
           return true; //Expanded node
    }
    return false;
}

bool EightPuzzle::gridEquals(puzzleNode _node1, puzzleNode _node2){
    for (int i = 0; i < 9; i++){
        if( _node1.puzzleState[i] != _node2.puzzleState[i] )
            return false;
    }
    return true;
}

void EightPuzzle::pushMove(int _pos1, int _pos2 ){

    puzzleNode temp;

    for(int i = 0; i < 9; i++)
        temp.puzzleState[i] = expandedNodes.back().puzzleState[i];

    temp.f = expandedNodes.back().f;
    //temp.g = expandedNodes.back().g;
    //temp.h = expandedNodes.back().h;

    //check if the position being moved is already in the correct place
    temp.f += rightPlace(_pos2, temp);

    //make the move
    temp.puzzleState[_pos1] = temp.puzzleState[_pos2];
    temp.puzzleState[_pos2] = -1;

    //test if the moved position is now in the correct place
    temp.f -= rightPlace(_pos1, temp);

    if(!isExpanded(temp))
        openNodes.push(temp);
}

void EightPuzzle::makeMove(int _pos1, int _pos2){
}

void EightPuzzle::print(){
    std::cout << openNodes.top().puzzleState[0] << " " << openNodes.top().puzzleState[1] << " " << openNodes.top().puzzleState[2] << std::endl <<
                 openNodes.top().puzzleState[3] << " " << openNodes.top().puzzleState[4] << " " << openNodes.top().puzzleState[5] << std::endl <<
                 openNodes.top().puzzleState[6] << " " << openNodes.top().puzzleState[7] << " " << openNodes.top().puzzleState[8] << std::endl <<
                 openNodes.top().f << std::endl << std::endl;

}
