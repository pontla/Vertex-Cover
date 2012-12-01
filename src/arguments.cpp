#include "arguments.hpp"
#include <iostream>

Arguments::Arguments( int argc, char * argv[] ) :
	_argc( argc ), _argv( argv )
{
}

int Arguments::size() const
{
	return _argc;
}

bool Arguments::exists( const std::string & opt ) const
{
	std::string prefix( 1, '-' );
	int i = 0;

	prefix += opt;

	while ( ++i < _argc )
	{
		if ( prefix == _argv[i] )
		{
			return true;
		}
	}
	return false;
}

bool Arguments::has_param( const std::string & opt ) const
{
	std::string prefix( 1, '-' );
	int i = 0;

	prefix += opt;

	while ( ++i < _argc )
	{
		if ( prefix == _argv[i] )
		{
			return _argv[i+1][0] != '-';
		}
	}
	return false;
}

std::string Arguments::operator []( const std::string & opt ) const
{
	std::string prefix( 1, '-' );
	int i = 0;

	prefix += opt;

	while ( ++i < _argc )
	{
		if ( prefix == _argv[i] && i+1 < _argc )
		{
			return _argv[i+1];
		}
	}
	return "";
}
