#include <cstdio>
#include <cstring>
#include "../struct.h"

void Write( FILE* fp, int a )
{
	fprintf( fp, "%d, ", a );
}

void Write( FILE* fp, float a )
{
	fprintf( fp, "%f, ", a );
}

void Write( FILE* fp, char* a )
{
	fprintf( fp, "%s, ", a );
}

void Read( FILE* fp, int* a )
{
	fscanf( fp, "%d, ", a );
}

void Read( FILE* fp, float* a )
{
	fscanf( fp, "%f, ", a );
}

void Read( FILE* fp, char** a )
{
	char buffer[ 1024 ];
	fscanf( fp, "%[^,], ", buffer );
	*a = strdup( buffer ); // mem leak, oh well
}

void Newline( FILE* fp )
{
	fprintf( fp, "\n" );
}

void Serialize( FILE* fp, const A& a )
{
	Write( fp, a.a );
	Write( fp, a.b );
	Newline( fp );
}

void Serialize( FILE* fp, const B& b )
{
	Write( fp, b.a );
	Write( fp, b.b );
	Write( fp, b.c );
	Newline( fp );
}

void Serialize( FILE* fp, const C& c )
{
	Write( fp, c.a );
	Serialize( fp, c.b );
	Newline( fp );
}

void Deserialize( FILE* fp, A& a )
{
	Read( fp, &a.a );
	Read( fp, &a.b );
}

void Deserialize( FILE* fp, B& b )
{
	Read( fp, &b.a );
	Read( fp, &b.b );
	Read( fp, &b.c );
}

void Deserialize( FILE* fp, C& c )
{
	Read( fp, &c.a );
	Deserialize( fp, c.b );
}

int main( )
{
	FILE* fp = fopen( "out.txt", "w" );
	A a;
	B b;
	C c;

	a.a = 1;
	a.b = 10;

	b.a = 2;
	b.b = 20.0f;
	b.c = "twenty point zero f";

	c.a = 3;
	c.b.a = 4;
	c.b.b = 5;

	Serialize( fp, a );
	Serialize( fp, b );
	Serialize( fp, c );

	memset( &a, 0, sizeof( a ) );
	memset( &b, 0, sizeof( b ) );
	memset( &c, 0, sizeof( c ) );

	fclose( fp );
	fp = fopen( "out.txt", "r" );

	Deserialize( fp, a );
	Deserialize( fp, b );
	Deserialize( fp, c );
	
	fclose( fp );

	return 0;
}
