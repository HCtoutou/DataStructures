#include<stdio.h>
#include<stdlib.h>
#include"RedBlackTree.h"

static void DoPrint(RedBlackTree T)
{
	if (T != NullNode)
	{
		DoPrint(T->Left);
		printf("%d\n", T->Element);
		DoPrint(T->Right);
	}
}

void PrtinTree(RedBlackTree T)
{
	DoPrint(T->Right);
}

RedBlackTree Initialize(void)
{
	RedBlackTree T;
	if (NullNode == NULL)
	{
		NullNode == malloc(sizeof(struct RedBlackNode));

		NullNode->Left = NullNode->Right = NullNode;
		NullNode->Color = Black;
		NullNode->Element = 0;
	}
	T = malloc(sizeof(struct RedBlackNode));
	
	T->Element = 0; //NegInfinity
	T->Left = T->Right = NullNode;
	T->Color = Black;
	return T;
}

static Position Rotate(int Item, Position Parent)
{
	if (Item < Parent->Element)
		return Parent->Left = Item < Parent->Left->Element ? LeftSingleRotate(Parent->Left) : RightSingleRotate(Parent->Left);
	else
		return Parent->Right = Item < Parent->Right->Element ? LeftSingleRotate(Parent->Right) : RightSingleRotate(Parent->Right);
}

static Position X, P, GP, GGP;
static void HandleReorient(int Item, RedBlackTree T)
{
	X->Color = Red;
	X->Left->Color = Black;
	X->Right->Color = Black;

	if (P->Color == Red)
	{
		GP->Color = Red;
		if ((Item < GP->Element) != (Item < P->Element))
			P = Rotate(Item, GP);
		X = Rotate(Item, GGP);
		X->Color = Black;
	}
	T->Right->Color = Black;
}

RedBlackTree Insert(int Item, RedBlackTree T)
{
	X = P = GP = T;
	NullNode->Element = Item;
	while (X->Element != Item)
	{
		GGP = GP; GP = P; P = X;
		if (Item < X->Element)
			X = X->Left;
		else
			X = X->Right;
		if (X->Left->Color == Red && X->Right->Color == Red)
			HandleReorient(Item, T);
	}
	if (X != NullNode)
		return NullNode;
	X = malloc(sizeof(struct RedBlackNode));

	X->Element = Item;
	X->Left = X->Right = NullNode;

	if (Item < P->Element)
		P->Left = X;
	else
		P->Right = X;
	HandleReorient(Item, T);

	return T;
}

/*右旋转*/
RedBlackTree RightSingleRotate(Position T)
{
	RedBlackTree k1;

	k1 = T->Left;
	T->Left = k1->Right;
	k1->Right = T;
	return k1;
}

/*左旋转*/
RedBlackTree LeftSingleRotate(Position k1)
{
	Position k2;

	k2 = k1->Right;
	k1->Right = k2->Left;
	k2->Left = k1;
	return k2;
}

int main()
{
	return 0;
}
