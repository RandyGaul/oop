#if !defined( SERIALIZEABLE_H )

class File;
class Reader;

class ISerializeable
{
public:
	virtual void Serialize( File& file ) const = 0;
	virtual void Deserialize( Reader& reader ) = 0;
};

#define SERIALIZEABLE_H
#endif
