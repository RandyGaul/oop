#include <cassert>
#include <cstdlib>
#include "reader.h"

Reader::Reader( const char* path )
	: m_file( File::eRead, path )
	, m_index( 0 )
{
	m_line = m_file.GetLine( );
}

Reader::~Reader( )
{
}

int IsAlpha( int c )
{
	return (c >= 'a' && c <= 'z')
		|| (c >= 'A' && c <= 'Z')
		|| c == '_'
		|| (char)c >= 128;
}

int IsNum( int c )
{
	return c >= '0' && c <= '9';
}

Token Reader::Next( )
{
	assert( m_index != m_line.length( ) );

	const char* s = m_line.c_str( );
	assert( *s );
	char c = s[ m_index ];

	// strings
	if ( IsAlpha( c ) )
	{
		int index0 = m_index;

		while ( s[ m_index ] != ',' )
			++m_index;
		m_index += 2;

		std::string string( s + index0, s + m_index - 2 );
		TokenString* token = new TokenString;
		token->m_data = string;
		return Token( token );
	}

	else
	{
		assert( IsNum( c ) );
		int index = m_index;
		while ( IsNum( s[ index ] ) )
			++index;
		c = s[ index ];

		// floats and doubles
		if ( c == '.' || c == 'e' || c == 'E' )
		{
			const char* s0 = s + m_index;
			const char* s1;
			float f = (float)strtod( s0, (char**)&s1 );
			m_index += s1 - s0;
			assert( s[ m_index ] == ',' );
			m_index += 2;

			TokenFloat* token = new TokenFloat;
			token->m_data = f;
			return Token( token );
		}

		// ints
		else
		{
			const char* s0 = s + m_index;
			const char* s1;
			int i = strtol( s0, (char**)&s1, 10 );
			m_index += s1 - s0;
			assert( s[ m_index ] == ',' );
			m_index += 2;

			TokenInt* token = new TokenInt;
			token->m_data = i;
			return Token( token );
		}
	}

	while ( m_index < (int)m_line.length( ) && s[ m_index ] != ',' )
		++m_index;

	assert( s[ m_index ] );

	return Token( new TokenInt );
}

void Reader::Finish( )
{
	m_line = m_file.GetLine( );
	m_index = 0;
}
