#include<stdio.h>
#include<stdlib.h>
#include"Splay.h"

SplayTree Initialize(void)
{
	if (NullNode == NULL)
	{
		NullNode = malloc(sizeof(struct SplayNode));
		if (NullNode == NULL)
			exit(-1);
		NullNode->Left = NullNode->Right = NullNode;
	}
	return NullNode;
}

SplayTree Splay(int Item, Position X)
{
	static struct SplayNode Header;
	Position LeftTreeMax, RightTreeMin;

	Header.Left = Header.Right = NullNode;
	LeftTreeMax = RightTreeMin = &Header;
	NullNode->Element = Item;

	while (Item != X->Element)
	{
		if (Item < X->Element)
		{
			if (Item < X->Left->Element)
				X = LeftSingleRotate(X);
			if (X->Left == NullNode)
				break;
			RightTreeMin->Left = X;
			RightTreeMin = X;
			X = X->Left;
		}
		else
		{
			if (Item > X->Right->Element)
				X = RightSingleRotate(X);
			if (X->Right == NullNode)
				break;
			LeftTreeMax->Right = X;
			LeftTreeMax = X;
			X = X->Right;
		}
	}
	LeftTreeMax->Right = X->Left;
	RightTreeMin->Left = X->Right;
	X->Left = Header.Right;
	X->Right = Header.Left;

	return X;
}

SplayTree Insert(int Item, SplayTree T)
{
	static Position NewNode = NULL;

	if (NewNode == NULL)
	{
		NewNode = malloc(sizeof(struct SplayNode));
		if (NewNode == NULL)
			exit(-1);
	}
	NewNode->Element = Item;

	if (T == NullNode)
	{
		NewNode->Left = NewNode->Right = NullNode;
		T = NewNode;
	}
	else
	{
		T = Splay(Item, T);
		if (Item < T->Element)
		{
			NewNode->Left = T->Left;
			NewNode->Right = T;
			T->Left = NullNode;
			T = NewNode;
		}
		else if (T->Element < Item)
		{
			NewNode->Right = T->Right;
			NewNode->Left = T;
			T->Right = NullNode;
			T = NewNode;
		}
		else
			return T;
	}
	NewNode = NULL;
	return T;
}

SplayTree Remove(int Item, SplayTree T)
{
	Position NewTree;
	if (T != NullNode)
	{
		T = Splay(Item, T);
		if (Item == T->Element)
		{
			if (T->Left == NullNode)
				NewTree = T->Right;
			else
			{
				NewTree = T->Left;
				NewTree = Splay(Item, NewTree);
				NewTree->Right = T->Right;
			}
			free(T);
			T = NewTree;
		}
	}
	return T;
}


/*右旋转*/
SplayTree RightSingleRotate(Position T)
{
	SplayTree k1;

	k1 = T->Left;
	T->Left = k1->Right;
	k1->Right = T;
	return k1;
}

/*左旋转*/
SplayTree LeftSingleRotate(Position k1)
{
	Position k2;

	k2 = k1->Right;
	k1->Right = k2->Left;
	k2->Left = k1;
	return k2;
}

SplayTree FindMin(SplayTree T)
{
	Position np = T;
	if (T != NULL)
	{
		while (np->Left != NULL)
			np = np->Left;

		return Splay(np, T);
	}
	return NULL;
}

SplayTree FindMax(SplayTree T)
{
	Position np = T;
	if (T != NULL)
	{
		while (np->Right != NULL)
			np = np->Right;

		return Splay(np, T);
	}
	return NULL;
}


int main()
{
	return 0;
}
