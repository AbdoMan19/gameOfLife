//
// Created by abdel on 01/11/2022.
//

#include "Universe.h"
#include "bits/stdc++.h"
using namespace std;
void Universe::run(int i) {
    for(int k=0;k<i;k++){
        next_generator();
    }

}

void Universe::next_generator() {
    bool temp[SIZE+2][SIZE+2]={false};
    for(int i=1 ;i<SIZE+1;i++){
        for(int j=1;j<SIZE+1;j++){
            int neighbors=count_neighbors(i,j);
            if(grid[i][j]){
                if(neighbors==2||neighbors==3) {
                    temp[i][j] = true;
                }else{
                    temp[i][j]=false;
                }
            }else{
                if(neighbors==3){
                    temp[i][j]=true;
                }
            }
        }
    }
    for(int i=1;i<SIZE+1;i++){
        for(int j=1;j<SIZE+1;j++){
            grid[i][j]=temp[i][j];
        }
    }
    dispaly();
}

void Universe::initialize(string fileName,char x) {
    this->x=x;
    fstream myFile;
    myFile.open(fileName, ios::in);
    for (int i = 1; i < SIZE + 1; i++) {
        for (int j = 1; j < SIZE + 1; j++) {
            char value;
            myFile >> value;
            if (value == '1') {
                grid[i][j] = true;
            } else {
                grid[i][j] = false;
            }
        }
    }
    myFile.close();
}

void Universe::reset() {
    for(int i=1;i<SIZE-1;i++) {
        for(int j=1;j<SIZE-1;j++) {
            grid[i][j]=false;
        }
    }
}

int Universe::count_neighbors(int i, int j) {
    int count = 0;
    for(int k=i-1;k<=i+1;k++){
        for(int l=j-1;l<=j+1;l++){
            if(k==i && l==j){
                continue;
            }else{
                if(grid[k][l]){
                    count++;
                }
            }
        }
    }

    return count;
}

void Universe::dispaly() {
    for(int i=1;i<SIZE-1;i++) {
        for(int j=1;j<SIZE-1;j++) {
            if(grid[i][j]){
                cout<<x;
            }else{
                cout<<'0';
            }
        }
        cout<<endl;
    }
    cout<<endl;
}
