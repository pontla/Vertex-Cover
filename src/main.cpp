#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <limits>
#include <ctime>
#include "arguments.hpp"

#define _DEBUG 0

int main( int argc, char * argv[] )
{
	int  time = 3, nodes=0 , edges = 0;
	
	Arguments args( argc, argv );
	std::ifstream file;
	std::string rmspace( 60, ' ' );

	if ( !args.exists( "algo" ) || !args.exists( "n" ) || !args.exists( "p" ))
	{
		std::cout << "Usage: " << std::endl << '\t'
			<< argv[0] << " [-n <#nodes>] [-p <#edges>] [-algo <algorithm>] [-time <time>]" << std::endl
			<< std::endl
			
			<< "\t-n <#nodes>" << std::endl
			<< "\t\tNombre de noeuds que le programme generera." << std::endl
			
			<< "\t-p <#edges>" << std::endl
			<< "\t\tNombre d'aretes sachant \"n\", étant le nombre de noeuds" << std::endl
			
			<< "\t-algo <algorithm>" << std::endl
			<< "\t\tAlgorithm de VC a executer :" << std::endl
			<< "\t\t\t -[kernel] : pour l'algorithme de Kernelization" << std::endl
			<< "\t\t\t -[arb] : pour l'algorithme VCA" << std::endl
			<< "\t\t\t -[2approx] : pour l'algorithme de 2-approximation" << std::endl
			<< "\t\t\t -[heuristique] : pour l'algorithme heuristique au choix" << std::endl

			<< "\t-time <time>" << std::endl
			<< "\t\tTemps pour un run." << std::endl
			<< "\t\t(defaut:" << time << "minutes)" << std::endl
			
			<< std::endl;
		return 0;
	}
	// Parsage des arguments
		// max itérations
	if ( args.exists( "n" ) )
	{
		std::istringstream iss( args[ "n" ] );
		iss >> nodes;
	}
	
	if ( args.exists( "p" ) )
	{
		std::istringstream iss( args[ "p" ] );
		iss >> edges;
	}
	

	if ( args.exists( "time" ) )
	{
		std::istringstream iss( args[ "time" ] );
		iss >> time;
	}
	
	std::cout << "temps : "<< time << " -edges: " << edges << " -nodes " << nodes << std::endl;
	
	return 0;
}