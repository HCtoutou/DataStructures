#pragma once
typedef enum ColorType{Red,Black}ColorType;

struct RedBlackNode;
typedef struct RedBlackNode* RedBlackTree;
typedef struct RedBlackNode* Position;
RedBlackTree Initialize(void);
RedBlackTree Insert(int Item, RedBlackTree T);
static void HandleReorient(int Item, RedBlackTree T);
RedBlackTree RightSingleRotate(Position T);
RedBlackTree LeftSingleRotate(Position k1);
struct RedBlackNode
{
	int Element;
	RedBlackTree Left;
	RedBlackTree Right;
	ColorType Color;
};

Position NullNode = NULL;
