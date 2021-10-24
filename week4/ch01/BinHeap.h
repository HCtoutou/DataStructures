#pragma once

struct HeapStruct;
typedef struct HeapStruct* PriorityQueue;

PriorityQueue Initialize(int MaxElements);
void Destory(PriorityQueue H);
void MakeEmpty(PriorityQueue H);
void Insert(int X, PriorityQueue H);
int DeleteMin(PriorityQueue H);
int FindMin(PriorityQueue H);
int IsEmpty(PriorityQueue H);
int IsFull(PriorityQueue H);
void DecreaseKey(int Size, int X, PriorityQueue H);//降低关键字的值
void IncreaseKey(int Size, int X, PriorityQueue H);//增加关键字的值


struct HeapStruct {
	int Capacity;
	int Size;
	int* Element;
};
