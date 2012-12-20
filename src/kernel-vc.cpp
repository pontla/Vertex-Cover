// #include "kernel-vc.hpp"
// 
// bool kernelisation(graph &g, int k){
//     graph gprime;
//     vector<vector<int> > graph0 = g.graphNE;
//     vector<int> listNoeuds = g.nodes , edgeU;
//     unsigned int cpt;
//     int nodeU, nodeV;
//     bool regles = false;
//     /**
//      * Règle VC1 :
//      * Si cardinalité d'un sommet = 1 , prendre son voisin et enlever u et v et leurs arêtes de G
//      * décrémenter k
//      */
//     
//      /**
//      * Règle VC2 :
//      * Si cardinalité d'un sommet >= k+1 , prendre le sommet et enlever u et sess arêtes de G
//      * décrémenter k
//      */
//      
//     if(compute_Edges(g)==0)
// 	  return true;
//     if(k==0) 
// 	  return false;
//     
//     //VC1 :
//     for(cpt=0; cpt<listNoeuds.size(); cpt++){
// 	if(graph0[cpt].size() == 1)
// 	{
// 	    edgeU = graph0[cpt];
// 	    nodeU = poidsNoeud( g, cpt);
// 	    nodeV = edgeU[0];
// 	    cpyEdges(g, gprime,nodeU, nodeV); 
// 	    cpt = listNoeuds.size();
// 	    k-1;
// 	    regles = true;
// 	}
//     }
//     
//     if(!regles){
//     //VC2
// 	//parcours de la liste de noeuds : 
// 	for(cpt=0; cpt<listNoeuds.size(); cpt++){
// 	    if(graph0[cpt].size() >= k+1)
// 	    {
// 		edgeU = graph0[cpt];
// 		nodeU = poidsNoeud( g, cpt);
// 		cpyEdges(g, gprime,nodeU, nodeU); 
// 		cpt = listNoeuds.size();
// 		k-1;
// 	    }
// 	}
//     }
//     
//     
// }
// int dichotomieK(graph g, int k);