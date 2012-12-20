#include "graphAl.hpp"
#include <algorithm>

vector<vector<int> > graphCpy;
vector<int> edgeCpy;

void construct_Rand(graph &g){
	unsigned int cpt , cpt2;
	srand(time(NULL));
	double random = 0.0 ;
	
	for(cpt=0; cpt<g.n; cpt++){
	    addNode(g, cpt);
	}
	for(cpt=0; cpt<g.n; cpt++){
	    for(cpt2=cpt+1; cpt2<g.n; cpt2++){
			random = rand() / (double)RAND_MAX; // rndome entre0-1
			if(random<g.p)
				addEdge(g,cpt,cpt2);
	    }
	}
}
void MaJgraph(graph &g, int noeudU){
   // cout << "MAJ : noeud : " << noeudU << endl;
    vector<int> ListIndiceNoeuds = g.nodes;
    unsigned int cpt;
    for(cpt=noeudU + 1; cpt<ListIndiceNoeuds.size(); cpt++){
	ListIndiceNoeuds[cpt]--;
    }
    ListIndiceNoeuds[noeudU] = -1 ;
    g.nodes = ListIndiceNoeuds;
}
 
void cleanEptyNodes(graph &g){
    vector<vector<int> > graph0 = g.graphNE, graph0prime = graph0;
    vector<int> edges, ListNoeuds = g.nodes;
    unsigned int cpt, cpt2 = 0;
    
    //Pour chaque liste d'aretes 
    for(cpt = 0 ; cpt < graph0.size(); cpt++){
	//On récupère la liste d'arete du cpt_ieme noeud
	edges = graph0[cpt];
	
	if(edges.size()<=1){
	    graph0prime.erase(graph0prime.begin()+cpt2);
	   // cout << " CleanMAJ " ;
	    cpt2--;
	    MaJgraph(g, edges[0]);
	}
	cpt2++;
    }
   // printGraph(g);
    g.graphNE = graph0prime;
}

int compute_Edges(graph g){
	int nbEdges = 0;
	unsigned int cpt;
	
	graphCpy = g.graphNE;
	
	for(cpt=0; cpt<graphCpy.size() ; cpt++){
	    edgeCpy = graphCpy[cpt];
	    nbEdges += edgeCpy.size()-1;
	}
	return nbEdges;
}

int compute_Max_Card(graph g){
	unsigned int maxCard = 0 , cpt;
	graphCpy = g.graphNE;
	
	for(cpt=0; cpt<graphCpy.size() ; cpt++){
	    edgeCpy = graphCpy[cpt];
	    if(edgeCpy.size()-1>maxCard)
			maxCard = edgeCpy.size()-1;
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

	//On récupère les listes d'arêtes correspondants aux indices u et v
	vector<int> edgeU=graph0[u];
	vector<int> edgeV=graph0[v];
	
	//On ajoute la valeur des noeuds aux listes d'arêtes
	edgeU.push_back(v);
	edgeV.push_back(u);
	
	//Mise à jour du graph
	graph0[u] = edgeU;
	graph0[v] = edgeV;
	g.graphNE = graph0;
}

void addNode(graph &g, int noeud){
	vector<vector<int> > graph0;
	vector<int> node ;
	
	graph0 = g.graphNE;
	node.push_back(noeud);
	graph0.push_back(node);
	g.graphNE = graph0;
	
	node = g.nodes;
	node.push_back(noeud);
	g.nodes = node;
}



// u et v sont les poids des noeuds ( valeur )
void cpyEdges(graph g, graph &gprime,  int u,  int v){
	vector<int> ListNoeuds;
	gprime = g ;	
	//erase U 
	eraseNode(gprime, u);
	ListNoeuds = gprime.nodes;
	//erase V
	if( u != v && ListNoeuds[v]!= -1)
	    eraseNode(gprime, v);
}

//NodeU valeur du noeud U dans la Liste de noeuds
void eraseNode(graph &g, int NodeU){
    //déclaration
    vector<vector<int> > ListAretes ;
    vector<int> ListNoeuds , edgesU, arete;
    unsigned int cpt, cpt2;
    int cptNoeudU; // emplacement du noeud U dans la Liste d'aretes
    
   // cout << endl << "erase : " <<  NodeU ;
    
    // Initialisation : 
    ListAretes = g.graphNE;
    ListNoeuds = g.nodes ;
    cptNoeudU = ListNoeuds[NodeU] ;
    edgesU = ListAretes[cptNoeudU] ;
    
    
    //Pour chaque éléments de l'arete que l'on supprime:
    for(cpt=1 ; cpt<edgesU.size() ; cpt++){
	arete = ListAretes[ListNoeuds[edgesU[cpt]]];//On récupère l'arete correspondante dans laquelle on va supprimer un noeud
	
	// parcours de l'arete pour chercher U et l'effacer
	for(cpt2 =1 ; cpt2<arete.size() ; cpt2++){
// 	    cout << "cpt2 :" << cpt2 ;
	    if(arete[cpt2] == NodeU){
		arete.erase (arete.begin()+cpt2);//on efface l'élément U de l'arête 
// 		cout << "  " << endl;
		cpt2 = arete.size(); // stop la boucle
	    }
	}
	ListAretes[ListNoeuds[edgesU[cpt]]] = arete;
    }
    
    // Maintenant on supprime le noeud U ( et donc toutes les arêtes associées ) ) 
    
    ListAretes.erase ( ListAretes.begin() +  ListNoeuds[NodeU]) ;
    g.graphNE = ListAretes ;
   // cout << " Erase : ";
    //MàJ du vecteur de compteurs 
    MaJgraph(g, NodeU);
    cleanEptyNodes(g);
}

bool searchEdge(graph g, vector<int> edgeU , int V){
    unsigned int cpt;
    for(cpt =0; cpt<edgeU.size(); cpt++){
	if(edgeU[cpt] == poidsNoeud(g,V))
	    return true;
    }
    return false;
}

/* void calculCard(graph &g){
 
 }*/

int poidsNoeud(graph g, int indice){
	edgeCpy = g.nodes;
	return edgeCpy[indice];
}

void printVect(vector<int> p_vector){
	unsigned int cpt;
	for(cpt=1 ; cpt<p_vector.size(); cpt++){
	    cout << p_vector[cpt] << " " ;
	}
	cout <<endl;
}

void printGraph(graph g){
	vector<vector<int> > grahToPrint = g.graphNE;
	vector<int> node = g.nodes , Noeud;
	unsigned int cpt;
	cout << " Print Graph : " << endl;
	for(cpt=0 ; cpt<grahToPrint.size(); cpt++){
	    Noeud = grahToPrint[cpt];
	    cout <<Noeud[0]/* node[cpt]*/ << " : ";
	    printVect(grahToPrint.at(cpt));
	}
}