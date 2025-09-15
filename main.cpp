#include <iostream>
#include "maze.h"
#include <fstream>
using namespace std;

int main(int argc, char** argv){
    if (argc != 2) {
        cout << argv[0] << " name-of-aninput-file\n";
        return 1;
    }
    maze m(argv[1]);
    m.begin_and_target();


    if (!m.solve()) {
        cout << "No solutions possible." << endl;
    }
    else {
        m.printSolved();
    }

    return 0;

}
