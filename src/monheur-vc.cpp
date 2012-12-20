#include "monheur-vc.hpp"
int kMinHeur=0;


int heuristique(graph &g){
    graph gprime;
    vector<vector<int> > graph0 = g.graphNE;
    vector<int> edgeU ;
    int noeudU;
    
    // selectionner une arête au hasard :

    noeudU = selectNodeMax(g);
    cpyEdges(g, gprime, noeudU , noeudU );
    //printGraph(gprime);
    kMinHeur++;
    if(compute_Edges(gprime)!=0){
	heuristique(gprime);
    }
    return kMinHeur;
}

int selectNodeMax(graph g){
    unsigned int cpt2, cardMax=0 ;
    int noeudMax=0;
    vector<vector< int> > ListEdges = g.graphNE ;
    vector<int> ListNoeud = g.nodes, aretes;
    
    
    for(cpt2=0 ; cpt2<ListEdges.size() ; cpt2++){
	aretes = ListEdges[cpt2];
	if(cardMax < aretes.size()-1){
	    cardMax = aretes.size()-1;
	    noeudMax = aretes[0];
	}
    }
    return noeudMax;
}