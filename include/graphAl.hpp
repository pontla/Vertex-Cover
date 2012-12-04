#ifndef GRAPHAL_INCLUDED
#define GRAPHAL_INCLUDED
#include <vector>
#include <iostream>

using std::vector;
using namespace std;


struct graph{
    int n, p, algo;
    vector<vector<int > > graphNE ;
    vector<int> card;
};

void update_Card(graph &g);
void construct_Aleatoire(graph &g);
int compute_Edges(graph g);
int compute_Max_Card(graph g);
double compute_AVG_Card(graph g);
void addEdge(graph &g, int u , int v);
void addNode(graph &g);
void printGraph(graph g);
void printVect(vector<int> p_vector);
#endif