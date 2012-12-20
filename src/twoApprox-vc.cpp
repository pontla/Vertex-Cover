#include "twoApprox-vc.hpp"
#include "graphAl.hpp"
int k = 0 ;

int TwoApprox(graph &g){; 
    graph gprime;
    vector<vector<int> > graph0 = g.graphNE;
    vector<int> edgeU ;
    int noeudU , noeudV;
    if(compute_Edges(g)==0)
	return 0;
    k+=2;
    // selectionner une arête au hasard : A ameliorer ... 

    //on récupère un indice de noeud U
    noeudU = selectNode(g);
    noeudV = selectEdge(g, noeudU);
//     cout << "2Approx :  nV : " << noeudV ;
    
      //on transvase la valeur du noeud
    edgeU = graph0[noeudU];
    
//     cout << " edgeU : " << edgeU[0]<< endl;
    
    noeudU = edgeU[0];
    
    //copier noeuds sans ceux selectionnés
    //copier aretes restantes
    cpyEdges(g, gprime, noeudU , noeudV );
    //printGraph(gprime);
//     cout << "il reste : " << compute_Edges(gprime) << " aretes " << endl ;
    if(compute_Edges(gprime)!=0){
	TwoApprox(gprime);
    }
   return k;
}

// retourne indice du noeud
int selectNode(graph g){
    vector<vector<int> > ListAretes = g.graphNE;
    srand(time(NULL));
    int random = rand() ;
    random = random % ListAretes.size();
    return random;
}

int selectEdge(graph g, int node){
    vector<vector<int> > graph0 = g.graphNE;
    vector<int> edgeU = graph0[node];
    srand(time(NULL));
    int random = rand() ;
    random = random % (edgeU.size()-1) + 1;
    random = edgeU[random];
    return random;
}