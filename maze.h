//
// Created by Anthony Villalobos on 9/9/25.
//

#ifndef MAZE_H
#define MAZE_H

#include <vector>
#include <string>
using namespace std;

class maze {
public:
    maze(string filename);
    void print();
    bool solve();
    void begin_and_target();
    void printSolved();
    bool inBounds(int r, int c) const;
    bool isOpenCell(int r, int c) const;
    bool hasUnexploredNeighbor(int row, int col, int& nextr, int& nextc);
    void resetVisited();


private:
    vector<vector<int>> grid;
    vector<vector<bool>> visited;
    vector<int> pathR;
    vector<int> pathC;
    int beginrow, begincol;
    int goalrow,  goalcol;
};


#endif //MAZE_H
