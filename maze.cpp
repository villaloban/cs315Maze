//
// Created by Anthony Villalobos on 9/9/25.
//
#include <iostream>
#include "maze.h"
#include <fstream>
#include <stack>
using namespace std;

maze::maze(string filename) {
    ifstream inFS(filename);
    if (!inFS.is_open()) {
        cout << "error" << filename <<  endl;
        return;
    }
    string line;
    while (getline(inFS, line)) {
        vector<int> row;
        for (int i = 0; i < line.size(); i++) {
            if (line[i] == '0') {
                row.push_back(0);
            }
            else if (line[i] == '1'){
                row.push_back(1);
            }
        }
        if (!row.empty())
            grid.push_back(row);

    }
}

void maze::begin_and_target() {
    // set condition for finding the start
    bool foundstart = false;

    for (int r = 0; r < grid.size(); r++) {
        for (int c = 0; c < grid[r].size(); c++) {
            if ((r == 0 || r == grid.size() - 1 ||
                 c == 0 || c == grid[r].size() - 1) &&
                grid[r][c] == 0)
            {
                if (!foundstart) {
                    beginrow = r;
                    begincol = c;
                    foundstart = true;
                }
                else {
                    goalrow = r;
                    goalcol = c;
                    return;
                }
            }
        }
    }
}



bool maze::inBounds(int r, int c) const {
    if (grid.empty())
        return false;
    if (r < 0 || c < 0)
        return false;
    if (r >= grid.size())
        return false;
    if (c >= grid[r].size())
        return false;
    return true;
}

bool maze::isOpenCell(int r, int c) const {
    if (inBounds(r, c) && grid[r][c] == 0)
        return true;
    return false;
}

bool maze::hasUnexploredNeighbor(int row, int col, int &nextr, int &nextc) {
    //up
    if (isOpenCell(row - 1, col) && !visited[row - 1][col]){
        nextr = row - 1;
        nextc = col;
        return true;
    }
    //down
    if (isOpenCell(row + 1, col) && !visited[row + 1][col]){
        nextr = row + 1;
        nextc = col;
        return true;
    }
    //right
    if (isOpenCell(row, col + 1) && !visited[row][col + 1]){
        nextr = row;
        nextc = col + 1;
        return true;
    }
    //left
    if (isOpenCell(row, col - 1) && !visited[row][col - 1]){
        nextr = row;
        nextc = col - 1;
        return true;
    }
    return false;
}

void maze::resetVisited() {
    if (grid.empty())
        return;
    visited.resize(grid.size());
    for (int r = 0; r < grid.size(); r++) {
        visited[r].resize(grid[r].size());
        for (int c = 0; c < grid[r].size(); c++)
            visited[r][c] = false;
    }
}

bool maze::solve() {
    if (grid.empty()) {
        return false;
    }

    if (beginrow < 0 || goalrow < 0) {
        cout << "No open boarder's found." << endl;
        return false;
    }

    resetVisited();

    stack<int> rstack;
    stack<int> cstack;

    rstack.push(beginrow);
    cstack.push(begincol);
    visited[beginrow][begincol] = true;

    while (!rstack.empty()) {
        int r = rstack.top();
        int c = cstack.top();
        int rnext, cnext;

        if (!hasUnexploredNeighbor(r, c, rnext, cnext)) {
            rstack.pop();
            cstack.pop();
        }
        else {
            rstack.push(rnext);
            cstack.push(cnext);
            visited[rnext][cnext] = true;

            if (rnext == goalrow && cnext == goalcol)
                break;
        }
    }
    if (rstack.empty()) {
        return false;
    }
    while (!rstack.empty()) {
        pathR.insert(pathR.begin(), rstack.top());
        pathC.insert(pathC.begin(), cstack.top());
        rstack.pop();
        cstack.pop();
    }
    return true;

}


void maze::print() {
    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[i].size(); j++) {
            cout << grid[i][j];
        }
        cout << endl;
    }
}

void maze::printSolved() {
    if (pathR.empty()) {
        cout << "No solution" << endl;
        return;
    }


    for (int r = 0; r < grid.size(); r++) {
        for (int c = 0; c < grid[r].size(); c++) {
            bool followpath = false;

            for (int i = 0; i < pathR.size(); i++) {
                if (pathR[i] == r && pathC[i] == c) {
                    followpath = true;
                    break;
                }
            }
        if (grid[r][c] == 1) {
            cout << '1';
        }
        else if (followpath) {
            cout << "\033[36m*\033[0m";
        }
        else {
            cout << '0';
        }
        }
        cout << '\n';

    }
}
