#if !defined( USER_STRUCT_H )

#include "../struct.h"
#include "serializeable.h"

class File;

struct UserA : public A, public ISerializeable
{
	virtual void Serialize( File& file ) const override;
	virtual void Deserialize( Reader& reader ) override;
};

struct UserB : public B, public ISerializeable
{
	virtual void Serialize( File& file ) const override;
	virtual void Deserialize( Reader& reader ) override;
};

struct UserC : public C, public ISerializeable
{
	virtual void Serialize( File& file ) const override;
	virtual void Deserialize( Reader& reader ) override;
};

#define USER_STRUCT_H
#endif
