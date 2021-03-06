#ifndef GRAPHAL_HPP_INCLUDED
#define GRAPHAL_HPP_INCLUDED
#include <vector>
#include <iostream>
#include <stdlib.h>
#include <time.h>

using std::vector;
using namespace std;


struct graph{
    unsigned int n, algo, time;
    double p;
    vector<vector<int > > graphNE ;
   // vector<bool> noeudActif; // tri de la plus grande à la plus petite .
    vector<int> nodes;
};

//METHODES
void construct_Rand(graph &g);
void cleanEptyNodes(graph &g);
void MaJgraph(graph &g, int noeudU);

int compute_Edges(graph g);
int compute_Max_Card(graph g);
double compute_AVG_Card(graph g);

void addEdge(graph &g, int u , int v);
void addNode(graph &g, int noeud);

void cpyNodes(graph g, graph &gprime,  int u,  int v);
void cpyEdges(graph g, graph &gprime,  int u, int v);

void eraseNode(graph &g, int NodeU);
bool searchEdge(graph g, vector<int> edgeU , int V);
int poidsNoeud(graph g, int indice);
int indiceNoeud(graph g, int noeud);

//PRINT 
void printGraph(graph g);
void printVect(vector<int*> p_vector);
#endif