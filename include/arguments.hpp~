#ifndef ARGUMENTS_HPP
#define ARGUMENTS_HPP

#include <string>

class Arguments
{
public:
	Arguments( int argc, char * argv[] );
	int size() const;
	bool exists( const std::string & opt ) const;
	bool has_param( const std::string & opt ) const;
	std::string operator []( const std::string & opt ) const;

protected:
	int _argc;
	char ** _argv;
};

#endif

 
