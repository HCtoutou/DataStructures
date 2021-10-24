#pragma once
struct BinNode;
struct Collection;
typedef struct Collection* BinQueue;
typedef struct BinNode* Position;
typedef struct BinNode* BinTree;

#define Capacity 4294967296
#define MaxTrees 30

BinQueue Initialize();
int IsEmpty(BinQueue H);
int IsFull(BinQueue H);
BinTree CombineTrees(BinTree T1, BinTree T2);
BinQueue Merge(BinQueue H1, BinQueue H2);
int DeleteMin(BinQueue H);
void Insert(int X, BinQueue H);
int FindMin(BinQueue H);

struct BinNode {
	int Element;
	Position LeftChild;
	Position NextSibling;
};

struct Collection {
	int CurrentSize;
	BinTree TheTrees[MaxTrees];
};
