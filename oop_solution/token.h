#if !defined( TOKEN_H )

#include <string>

class IToken
{
public:
	virtual ~IToken( );

	enum Type
	{
		eInt,
		eFloat,
		eString,
		eNone,
	};

	virtual void Get( void* memory, Type type ) = 0;

private:
	Type m_type;

protected:
	IToken( );
	friend class Reader;
};

class TokenInt : public IToken
{
public:
	virtual void Get( void* memory, Type type ) override;

private:
	int m_data;
	friend class Reader;
};

class TokenFloat : public IToken
{
public:
	virtual void Get( void* memory, Type type ) override;

private:
	float m_data;
	friend class Reader;
};

class TokenString : public IToken
{
public:
	virtual void Get( void* memory, Type type ) override;

private:
	std::string m_data;
	friend class Reader;
};

class Token
{
public:
	Token( IToken* token );
	~Token( );

	void Get( void* memory, IToken::Type type );

private:
	IToken* m_token;
};

#define TOKEN_H
#endif
