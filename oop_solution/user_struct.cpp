#include <cassert>
#include "file.h"
#include "reader.h"
#include "user_struct.h"

void UserA::Serialize( File& file ) const
{
	file.Write( a );
	file.Write( b );
	file.Newline( );
}

void UserA::Deserialize( Reader& reader )
{
	reader.Next( ).Get( &a, IToken::eInt );
	reader.Next( ).Get( &b, IToken::eInt );
	reader.Finish( );
}

void UserB::Serialize( File& file ) const
{
	file.Write( a );
	file.Write( b );
	file.Write( c );
	file.Newline( );
}

void UserB::Deserialize( Reader& reader )
{
	reader.Next( ).Get( &a, IToken::eInt );
	reader.Next( ).Get( &b, IToken::eFloat );
	reader.Next( ).Get( &c, IToken::eString );
	reader.Finish( );
}

void UserC::Serialize( File& file ) const
{
	file.Write( a );

	UserA temp;
	temp.a = b.a;
	temp.b = b.b;

	temp.Serialize( file );
	file.Newline( );
}

void UserC::Deserialize( Reader& reader )
{
	reader.Next( ).Get( &a, IToken::eInt );
	UserA temp;
	temp.Deserialize( reader );
	b = temp;
	reader.Finish( );
}
