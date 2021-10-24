#include<stdio.h>
#include<stdlib.h>
#include"BinQueue.h"

BinQueue Initialize() {
	//BinQueue H = malloc(sizeof(struct Collection));

	BinQueue H = (BinQueue)calloc(1, sizeof(struct Collection));
	if (H == NULL) {
		printf("Out of space\n");
		exit(1);
	}
	H->CurrentSize = 0;
	return H;
}

int IsEmpty(BinQueue H) {
	return H->CurrentSize == NULL;
}

int IsFull(BinQueue H) {
	return H->CurrentSize == MaxTrees;
}

BinTree CombineTrees(BinTree T1, BinTree T2){
	if (T1->Element > T2->Element)
		return CombineTrees(T2, T1);
	T2->NextSibling = T1->LeftChild;
	T1->LeftChild = T2;
	return T1;
}

BinQueue Merge(BinQueue H1, BinQueue H2) {
	BinTree T1, T2, Carry = NULL;
	int i, j;

	if (H1->CurrentSize + H2->CurrentSize > Capacity)
		printf("Merge would exceed capacity\n");
	H1->CurrentSize += H2->CurrentSize;
	for (i = 0, j = 1; j <= H1->CurrentSize; i++, j *= 2) {
		T1 = H1->TheTrees[i];
		T2 = H2->TheTrees[i];
		switch (!!T1 + 2 * !!T2 + 4 * !!Carry) {
		case 0:/*No trees*/
		case 1:/*Only H1*/
			break;
		case 2:/*Only H2*/
			H1->TheTrees[i] = T2;
			H2->TheTrees[i] = NULL;
			break;
		case 4:/*Only Carry*/
			H1->TheTrees[i] = Carry;
			Carry = NULL;
			break;
		case 3:/*H1 and H2*/
			Carry = CombineTrees(T1, T2);
			H1->TheTrees[i] = H2->TheTrees[i] = NULL;
			break;
		case 5:/*H1 and Carry*/
			Carry = CombineTrees(T1, Carry);
			H1->TheTrees[i] = NULL;
			break;
		case 6:/*H2 and Carry*/
			Carry = CombineTrees(T2, Carry);
			H2->TheTrees[i] = NULL;
			break;
		case 7:/*All three*/
			H1->TheTrees[i] = Carry;
			Carry = CombineTrees(T1, T2);
			H2->TheTrees[i] = NULL;
			break;
		}
	}
	return H1;
}

int FindMin(BinQueue H) {
	int i, min;
	int MinValue = 0x7fffffff;

	if (IsEmpty(H))
		return NULL;

	for (i = 0; i < MaxTrees; i++) {
		if(H->TheTrees[i])
			if (H->TheTrees[i]->Element < MinValue) {
				MinValue = H->TheTrees[i]->Element;
				min = i;
			}
	}
	return MinValue;
}

int DeleteMin(BinQueue H) {
	int i, j;
	int MinTree;	/*The tree with the miniimum item*/
	BinQueue DeletedQueue;
	Position DeletedTree, OldRoot;
	int MinItem;

	if (IsEmpty(H)) {
		printf("Empty binomial queue\n");
		return -0x7fffffff;
	}

	MinItem = 0x7fffffff;
	for (i = 0; i < MaxTrees; i++) {
		if (H->TheTrees[i] && H->TheTrees[i]->Element < MinItem) {
			MinItem = H->TheTrees[i]->Element;
			MinTree = i;
		}
	}
	DeletedTree = H->TheTrees[MinTree];
	OldRoot = DeletedTree;
	DeletedTree = DeletedTree->LeftChild;
	free(OldRoot);

	DeletedQueue = Initialize();
	DeletedQueue->CurrentSize = (1 << MinTree) - 1;
	for (j = MinTree - 1; j >= 0; j--) {
		DeletedQueue->TheTrees[j] = DeletedTree;
		DeletedTree = DeletedTree->NextSibling;
		DeletedQueue->TheTrees[j]->NextSibling = NULL;
	}

	H->TheTrees[MinTree] = NULL;
	H->CurrentSize -= DeletedQueue->CurrentSize + 1;

	Merge(H, DeletedQueue);
	return MinItem;
}

void Insert(int X, BinQueue H) {
	BinQueue Temp = Initialize();
	BinTree NewNode = malloc(sizeof(struct BinNode));
	if (NewNode == NULL) {
		printf("Out of space\n");
		exit(1);
	}

	NewNode->Element = X;
	NewNode->LeftChild = NewNode->NextSibling = NULL;

	Temp->CurrentSize = 1;
	Temp->TheTrees[0] = NewNode;

	Merge(H, Temp);
	free(Temp);
}

int main() {
	BinQueue H;
	H = Initialize();
	Insert(2, H);
	Insert(3, H);
	Insert(16, H);
	Insert(10, H);
	Insert(50, H);
	Insert(11, H);
	Insert(13, H);
	printf("%d\n", FindMin(H));
	DeleteMin(H);
	printf("%d\n", FindMin(H));
	return 0;
}
