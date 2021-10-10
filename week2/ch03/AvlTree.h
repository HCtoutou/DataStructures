#pragma once
struct AvlNode;
typedef struct AvlNode* Position;
typedef struct AvlNode* AvlTree;

AvlTree MakeEmpty(AvlTree T);
Position Find(int X, AvlTree T);
Position FindMin(AvlTree T);
Position FindMax(AvlTree T);
AvlTree Insert(int X, AvlTree T);
AvlTree Delete(int X, AvlTree T);
static Position SingleRotateWithLeft(Position K2);
static Position SingleRotateWithRight(Position K4);
static Position DoubleRotateWithLeft(Position K3);
static Position DoubleRotateWithRight(Position K6);

struct AvlNode {
	int Element;
	AvlTree Left;
	AvlTree Right;
	int Height;
};
