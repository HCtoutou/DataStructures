#include<stdio.h>
#include<stdlib.h>
#include"BinHeap.h"
int MinData=-100;

int IsFull(PriorityQueue H) {
	if (H->Capacity == H->Size)
		return 1;
	else
		return 0;
}

int IsEmpty(PriorityQueue H) {
	if ( H->Size==0)
		return 1;
	else
		return 0;
}

PriorityQueue Initialize(int MaxElements) {
	PriorityQueue H;

	if (MaxElements < 3)
		printf("Priority queue size is too small\n");
	H = malloc(sizeof(struct HeapStruct));
	if (H == NULL)
		printf("Out of space\n");

	H->Element = malloc((MaxElements + 1) * sizeof(int));
	if (H->Element == NULL)
		printf("Out of space\n");

	H->Capacity = MaxElements;
	H->Size = 0;
	H->Element[0] = MinData;

	return H;
}

void Insert(int X, PriorityQueue H) {//插入
	int i;

	if (IsFull(H)) {
		printf("Priority queue is full\n");
		return;
	}

	for (i = ++H->Size; H->Element[i / 2] > X; i /= 2)//若i节点的根节点的值大于X
		H->Element[i] = H->Element[i / 2];//则将i节点的根节点下滤
	H->Element[i] = X;//将X填入合适的i位置
}

int DeleteMin(PriorityQueue H) {//拿出最小值
	int i, Child;
	int MinElement, LastElement;

	if (IsEmpty(H)) {
		printf("Priority queue is empty\n");
		return H->Element[0];
	}
	MinElement = H->Element[1];
	LastElement = H->Element[H->Size--];
	for (i = 1; i * 2 <= H->Size; i = Child) {
		/*Find smaller child*/
		Child = i * 2;
		if (Child != H->Size && H->Element[Child + 1] < H->Element[Child])
			Child++;

		if (LastElement > H->Element[Child])
			H->Element[i] = H->Element[Child];
		else
			break;
	}
	H->Element[i] = LastElement;
	return MinElement;
}

void DecreaseKey(int Size, int num, PriorityQueue H) {//降低关键字的值
	int i;
	num = H->Element[Size] - num;
	for (i = Size; num < H->Element[i / 2]; i /= 2)
		H->Element[i] = H->Element[i / 2];//将i节点的根节点下滤，i节点上滤
	H->Element[i] = num;//将X填入合适的i位置
}

void IncreaseKey(int Size, int X, PriorityQueue H) {//增加关键字的值
	int i, Child;
	int NewElement;

	NewElement = H->Element[Size] + X;
	for (i = Size; i * 2 < H->Size;i=Child) {
		Child = i * 2;
		if (Child != H->Size && H->Element[Child + 1] < H->Element[Child])//找出两个儿子中较小的一个，返回其位置
			Child = Child + 1;
		if (H->Element[Child] < NewElement)
			H->Element[i] = H->Element[Child];
		else
			break;
	}
	H->Element[i] = NewElement;
}

int main() {
	PriorityQueue H;
	H=Initialize(20);
	Insert(1, H);
	Insert(5, H);
	Insert(2, H);
	Insert(7, H);
	Insert(20, H);
	printf("%d\n",DeleteMin(H));
	DecreaseKey(2, 4, H);
	printf("%d\n", H->Element[1]);
	IncreaseKey(1, 4, H);
	printf("%d\n", H->Element[1]);
	return 0;
}
