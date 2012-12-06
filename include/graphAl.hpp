#ifndef GRAPHAL_INCLUDED
#define GRAPHAL_INCLUDED
#include <vector>
#include <iostream>
#include <stdlib.h>
#include <time.h>

using std::vector;
using namespace std;


struct graph{
    unsigned int n, algo;
    double p;
    vector<vector<int > > graphNE ;
    vector<int> card;
};

void construct_Rand(graph &g);
int compute_Edges(graph g);
int compute_Max_Card(graph g);
double compute_AVG_Card(graph g);
void addEdge(graph &g, int u , int v);
void addNode(graph &g);
void printGraph(graph g);
void printVect(vector<int> p_vector);
#endif