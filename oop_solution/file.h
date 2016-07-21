#if !defined( FILE_H )

#include <cstdio>
#include <string>

class File
{
public:
	enum Mode
	{
		eRead,
		eWrite
	};

	File( Mode mode, const char* path );
	~File( );
	
	std::string GetLine( );
	void Write( int value );
	void Write( float value );
	void Write( std::string value );
	void Newline( );

private:
	FILE* m_fp;
};

#define FILE_H
#endif
