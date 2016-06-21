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

int fitness(vector<int> &);
void make_child(vector<int> &, vector<int> &);
void output_vector(vector<int> &);

int main(int argc, const char * argv[]) {
    
    vector<int> parent(13, 0);
    vector<int> child(13, 0);
    
    make_child(parent, child);
    
    //Evolve
    for (int i = 1; i<=25; i++)
    {
        cout << "Iteration # " << i << endl;
        output_vector(parent);
        output_vector(child);
        
        int fit_parent = fitness(parent);
        int fit_child = fitness(child);
    
        cout << "Parent Fitness = " << fit_parent << endl;
        cout << "Child Fitness = " << fit_child << endl;
    
        if (fit_child > fit_parent)
        {
            parent = child;
        }
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

//Output Vector
void output_vector(vector<int> &vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        cout << vec[i] << " ";
    }
    cout << endl;
}
