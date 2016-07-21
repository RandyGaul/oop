#include <cassert>
#include "token.h"

IToken::IToken( )
	: m_type( eNone )
{
}

IToken::~IToken( )
{
}

void TokenInt::Get( void* memory, Type type )
{
	assert( type == eInt );
	int* int_memory = static_cast< int* >( memory );
	*int_memory = m_data;
}

void TokenFloat::Get( void* memory, Type type )
{
	assert( type == eFloat );
	float* float_memory = static_cast< float* >( memory );
	*float_memory = m_data;
}

void TokenString::Get( void* memory, Type type )
{
	assert( type == eString );
	char** string = static_cast< char** >( memory );
	*string = strdup( m_data.c_str( ) ); // mem leak, oh well
}

Token::Token( IToken* token )
	: m_token( token )
{
}

Token::~Token( )
{
	delete m_token;
	m_token = 0;
}

void Token::Get( void* memory, IToken::Type type )
{
	m_token->Get( memory, type );
}
