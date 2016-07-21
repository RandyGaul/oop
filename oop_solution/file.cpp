#include <cassert>
#include "file.h"

File::File( Mode mode, const char* path )
{
	m_fp = fopen( path, mode == eRead ? "r" : "w" );
	assert( m_fp );
}

File::~File( )
{
	fclose( m_fp );
}

#define MAX_LINE_LEN 256

std::string File::GetLine( )
{
	std::string string;
	char memory[ MAX_LINE_LEN ];
	char* ret = fgets( memory, MAX_LINE_LEN, m_fp );

	if ( ret )
	{
		string = memory;
	}

	if ( string == "\n" )
	{
		string = "";
	}

	return string;
}

void File::Write( int value )
{
	fprintf( m_fp, "%d, ", value );
}

void File::Write( float value )
{
	fprintf( m_fp, "%f, ", value );
}

void File::Write( std::string value )
{
	fprintf( m_fp, "%s, ", value.c_str( ) );
}

void File::Newline( )
{
	fprintf( m_fp, "\n" );
}
