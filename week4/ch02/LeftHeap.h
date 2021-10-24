#pragma once
struct TreeNode;
typedef struct TreeNode* PriorityQueue;

int FindMin(PriorityQueue H);
int IsEmpty(PriorityQueue H);
PriorityQueue Merge(PriorityQueue H1, PriorityQueue H2);
static PriorityQueue Merge1(PriorityQueue H1, PriorityQueue H2);
static void SwapChildren(PriorityQueue H);

#define Insert(X,H)(H=Insert1((X),H));
PriorityQueue Insert1(int X, PriorityQueue H);

#define DeleteMin(H)(H=DeleteMin1(H));
PriorityQueue DeleteMin1(PriorityQueue H);

struct TreeNode {
	int Element;
	PriorityQueue Left;
	PriorityQueue Right;
	int Npl;
};
