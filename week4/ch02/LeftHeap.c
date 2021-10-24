#include<stdio.h>
#include<stdlib.h>
#include"LeftHeap.h"

int IsEmpty(PriorityQueue H) {
	return H->Left == NULL && H->Right->Right == NULL;
}
PriorityQueue Merge(PriorityQueue H1, PriorityQueue H2) {
	if (H1 == NULL)
		return H2;
	if (H2 == NULL)
		return H1;
	if (H1->Element < H2->Element)
		return Merge1(H1, H2);
	else
		return Merge1(H2, H1);
}

static PriorityQueue Merge1(PriorityQueue H1, PriorityQueue H2) {
	if (H1->Left == NULL)
		H1->Left = H2;
	else {
		H1->Right = Merge(H1->Right, H2);
		if (H1->Left->Npl < H1->Right->Npl)
			SwapChildren(H1);

		H1->Npl = H1->Right->Npl + 1;
	}
	return H1;
}

static void SwapChildren(PriorityQueue H) {
	PriorityQueue node;
	node = H->Left;
	H->Left = H->Right;
	H->Right = node;
}

PriorityQueue Insert1(int X, PriorityQueue H) {
	PriorityQueue SingleNode;

	SingleNode = malloc(sizeof(struct TreeNode));
	if (SingleNode == NULL)
		printf("Out of space!!!\n");
	else {
		SingleNode->Element = X;
		SingleNode->Npl = 0;
		SingleNode->Left = SingleNode->Right = NULL;
		H = Merge(SingleNode , H);
	}
	return H;
}

int FindMin(PriorityQueue H) {
	return H->Element;
}

PriorityQueue DeleteMin1(PriorityQueue H) {
	PriorityQueue LeftHeap, RightHeap;

	if (IsEmpty(H)) {
		printf("Priority queue is empty\n");
		return H;
	}

	LeftHeap = H->Left;
	RightHeap = H->Right;
	free(H);
	return Merge(LeftHeap, RightHeap);
}



int main() {
	PriorityQueue H1 = NULL;
	Insert(1, H1);
	Insert(5, H1);
	Insert(10,H1);
	Insert(6, H1);
	Insert(2, H1);
	DeleteMin(H1);
	return 0;
}
