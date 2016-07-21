#if !defined( STRUCT_H )

struct A
{
	int a;
	int b;
};

struct B
{
	int a;
	float b;
	char* c;
};

struct C
{
	int a;
	A b;
};

#define STRUCT_H
#endif
