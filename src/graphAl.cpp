#include "graphAl.hpp"
unsigned int cpt, cpt2;
vector<vector<int> > graphCpy;
vector<int> edgeCpy;

void construct_Rand(graph &g){  
    srand(time(NULL));
    double random = 0.0 ; 
    
    for(cpt=0; cpt<g.n; cpt++){
	addNode(g);
    }
    for(cpt=0; cpt<g.n; cpt++){
	for(cpt2=cpt+1; cpt2<g.n; cpt2++){
	    random = rand() / (double)RAND_MAX; // rndome entre0-1 
	    if(random<g.p)
		addEdge(g,cpt,cpt2);
	}
    }
}

int compute_Edges(graph g){
    int nbEdges = 0;

    graphCpy = g.graphNE;
    
    for(cpt=0; cpt<graphCpy.size() ; cpt++){
	edgeCpy = graphCpy[cpt];
	nbEdges += edgeCpy.size();
    }
    return nbEdges;
}

int compute_Max_Card(graph g){
    unsigned int maxCard = 0 ;
    graphCpy = g.graphNE;
    
    for(cpt=0; cpt<graphCpy.size() ; cpt++){
	edgeCpy = graphCpy[cpt];
	if(edgeCpy.size()>maxCard)
	    maxCard = edgeCpy.size();
    }
    return maxCard;
}

double compute_AVG_Card(graph g){
    double average =0.0;
    
    average = (double)compute_Edges(g) / g.n;
    
    return average;
}

void addEdge(graph &g, int u , int v){
        vector<vector<int> > graph0 = g.graphNE;
	vector<int> nodeU=graph0[u];
	vector<int> nodeV=graph0[v];
	nodeU.push_back(v-1);
	nodeV.push_back(u-1);
	graph0[u] = nodeU;
	graph0[v] = nodeV;
	g.graphNE = graph0;	
}

void addNode(graph &g){
    vector<vector<int> > graph0;
    vector<int> node;
    graph0 = g.graphNE; 
    graph0.push_back(node);
    g.graphNE = graph0;
}

void printVect(vector<int> p_vector){
    unsigned int cpt;
    for(cpt=0 ; cpt<p_vector.size(); cpt++){
        cout << p_vector[cpt]+1 << " " ;
    }
    cout << endl;
}

void printGraph(graph g){
    vector<vector<int> > grahToPrint = g.graphNE;
    unsigned int cpt;
    for(cpt=0 ; cpt<grahToPrint.size(); cpt++){
        cout << cpt << " : ";
        printVect(grahToPrint.at(cpt));
    }
}