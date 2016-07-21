#if !defined( READER_H )

#include "token.h"
#include "file.h"

class Reader
{
public:
	Reader( const char* path );
	~Reader( );

	Token Next( );
	void Finish( );

private:
	File m_file;

	int m_index;
	std::string m_line;
};

#define READER_H
#endif
