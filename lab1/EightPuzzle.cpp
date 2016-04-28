#include "EightPuzzle.hpp"

#include <iostream>
#include <stdlib.h>

EightPuzzle::EightPuzzle(){
    puzzleNode temp;

    // Book problem, 20 moves
    //temp.puzzleState[0] = 2; temp.puzzleState[1] = 5; temp.puzzleState[2] = 0;
    //temp.puzzleState[3] = 1; temp.puzzleState[4] = 4; temp.puzzleState[5] = 8;
    //temp.puzzleState[6] = 7; temp.puzzleState[7] = 3; temp.puzzleState[8] = 6;

    // Should take 31 moves, takes 180.6 seconds with manhattan when using a vector
    temp.puzzleState[0] = 8; temp.puzzleState[1] = 6; temp.puzzleState[2] = 7;
    temp.puzzleState[3] = 2; temp.puzzleState[4] = 5; temp.puzzleState[5] = 4;
    temp.puzzleState[6] = 3; temp.puzzleState[7] = 0; temp.puzzleState[8] = 1;

    // Run unsolvable
    //temp.puzzleState[0] = 8; temp.puzzleState[1] = 1; temp.puzzleState[2] = 2;
    //temp.puzzleState[3] = 0; temp.puzzleState[4] = 4; temp.puzzleState[5] = 3;
    //temp.puzzleState[6] = 7; temp.puzzleState[7] = 6; temp.puzzleState[8] = 5;

    temp.g = 0;
    //temp.h = 0;
    //temp.f = 0;

    finalState.puzzleState[0] = 1; finalState.puzzleState[1] = 2; finalState.puzzleState[2] = 3;
    finalState.puzzleState[3] = 4; finalState.puzzleState[4] = 5; finalState.puzzleState[5] = 6;
    finalState.puzzleState[6] = 7; finalState.puzzleState[7] = 8; finalState.puzzleState[8] = 0;

    //for (int i = 0; i < 9; i++)
    //    temp.f += wrongPlace(i, temp);

    //temp.h = temp.f = wrongSum(temp);
    temp.h = temp.f = manhattanSum(temp);

    openNodes = puzzlePQ(puzzleNodeComp(true));

    openNodes.push(temp);
}

int EightPuzzle::findEmpty(puzzleNode _node){
    for(int i = 0; i < 9; i++) {
        if(_node.puzzleState[i] == 0)
            return i;
    }
}

void EightPuzzle::moveEmpty() {

    int nrOfMoves = 0;
    std::string tmpString;
    //while(wrongAmount != 0)
    while(true)
    {
        tmpString = createKey(openNodes.top());
        expandedNodes.insert({tmpString, openNodes.top()});
        lastExpanded = &expandedNodes.at(tmpString);
        openNodes.pop();

        switch(findEmpty(*lastExpanded)) {
        case 0:
            //Move 1 ============================================
            pushMove(0, 1, 'r');
            //Move 2 ============================================
            pushMove(0, 3, 'd');
            break;
        case 1:
            //Move 1 ============================================
            pushMove(1, 0, 'l');
            //Move 2 ============================================
            pushMove(1, 2, 'r');
            //Move 3 ============================================
            pushMove(1, 4, 'd');
            break;
        case 2:
            //Move 1 ============================================
            pushMove(2, 1, 'l');
            //Move 2 ============================================
            pushMove(2, 5, 'd');

            break;
        case 3:
             //Move 1 ============================================
            pushMove(3, 0, 'u');
            //Move 2 ============================================
            pushMove(3, 4, 'r');
            //Move 3 ============================================
            pushMove(3, 6, 'd');
            break;
        case 4:
             //Move 1 ============================================
            pushMove(4, 1, 'u');
            //Move 2 ============================================
            pushMove(4, 3, 'l');
            //Move 3 ============================================
            pushMove(4, 5, 'r');
            //Move 4 ============================================
            pushMove(4, 7, 'd');
            break;
        case 5:
           //Move 1 ============================================
            pushMove(5, 2, 'u');
            //Move 2 ============================================
            pushMove(5, 4, 'l');
            //Move 3 ============================================
            pushMove(5, 8, 'd');
            break;
        case 6:
          //Move 1 ============================================
            pushMove(6, 3, 'u');
            //Move 2 ============================================
            pushMove(6, 7, 'r');
            break;
        case 7:
             //Move 1 ============================================
            pushMove(7, 4, 'u');
            //Move 2 ============================================
            pushMove(7, 6, 'l');
            //Move 3 ============================================
            pushMove(7, 8, 'r');
            break;
        case 8:
            //Move 1 ============================================
            pushMove(8, 5, 'u');
            //Move 2 ============================================
            pushMove(8, 7, 'l');
            break;
        }

        //print();
        nrOfMoves++;

        if(gridEquals(openNodes.top(), finalState) || openNodes.empty())
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
    if(expandedNodes.find(createKey(_node)) == expandedNodes.end())
        return false;
    else
        return true;
}

bool EightPuzzle::gridEquals(puzzleNode _node1, puzzleNode _node2){
    for (int i = 0; i < 9; i++)
        if( _node1.puzzleState[i] != _node2.puzzleState[i] )
            return false;

    return true;
}

int EightPuzzle::wrongSum(puzzleNode _node){
    int wSum = 0;

    for (int i = 0; i < 9; i++){
        wSum += _node.puzzleState[i] != finalState.puzzleState[i];
    }

    return wSum;
}

int EightPuzzle::manhattanSum(puzzleNode _node){
    int mSum = 0;
    for(int i = 0; i < 9; i++)
        for(int j = 0; j < 9; j++)
            if(_node.puzzleState[i] ==  finalState.puzzleState[j])
                mSum += manhattanDist(i, j);

//    int current, finalzzz;
//    for (int i = 0; i < 9; i++){
//        for (int j = 0; j < 9; j++){
//            if(i == _node.puzzleState[j])
//                current = j;
//            if(i == finalState.puzzleState[j])
//                finalzzz = j;
//        }
//
//        //std::cout << "current: " << current << "final: " << finalzzz << std::endl;
//        mSum +=  manhattanDist(current, finalzzz);
//    }



    //std::cout << "mSum: " << mSum << std::endl;
    return mSum;
}

int EightPuzzle::manhattanDist(int _pos1, int _pos2){
    int x1 = _pos1%3; int y1 = _pos1/3;

    int x2 = _pos2%3; int y2 = _pos2/3;
    //std::cout << " x1: " <<  x1<< " x2: " << x2<< " y1: " << y1 << " y2: "<< y2 << std::endl;

    return abs(x1-x2) + abs(y1-y2);
}

void EightPuzzle::pushMove(int _pos1, int _pos2, char moved ){

    puzzleNode temp;

    // Push which moves was made
    //temp.moves = expandedNodes.back().moves;
    //temp.moves.push_back(moved);

    for(int i = 0; i < 9; i++)
        temp.puzzleState[i] = lastExpanded->puzzleState[i];

    //temp.f = expandedNodes.back().f;
    temp.g = lastExpanded->g + 1;
    temp.h = manhattanSum(temp);
    //temp.h = wrongSum(temp);

    //make the move
    temp.puzzleState[_pos1] = temp.puzzleState[_pos2];
    temp.puzzleState[_pos2] = 0;

    temp.f = temp.h + temp.g;

    if(!isExpanded(temp))
        openNodes.push(temp);
}

void EightPuzzle::makeMove(int _pos1, int _pos2){
}

void EightPuzzle::print(){
    std::cout << openNodes.top().puzzleState[0] << " " << openNodes.top().puzzleState[1] << " " << openNodes.top().puzzleState[2] << std::endl <<
                 openNodes.top().puzzleState[3] << " " << openNodes.top().puzzleState[4] << " " << openNodes.top().puzzleState[5] << std::endl <<
                 openNodes.top().puzzleState[6] << " " << openNodes.top().puzzleState[7] << " " << openNodes.top().puzzleState[8] << std::endl <<
                 "f: " << openNodes.top().f << std::endl << "g: " << openNodes.top().g << std::endl <<
                 "Moves made: " << openNodes.top().g << std::endl;

}

std::string EightPuzzle::createKey(puzzleNode _node){

    std::string tmpString = "";
    for (int i = 0; i < 9; i++){
        tmpString += _node.puzzleState[i];
    }
    return tmpString;
}
