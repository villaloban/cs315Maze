**Student Info:** 
Name: Anthony Villalobos
Student ID: 008394627
Repo Link: https://github.com/anthony-villaloban/cs315Maze.git

Collaboration & Sources: The sources that I used to help me with this project were GeeksforGeeks and chatgpt. During this project I encountered an issue where I was hardcoding the file that was being read. This caused it so whenever I would run it on blue then it would end up backfiring and saying there was an error reading the file. I tried including the file in the cmake debug and in the main folder but still I encountered this issue. I ended up asking chatgpt why I was encountering this issue and it's because it was being hard coded and would end up ignoring what was on the command line and woudldn't read it or just crash. I ended up using geeksforgeeks on help with the backtracking algorithm, stacks, and also with matrix guides. 

Implementation & Details: This program reads a file that contains a maze made up of 0's and 1's. 0's represent an open space and 1's represent a wall, each maze must contain two boarder open cells in order to have a beginning and target goal. 
This program used functioms such as 
    bool solve(); //solved for maze using backtracking algoritm, and stack algorithm
    void begin_and_target(); //Traversed the maze and found two open boarder 0's one being a beginning and the other being the target
    void printSolved(); //printed the correct path that the maze took in order to finish
    bool inBounds(int r, int c) const; //checks if the row or colums are in the maze and doesn't go out of bounds
    bool isOpenCell(int r, int c) const; //checks if the neigboring cell is open or not
    bool hasUnexploredNeighbor(int row, int col, int& nextr, int& nextc); //finds the next cell that has not been visited previously 
    void resetVisited(); //resets the cells that were visisted before we solve

Testing & Status: 
An example of tests that were used include this maze
1110111
1000001
1011101
1010101
1010111
1000001
1110111

Then on blue ./a.out maze0-1_input.txt was typed in the command line and it returned the solved maze with '*' representing the path it used. 
111*111
1***001
1*11101
1*10101
1*10111
1***001
111*111

An example where theres there's a maze with no solution include 
01111
11111
11111
11111
11110

When we run this on blue we get ./a.out maze0-1_input.txt
No solutions possible.
We get this result since even though there two boarding open cells there is no path that they can move to so therefore it's unsolvable

However there is a seg fault whenever there is no open boarders it gives a seg fault because there are no open boarders. For example 
111
101
101
101
111

.when ran gives /a.out file1.txt      
zsh: segmentation fault  ./a.out file1.tx


