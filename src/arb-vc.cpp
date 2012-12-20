#include "arb-vc.hpp"
#include "twoApprox-vc.hpp"
bool coupure;

bool arbvc(graph &g , int k){
// printGraph(g);
    graph G1, G2;
    vector<vector<int> > graph0 = g.graphNE;
    vector<int> edgeU ;
    bool resultat1 , resultat2 ;
    int noeudU , noeudV;
    
    /**
    * 1- Si E(G) = 0  => Vrai 
    * 2- Si k = 0 => Faux
    * 3- arête au hasard {u,v} de G
    * 4- G1 - {u} et G2 - {v}
    * 5- Return AVC(G1,k-1) ou AVC(G2,k-1)
    */
    if(coupure){
	cout << " COUPURE ";
	return true;
    }
    if(compute_Edges(g)==0)
	return true;
    if(k==0) 
	return false;
    // selectionner une arête au hasard :
//on récupère un indice de noeud U
    noeudU = selectNode(g);
    noeudV = selectEdge(g, noeudU);
    
    //on transvase la valeur du noeud
    edgeU = graph0[noeudU];
    
    noeudU = edgeU[0];
    //printGraph(g);
// cout << "On enlève les noeuds : " << noeudU << " " << noeudV <<  " k = " << k << endl;

    // G1 - u  et G2 - v     
    cpyEdges(g, G1, noeudU , noeudU );
    
    cpyEdges(g, G2, noeudV , noeudV );

    k= k-1;
    resultat1 = arbvc(G1 , k);
    resultat2 = arbvc(G2 , k);
    coupure = (resultat1 || resultat2) ;
    return coupure ;
}


//recherche dichotomique : 
int dichotomie(graph &g, int k , int k2){
    int debut, fin, mil, kMin = k2;
    bool  algo;
    coupure = false;
    
    // init :
    debut = k/2;
    fin = k2;
    
    //boucle de recherche
    do{
	mil = (debut + fin) / 2;
	cout << " Test pour k = " << mil << endl;
	algo = arbvc(g, mil) ;
	if(algo){
	    kMin = mil;
	    fin = mil;
	}else{
	    debut = mil+1;
	}
	cout << " kMin : " << kMin << " " << debut << " " << fin << endl;
    }while(debut != fin );
    return kMin;
}