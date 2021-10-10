#include<stdio.h>
#include<stdlib.h>
#include"Tree.h"
int main() {
	Tree T;
	T=Creat();
	printf("前序遍历:");
	PreOrder(T);
	printf("\n");
	printf("中序遍历:");
	InOrder(T);
	printf("\n");
	printf("后序遍历:");
	PostOrder(T);
	printf("\n");
	printf("树高:%d\n", Height(T));
	printf("叶子节点:");
	Leaf(T);
}

Tree Creat(){
	char ch;
	Tree  T;
	printf("please input the number:");
	scanf(" %c", &ch);
	if (ch == '#') {
		T = NULL;
	}
	else {
		T =(Tree)malloc(sizeof(struct TreeNode));
		if (T == NULL) {
			printf("error\n");
			exit(1);
		}
		T->Element = ch;
		T->Left=Creat();
		T->Right=Creat();
	}
	return T;
}

void PreOrder(Tree T) {
	if (T == NULL)//递归结束条件
		return;
	else {
		printf("%c", T->Element);
		PreOrder(T->Left);
		PreOrder(T->Right);
	}
}

void InOrder(Tree T) {
	if (T == NULL)//递归结束条件
		return;
	else {
		InOrder(T->Left);
		printf("%c", T->Element);
		InOrder(T->Right);
	}
}

void PostOrder(Tree T) {
	if (T == NULL)
		return;
	else {
		PostOrder(T->Left);
		PostOrder(T->Right);
		printf("%c",T->Element);
	}
}

int Height(Tree T) {
	if (T == NULL)
		return 0;
	int Left_Height = Height(T->Left);
	int Right_Height = Height(T->Right);
	return (Left_Height > Right_Height) ? (Left_Height + 1) : (Right_Height + 1);
}

void Leaf(Tree T) {
	if (T == NULL)
		return;
	else {
		if (T->Left == NULL && T->Right == NULL)
			printf("%c", T->Element);
		Leaf(T->Left);
		Leaf(T->Right);
	}
}
