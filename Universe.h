//
// Created by abdel on 01/11/2022.
//

#ifndef GAMEOFLIFE_UNIVERSE_H
#define GAMEOFLIFE_UNIVERSE_H
#define SIZE 20
#include "bits/stdc++.h"
using namespace std;
class Universe {
private:
    char x;
    bool grid[SIZE+2][SIZE+2]={false};
public:
    void initialize(string fileName,char x);
    void reset();
    int count_neighbors(int i,int j);
    void next_generator();
    void dispaly();
    void run(int i);
};


#endif //GAMEOFLIFE_UNIVERSE_H
