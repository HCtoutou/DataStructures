#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include"Tree.h"
SearchTree MakeEmpty(SearchTree T) {
	if (T != NULL) {
		MakeEmpty(T->Left);
		MakeEmpty(T->Right);
		free(T);
	}
	return NULL;
}
Position Find(int X, SearchTree T) {
	if (T == NULL)
		return NULL;
	if (X < T->Element)
		return Find(X, T->Left);
	else if (X > T->Element)
		return Find(X, T->Right);
	else
		return T;
}

Position FindMin(SearchTree T) {
	if (T == NULL)
		return NULL;
	else if (T->Left == NULL)
		return T;
	else
		return FindMin(T->Left);
}
Position FindMax(SearchTree T) {
	if (T != NULL)
		while (T->Right != NULL)
			T = T->Right;
	return T;
}
SearchTree Insert(int X, SearchTree T) {
	if (T == NULL) {
		T = (struct TreeNode*)malloc(sizeof(struct TreeNode));
		if (T == NULL)
			exit(0);
		else {
			T->Element = X;
			T->Left = T->Right = NULL;
		}
	}
	else if (X < T->Element)
		T->Left = Insert(X, T->Left);
	else if (X > T->Element)
		T->Right = Insert(X, T->Right);
	//else x is in the tree already;we will do nothing
	return T;
}
SearchTree Delete(int X, SearchTree T) {
	Position TmpCell;
	if (T == NULL)
		printf("Element not found");
	else if (X < T->Element)
		T->Left = Delete(X, T->Left);
	else if (X > T->Element)
		T->Right = Delete(X, T->Left);
	else if (T->Left && T->Right) {
		//replace with smallest in right subtree
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

int main() {
	SearchTree T=NULL;
	MakeEmpty(T);
	T=Insert(2, T);
	T=Insert(1, T);
	T=Insert(5, T);
	T=Insert(3, T);
	Position max,min;
	max = FindMax(T);
	min = FindMin(T);
	printf("%d\n", max->Element);
	printf("%d\n", min->Element);
	T = Delete(1, T);
	min = FindMin(T);
	printf("%d\n", min->Element);
	return 0;
}
