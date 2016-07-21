#include "user_struct.h"
#include "reader.h"

int main( )
{
	UserA a;
	UserB b;
	UserC c;

	a.a = 1;
	a.b = 10;

	b.a = 2;
	b.b = 20.0f;
	b.c = "twenty point zero f";

	c.a = 3;
	c.b.a = 4;
	c.b.b = 5;

	{
		File file( File::eWrite, "out.txt" );
		a.Serialize( file );
		b.Serialize( file );
		c.Serialize( file );
	}

	memset( &a, 0, sizeof( a ) );
	memset( &b, 0, sizeof( b ) );
	memset( &c, 0, sizeof( c ) );

	{
		Reader reader( "out.txt" );

		a.Deserialize( reader );
		b.Deserialize( reader );
		c.Deserialize( reader );
	}

	return 0;
}
