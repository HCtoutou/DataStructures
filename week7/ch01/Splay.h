#pragma once
struct SplayNode;
typedef struct SplayNode* SplayTree;

SplayTree MakeEmpty(SplayTree T);
SplayTree Find(int X, SplayTree T);
SplayTree FindMin(SplayTree T);
SplayTree FindMax(SplayTree T);
SplayTree Initialize(void);
SplayTree Insert(int X, SplayTree T);
SplayTree Remove(int X, SplayTree T);
int Retrieve(SplayTree T);

struct SplayNode
{
	int Element;
	SplayTree Left;
	SplayTree Right;
};

typedef struct SplayNode* Position;
SplayTree RightSingleRotate(Position T);
SplayTree LeftSingleRotate(Position k1);
static Position NullNode = NULL;
