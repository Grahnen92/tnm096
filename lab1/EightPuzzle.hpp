

class EightPuzzle
{
public:

    EightPuzzle();
    //~EightPuzzle();

    void moveEmpty();

    void print();

private:

    int findEmpty();

    bool wrongPlace(int _pos);
    bool rightPlace(int _pos);

    void tryMove(int _pos1, int _pos2, int _moveNr);
    void makeMove(int _pos1, int _pos2, int _moveNr);

    int currentState[9];
   //int tmpState[9];
    int finalState[9];

    int wrongAmount;
    int tmpWrongAmount[4];
};
