#include "arb-vc.hpp"
#include "twoApprox-vc.hpp"
bool coupure, temps;
clock_t tstart = clock();


bool arbvc(graph &g , int k){
    
    //GESTION DE LA LIMITE DE TEMPS : 
    clock_t tend = clock();
    if( (double)(tend - tstart) / (double)CLOCKS_PER_SEC >= g.time ){
	temps = false; 
	return false; // coupe le programme 
    }

    //Declaration et initiailisation
    graph G1, G2 , Gcpy;
    vector<vector<int> > graph0 = g.graphNE;
    vector<int> ListNoeud = g.nodes, ListNoeudSup3, edgeCPT, voisinsU;
    bool resultat1 , resultat2  ;
    int noeudU , noeudV, kprime = k;
    unsigned int cpt;
    
    //ALGO : 
    /**
    * 1- Si E(G) = 0  => Vrai 
    * 2- Si k = 0 => Faux
    * 3- Si degré max de g <= 2 , return " resultat graph degra max 2 "
    * 4- Choisir arbitrairement un sommet de card >= 3 
    * 5- G1 - {u} et G2 - {voisins de u}
    * 6- Return AVC(G1,k-1) ou AVC(G2,k-(nb voisins))
    */
    
    for(cpt=0 ; cpt<graph0.size() ; cpt++){
	edgeCPT = graph0[cpt];
	if(edgeCPT.size()-1 >= 3){
	    ListNoeudSup3.push_back(edgeCPT[0]);
	}
    }
    
    if(coupure){
	return true;
    }
    if(compute_Edges(g)==0 && k>=0)
	return true;
    if(k<=0) 
	return false;
    
    //s'il n'y a plus que des noeuds de degré inférieur à 3 on execute l'algo de résolution adapté
    if(ListNoeudSup3.size()==0){
	return graphTaille2(g,k);
    }
    else
	noeudU = selectNodeSup3(ListNoeudSup3);
    voisinsU = graph0[ListNoeud[noeudU]] ;
    

    Gcpy = g ; 
    for(cpt = 1 ; cpt < voisinsU.size() ; cpt++){
	noeudV = voisinsU[cpt];
	cpyEdges(Gcpy, G2, noeudV , noeudV );
	Gcpy = G2;
	kprime--;
    }

    cpyEdges(g, G1, noeudU , noeudU );
    resultat1 = arbvc(G1 , k-1);
    
    resultat2 = arbvc(G2 , kprime);
    coupure = (resultat1 || resultat2) ;
    return coupure ;
}

bool graphTaille2(graph g, int k){
    graph G1;
    vector<vector<int> > graph0 = g.graphNE;
    vector<int>  edgeCPT;
    int noeud;
    bool res = false;
    
    /**
     * 1- Si un noeud de card = 1 , prendre son voisin , l'enlever de G , décrémenter k et recommencer
     * 2- Si noeud de card = 2 , prendre le noeud , l'enlver de G, décrémenter k et recommencer
     */    
	if(compute_Edges(g)==0 && k>=0)
	    return true;
	if(k<=0) 
	    return false;
	
	edgeCPT = graph0[0];
	// Si on a un noeud au moins avec une card = 1
	if(edgeCPT.size()-1 == 1){
	    noeud = edgeCPT[1];
	    cpyEdges(g, G1, noeud , noeud );
	    k = k -1 ;
	    res= graphTaille2(G1, k);
	}
	
	if(edgeCPT.size()-1 == 2){
	    noeud = edgeCPT[0];
	    cpyEdges(g, G1, noeud , noeud );
	    k = k -1;
	    res =graphTaille2(G1, k);
	}
	return res;
}

// retourne indice du noeud
int selectNodeSup3(vector<int> ListNoeuds){
    srand(time(NULL));
    int random = rand() ;
    random = random % ListNoeuds.size();
    return ListNoeuds[random];
}

//fonction test pour dichotomie
bool testDicho(int k){
 if(k>=7)
     return true;
 else
     return false;
}

//recherche dichotomique : 
int dichotomieARBVC(graph &g, int k , int k2){
    int debut, fin, mil, kMin = k2;
    bool  algo;

    //Init
    debut = k/2;
    fin = k2;
    if(k2 > k ){ 
	kMin = k;
	fin = k;}
    
    //boucle de recherche
    do{
	coupure = false;
	temps = true;
	mil = (debut + fin) / 2;
	algo = arbvc(g, mil) ;
	//algo = testDicho(mil);
	if(algo){
	    kMin = mil;
	    fin = mil;
	}else{
	    debut = mil+1;
	}
    }while(debut != fin );
    
    if(!temps)
	kMin = -1;
    return kMin;
}