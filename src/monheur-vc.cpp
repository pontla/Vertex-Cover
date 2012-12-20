#include "monheur-vc.hpp"
int kMinHeur=0 , kminHeur2 = 0;


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

int heuristique2(graph &g){
    graph gprime;
    vector<vector<int> > graph0 = g.graphNE;
    vector<int> edgeU ;
    int noeudU;
    
    // selectionner une arête au hasard :

    noeudU = selectNodeMin(g);
    cpyEdges(g, gprime, noeudU , noeudU );
    //printGraph(gprime);
    kminHeur2++;
    if(compute_Edges(gprime)!=0){
	heuristique2(gprime);
    }
    return kminHeur2;
}

int selectNodeMin(graph g){
    unsigned int cpt2, cardMin ;
    int noeudMin=0;
    vector<vector< int> > ListEdges = g.graphNE ;
    vector<int> ListNoeud = g.nodes, aretes;
    
    cardMin = ListNoeud.size();
    for(cpt2=0 ; cpt2<ListEdges.size() ; cpt2++){
	aretes = ListEdges[cpt2];
	if(cardMin > aretes.size()-1){
	    cardMin = aretes.size()-1;
	    noeudMin = aretes[0];
	}
    }
    return noeudMin;
}

int meilleurK(graph &g){
    int k1 =  heuristique(g) ; 
    int k2 =  heuristique2(g) ;
    cout << " k1 : "<< k1 << " k2 : " << k2 << endl;
    if(k1 <k2)
	return  k1;
    return k2;
}