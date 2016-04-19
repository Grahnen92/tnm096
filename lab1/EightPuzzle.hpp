#include <vector>
#include <queue>

struct puzzleNode{
    int puzzleState[9];
    int g;
    int h;
    //maybe g + h in one variable
    int f;
};

class puzzleNodeComp {
    bool reverse;
public:
    puzzleNodeComp(const bool& revparam=false){
        reverse=revparam;
    }

    bool operator() (const puzzleNode& lhs, const puzzleNode& rhs) const{
        if (reverse)
            return (lhs.f > rhs.f);
        else
            return (lhs.f < rhs.f);
    }
};

class EightPuzzle
{
public:

    EightPuzzle();
    //~EightPuzzle();

    void moveEmpty();

    void print();

private:

    int findEmpty(puzzleNode _node);

    bool wrongPlace(int _pos, puzzleNode _node);
    bool rightPlace(int _pos, puzzleNode _node);
    int wrongSum(puzzleNode _node);

    int manhattanSum(puzzleNode _node);
    int manhattanDist(int _pos1, int _pos2);

    bool gridEquals(puzzleNode _node1, puzzleNode _node2);

    bool isExpanded(puzzleNode _node );

    void pushMove(int _pos1, int _pos2);
    void makeMove(int _pos1, int _pos2);

    puzzleNode finalState;

   //int wrongAmount;
    //int tmpWrongAmount[4];

    std::vector<puzzleNode> expandedNodes;

    typedef std::priority_queue<puzzleNode,std::vector<puzzleNode>,puzzleNodeComp> puzzlePQ;
    //puzzlePQ openNodes(puzzleNodeComp(true));
    puzzlePQ openNodes;

};
