    #include "graphAl.hpp"
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

    int compute_Edges(graph g){
	int nbEdges = 0 , cpt;

	graphCpy = g.graphNE;
	
	for(cpt=0; cpt<graphCpy.size() ; cpt++){
	    edgeCpy = graphCpy[cpt];
	    nbEdges += edgeCpy.size();
	}
	return nbEdges;
    }

    int compute_Max_Card(graph g){
	unsigned int maxCard = 0 , cpt;
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
	    int uprime , vprime;
	    vector<vector<int> > graph0 = g.graphNE;
	    
	    //On récupère les listes d'arêtes correspondants aux indices u et v
	    cout<< " DBGaddEdge valeurs :" << u << v  << " indices :" << indiceNoeud(g,u) << " " << indiceNoeud(g,v) << endl;
	    vector<int> edgeU=graph0[indiceNoeud(g,u)];
	    vector<int> edgeV=graph0[indiceNoeud(g,v)];

	    uprime = u;
	    vprime = v;	

	    //On ajoute la valeur des noeuds aux listes d'arêtes
	    edgeU.push_back(vprime-1);
	    edgeV.push_back(uprime-1);
	    
	    //Mise à jour du graph
	    graph0[indiceNoeud(g,u)] = edgeU;
	    graph0[indiceNoeud(g,v)] = edgeV;
	    g.graphNE = graph0;
    }

    void addNode(graph &g, int noeud){
	vector<vector<int> > graph0;
	vector<int> node;
	graph0 = g.graphNE; 
	graph0.push_back(node);
	g.graphNE = graph0;
	
	node = g.nodes;
	node.push_back(noeud);
	g.nodes = node;
    }

    //void cpyNodes(graph g, graph &gprime, int u);
    void cpyNodes(graph g, graph &gprime, int u, int v){
	int cpt;
	vector<int> ListNoeuds = g.nodes , ListNoeudsPrime;
	for(cpt=0 ; cpt<ListNoeuds.size() ; cpt++){
	    if(cpt!=u && cpt!=v){
		ListNoeudsPrime.push_back(poidsNoeud(g,cpt));
	    }
	}
	gprime.nodes = ListNoeudsPrime ;
    }

    
    void cpyEdges(graph g, graph &gprime, int u, int v){
	int cpt, cpt2;
	    vector<int> ListNoeuds = g.nodes , ListNoeudsPrime = gprime.nodes , aretes , aretesPrime;
	    vector<vector<int> > ListAretes = g.graphNE , ListAretesPrime;
	    
	    for(cpt=0 ; cpt<ListNoeuds.size() ; cpt++){
		aretes = ListAretes[cpt];
		for(cpt2=0 ; cpt2<aretes.size() ; cpt2++){
		    if(cpt2 != u && cpt2 != v){
			cout << " cpyEdges : " << cpt << cpt2 << " " << poidsNoeud(g,cpt) << " " <<  poidsNoeud(g,cpt2)<< endl; 
			addEdge(gprime,poidsNoeud(g,cpt), poidsNoeud(g,cpt2));
		
			}
		    }
	    }   
    }

    int poidsNoeud(graph g, int indice){
	edgeCpy = g.nodes;    
	return edgeCpy[indice];
    }

    int indiceNoeud(graph g, int noeud){
	vector<int> ListNoeuds = g.nodes;
	int cpt;
	for(cpt=0; cpt<g.n ; cpt++){
	    if(noeud == ListNoeuds[cpt])
		return cpt;
	}
	return 0;
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
	vector<int> node = g.nodes;
	unsigned int cpt;
	for(cpt=0 ; cpt<grahToPrint.size(); cpt++){
	    cout << node[cpt] << " : ";
	    printVect(grahToPrint.at(cpt));
	}
    }