#pragma once
typedef struct ElemAtom {
	int id;
	char *name;
}ElemAtom;

typedef enum{ATOM, LIST} ElemTag;
typedef struct GLNode 
{
	ElemTag Tag;
	union 
	{
		ElemAtom atom;
		struct 
		{
			struct GLNode *head;
			struct GLNode *tail;
		}list;
	};
}GList;