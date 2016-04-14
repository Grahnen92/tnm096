#include "EightPuzzle.hpp"

#include <iostream>

EightPuzzle::EightPuzzle(){

    wrongAmount = 0;
    tmpWrongAmount[0] = 0; tmpWrongAmount[1] = 0; tmpWrongAmount[2] = 0; tmpWrongAmount[3] = 0;

    currentState[0] = 2; currentState[1] = 5; currentState[2] = -1;
    currentState[3] = 1; currentState[4] = 4; currentState[5] = 8;
    currentState[6] = 7; currentState[7] = 3; currentState[8] = 6;

    finalState[0] = 1; finalState[1] = 2; finalState[2] = 3;
    finalState[3] = 4; finalState[4] = 5; finalState[5] = 6;
    finalState[6] = 7; finalState[7] = 8; finalState[8] = -1;

    for (int i = 0; i < 9; i++){
        wrongAmount += wrongPlace(i);
    }


}

int EightPuzzle::findEmpty(){
    for(int i = 0; i < 9; i++) {
        if(currentState[i] == -1)
            return i;
    }
}

void EightPuzzle::moveEmpty() {

    while(wrongAmount != 0)
    {
        tmpWrongAmount[0] = wrongAmount; tmpWrongAmount[1] = wrongAmount; tmpWrongAmount[2] = wrongAmount; tmpWrongAmount[3] = wrongAmount;

        switch(findEmpty()) {
        case 0:
            //Move 1 ============================================
            tryMove(0, 1, 0);
            //Move 2 ============================================
            tryMove(0, 3, 1);
            //Compare Move 1 and 2 =======================================
            //Keep the move with the lowest wrongAmount
            if(tmpWrongAmount[0] <= tmpWrongAmount[1] )
                makeMove(0, 1, 0);
            else
                makeMove(0, 3, 1);
            break;
        case 1:
            //Move 1 ============================================
            tryMove(1, 0, 0);
            //Move 2 ============================================
            tryMove(1, 2, 1);
            //Move 3 ============================================
            tryMove(1, 4, 2);
            //Compare Move 1, 2, 3 =======================================
            //Keep the move with the lowest wrongAmount
            if(tmpWrongAmount[0] <= tmpWrongAmount[1] &&
               tmpWrongAmount[0] <= tmpWrongAmount[2]  )
                makeMove(1, 0, 0);
            else if (tmpWrongAmount[1] <= tmpWrongAmount[0] &&
                     tmpWrongAmount[1] <= tmpWrongAmount[2])
                makeMove(1, 2, 1);
            else
                makeMove(1, 4, 2);
            break;
        case 2:
            //Move 1 ============================================
            tryMove(2, 1, 0);
            //Move 2 ============================================
            tryMove(2, 5, 1);
            //Compare Move 1 and 2 =======================================
            //Keep the move with the lowest wrongAmount
            if(tmpWrongAmount[0] <= tmpWrongAmount[1] )
                makeMove(2, 1, 0);
            else
                makeMove(2, 5, 1);
            break;
        case 3:
             //Move 1 ============================================
            tryMove(3, 0, 0);
            //Move 2 ============================================
            tryMove(3, 4, 1);
            //Move 3 ============================================
            tryMove(3, 6, 2);
            //Compare Move 1, 2, 3 =======================================
            //Keep the move with the lowest wrongAmount
            if(tmpWrongAmount[0] <= tmpWrongAmount[1] &&
               tmpWrongAmount[0] <= tmpWrongAmount[2]  )
                makeMove(3, 0, 0);
            else if (tmpWrongAmount[1] <= tmpWrongAmount[0] &&
                     tmpWrongAmount[1] <= tmpWrongAmount[2])
                makeMove(3, 4, 1);
            else
                makeMove(3, 6, 2);

            break;
        case 4:
             //Move 1 ============================================
            tryMove(4, 1, 0);
            //Move 2 ============================================
            tryMove(4, 3, 1);
            //Move 3 ============================================
            tryMove(4, 5, 2);
            //Move 4 ============================================
            tryMove(4, 7, 3);
            //Compare Move 1, 2, 3, 4 ===========================
            //Keep the move with the lowest wrongAmount
            if(tmpWrongAmount[0] <= tmpWrongAmount[1] &&
               tmpWrongAmount[0] <= tmpWrongAmount[2] &&
               tmpWrongAmount[0] <= tmpWrongAmount[3] )
                makeMove(4, 1, 0);
            else if (tmpWrongAmount[1] <= tmpWrongAmount[0] &&
                     tmpWrongAmount[1] <= tmpWrongAmount[2] &&
                     tmpWrongAmount[1] <= tmpWrongAmount[3])
                makeMove(4, 3, 1);
            else if (tmpWrongAmount[2] <= tmpWrongAmount[0] &&
                     tmpWrongAmount[2] <= tmpWrongAmount[1] &&
                     tmpWrongAmount[2] <= tmpWrongAmount[3])
                makeMove(4, 5, 2);
            else
                makeMove(4, 7, 3);
            break;
        case 5:
           //Move 1 ============================================
            tryMove(5, 2, 0);
            //Move 2 ============================================
            tryMove(5, 4, 1);
            //Move 3 ============================================
            tryMove(5, 8, 2);
            //Compare Move 1, 2, 3 =======================================
            //Keep the move with the lowest wrongAmount
            if(tmpWrongAmount[0] <= tmpWrongAmount[1] &&
               tmpWrongAmount[0] <= tmpWrongAmount[2]  )
                makeMove(5, 2, 0);
            else if (tmpWrongAmount[1] <= tmpWrongAmount[0] &&
                     tmpWrongAmount[1] <= tmpWrongAmount[2])
                makeMove(5, 4, 1);
            else
                makeMove(5, 8, 2);
            break;
        case 6:
          //Move 1 ============================================
            tryMove(6, 3, 0);
            //Move 2 ============================================
            tryMove(6, 7, 1);
            //Compare Move 1 and 2 =======================================
            //Keep the move with the lowest wrongAmount
            if(tmpWrongAmount[0] <= tmpWrongAmount[1] )
                makeMove(6, 3, 0);
            else
                makeMove(6, 7, 1);
            break;
        case 7:
             //Move 1 ============================================
            tryMove(7, 4, 0);
            //Move 2 ============================================
            tryMove(7, 6, 1);
            //Move 3 ============================================
            tryMove(7, 8, 2);
            //Compare Move 1, 2, 3 =======================================
            //Keep the move with the lowest wrongAmount
            if(tmpWrongAmount[0] <= tmpWrongAmount[1] &&
               tmpWrongAmount[0] <= tmpWrongAmount[2]  )
                makeMove(7, 4, 0);
            else if (tmpWrongAmount[1] <= tmpWrongAmount[0] &&
                     tmpWrongAmount[1] <= tmpWrongAmount[2])
                makeMove(7, 6, 1);
            else
                makeMove(7, 8, 2);
            break;
        case 8:
            //Move 1 ============================================
            tryMove(8, 5, 0);
            //Move 2 ============================================
            tryMove(8, 7, 1);
            //Compare Move 1 and 2 =======================================
            //Keep the move with the lowest wrongAmount
            if(tmpWrongAmount[0] <= tmpWrongAmount[1] )
                makeMove(8, 5, 0);
            else
                makeMove(8, 7, 1);
            break;
        }

        print();
    }
}

bool EightPuzzle::wrongPlace(int _pos) {
    return currentState[_pos] != finalState[_pos];
}

bool EightPuzzle::rightPlace(int _pos) {
    return currentState[_pos] == finalState[_pos];
}

void EightPuzzle::tryMove(int _pos1, int _pos2, int _moveNr ){
    //check if the position being moved is already in the correct place
    tmpWrongAmount[_moveNr] += rightPlace(_pos2);

    //make the move
    currentState[_pos1] = currentState[_pos2];
    currentState[_pos2] = -1;

    //test if the moved position is now in the correct place
    tmpWrongAmount[_moveNr] -= rightPlace(_pos1);

    //Reset grid
    currentState[_pos2] = currentState[_pos1];
    currentState[_pos1] = -1;
}

void EightPuzzle::makeMove(int _pos1, int _pos2, int _moveNr ){
    //make the move
    currentState[_pos1] = currentState[_pos2];
    currentState[_pos2] = -1;

    wrongAmount = tmpWrongAmount[_moveNr];
}

void EightPuzzle::print(){
    std::cout << currentState[0] << " " << currentState[1] << " " << currentState[2] << std::endl <<
                 currentState[3] << " " << currentState[4] << " " << currentState[5] << std::endl <<
                 currentState[6] << " " << currentState[7] << " " << currentState[8] << std::endl <<
                 wrongAmount << std::endl << std::endl;

}
