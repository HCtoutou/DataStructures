#pragma once
struct TreeNode;
typedef struct TreeNode* PtrToNode;
typedef PtrToNode Tree;
Tree Creat();
void PreOrder(Tree T);//前序遍历
void InOrder(Tree T);//中序遍历
void PostOrder(Tree T);//后序遍历
int Height(Tree T);
void Leaf(Tree T);
struct TreeNode {
	char Element;
	Tree Left;
	Tree Right;
};
