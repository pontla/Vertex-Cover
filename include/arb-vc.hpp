#ifndef ARB_VC_HPP
#define ARB_VC_HPP

#include "graphAl.hpp"
#include <ctime>

bool arbvc(graph &g, int k);
int dichotomieARBVC(graph &g, int k, int k2);
bool graphTaille2(graph g, int k);
int selectNodeSup3(vector<int> ListNoeuds);
bool testDicho(int k);
#endif