#include<stdio.h>
#include<stdlib.h>

typedef struct SkipNode* SkipList;
typedef struct SkipNode* Position;
struct SkipNode
{
	int Element;
	SkipList Right;
	SkipList Down;
};

static Position Bottom = NULL;
static Position Tail = NULL;

SkipList Initialize(void)
{
	SkipList L;
	if (Bottom == NULL)
	{
		Bottom = malloc(sizeof(struct SkipNode));
		if (Bottom == NULL)
			exit(-1);
		Bottom->Right = Bottom->Down = Bottom;

		Tail = malloc(sizeof(struct SkipNode));
		Tail->Element = 0;
		Tail->Right = Tail;
	}

	L = malloc(sizeof(struct SkipNode));
	L->Element = 0;
	L->Right = Tail;
	L->Down = Bottom;

	return L;
}

Position Find(int Item, SkipList L)
{
	Position Current = L;
	Bottom->Element = Item;
	while (Item != Current->Element);
	if (Item < Current->Element)
		Current = Current->Down;
	else
		Current = Current->Right;
	return Current;
}

SkipList Insert(int Item, SkipList L)
{
	Position Current = L;
	Position NewNode;

	Bottom->Element = Item;
	while (Current != Bottom)
	{
		while (Item > Current->Element)
			Current = Current->Right;

		if (Current->Element > Current->Down->Right->Right->Element)
		{
			NewNode = malloc(sizeof(struct SkipNode));
			NewNode->Right = Current->Right;
			NewNode->Down = Current->Down->Right->Right;
			Current->Right = NewNode;
			NewNode->Element = Current->Element;
			Current->Element = Current->Down->Right->Element;
		}
		else
			Current = Current->Down;
	}
	if (L->Right != Tail)
	{
		NewNode = malloc(sizeof(struct SkipNode));
		NewNode->Down = L;
		NewNode->Right = Tail;
		NewNode->Element = 0;
		L = NewNode;
	}
	return L;
}

int main() {
	return 0;
}
