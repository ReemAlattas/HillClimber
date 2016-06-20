//
//  main.cpp
//  HillClimber
//
//  Created by Reem Alattas on 6/20/16.
//  Copyright © 2016 ReemAlattas. All rights reserved.
//

#include <iostream>
using std::cout;
using std::endl;

#include <vector>
using std::vector;

int fitness(vector<int> &parent);
void make_child(vector<int> &parent, vector<int> &child);

int main(int argc, const char * argv[]) {
    
    vector<int> parent(13, 0);
    vector<int> child(13, 0);
    vector<int> temp(13, 0);
    
    int fit_parent = fitness(parent);
    int fit_child = fitness(child);
    
    if (fit_child > fit_parent)
    {
        parent = child;
        make_child(parent, child);
    }
    
    return 0;
}

//Fitness Function
int fitness(vector<int> &parent)
{
    int fit = 0;
    
    for (int i = 0; i < parent.size(); i++) {
        fit += parent[i];
    }
    
    return fit;
}

//Make Child
void make_child(vector<int> &parent, vector<int> &child)
{
    child = parent;
    int random = rand() % 13;
    child[random] = abs(child[random] - 1);
}
