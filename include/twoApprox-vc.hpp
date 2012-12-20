#ifndef TWOAPPROX_VC_HPP_INCLUDED
#define TWOAPPROX_VC_HPP_INCLUDED

#include <vector>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "graphAl.hpp"

using std::vector;
using namespace std;

int TwoApprox(graph &g);

int selectNode(graph g);
int selectEdge(graph g, int node);

#endif