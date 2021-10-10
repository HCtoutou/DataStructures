#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include"AvlTree.h"

static int Height(Position P) {
	if (P == NULL)
		return -1;
	else
		return P->Height;
}

AvlTree MakeEmpty(AvlTree T) {
	if (T != NULL) {
		MakeEmpty(T->Left);
		MakeEmpty(T->Right);
		free(T);
	}
	return NULL;
}
Position FindMin(AvlTree T) {
	if (T == NULL)
		return NULL;
	else if (T->Left == NULL)
		return T;
	else
		return FindMin(T->Left);
}

Position FindMax(AvlTree T) {
	if (T == NULL)
		return NULL;
	else
		while (T->Right != NULL)
			T = T->Right;
	return T;
}

Position Find(int X, AvlTree T) {
	if (T == NULL)
		return NULL;
	else if (X > T->Element)
		return Find(X, T->Right);
	else if (X < T->Element)
		return Find(X, T->Left);
	else
		return T;
}

AvlTree Delete(int X, AvlTree T) {
	Position TmpCell;
	if (T == NULL)
		printf("Element not found");
	else if (X < T->Element)
		T->Left = Delete(X, T->Left);
	else if (X > T->Element)
		T->Right = Delete(X, T->Left);
	else if (T->Left && T->Right) {
		TmpCell = FindMin(T->Right);
		T->Element = TmpCell->Element;
		T->Right = Delete(T->Element, T->Right);
	}
	else {
		TmpCell = T;
		if (T->Left == NULL)
			T = T->Right;
		else if (T->Right == NULL)
			T = T->Left;
		free(TmpCell);
	}
	return T;
}
AvlTree Insert(int X, AvlTree T) {
	if (T == NULL) {
		T = malloc(sizeof(struct AvlNode));
		if (T == NULL)
			printf("error\n");
		else {
			T->Element = X;
			T->Height = 0;
			T->Left = T->Right = NULL;
		}
	}
	else if (X < T->Element) {
		T->Left = Insert(X, T->Left);
		if (Height(T->Left) - Height(T->Right) == 2)
			if (X < T->Left->Element)
				T = SingleRotateWithLeft(T);
			else
				T = DoubleRotateWithLeft(T);
	}
	else if (X > T->Element) {
		T->Right = Insert(X, T->Right);
		if (Height(T->Right) - Height(T->Left) == 2)
			if (X > T->Right->Element)
				T = SingleRotateWithRight(T);
			else
				T = DoubleRotateWithRight(T);
	}
	T->Height = fmax(Height(T->Left), Height(T->Right)) + 1;
	return T;
}

static Position SingleRotateWithLeft(Position K2) {
	Position K1;
	K1 = K2->Left;
	K2->Left = K1->Right;
	K1->Right = K2;
	K2->Height = fmax(Height(K2->Left), Height(K2->Right) ) + 1;
	K1->Height = fmax(Height(K1->Left), K2->Height) + 1;
	return K1;
}

static Position SingleRotateWithRight(Position K4) {
	Position K5;
	K5 = K4->Right;
	K4->Right = K5->Left;
	K5->Left = K4;
	K4->Height = fmax(Height(K4->Left), Height(K4->Right)) + 1;
	K5->Height = fmax(Height(K5->Right), K4->Height) + 1;
	return K5;
}

static Position DoubleRotateWithLeft(Position K3) {
	K3->Left = SingleRotateWithRight(K3->Left);
	return SingleRotateWithLeft(K3);
}

static Position DoubleRotateWithRight(Position K6) {
	K6->Right = SingleRotateWithLeft(K6->Right);
	return SingleRotateWithRight(K6);
}

int main() {
	AvlTree T = NULL;
	MakeEmpty(T);
	T = Insert(2, T);
	T = Insert(1, T);
	T = Insert(5, T);
	T = Insert(3, T);
	T = Insert(6, T);
	T = Insert(7, T);
	Position max, min;
	max = FindMax(T);
	min = FindMin(T);
	printf("%d\n", max->Element);
	printf("%d\n", min->Element);
	T = Delete(1, T);
	min = FindMin(T);
	printf("%d\n", min->Element);
	return 0;
}
