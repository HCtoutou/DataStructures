修改
#include<stdio.h>
#include<stdlib.h>
#include"List.h"

Position Creat(int n) {
	Position head, node, end;
	head = malloc(sizeof(struct Node));
  if(head==NULL)
    exit(0);
	end = head;
	printf("%d\n", head->Element);
	for (int i = 0; i < n; i++) {
		node = malloc(sizeof(struct Node));
		node->Element = i;
		end->Next = node;
		end = node;
	}
	end->Next = NULL;
	return head;
}

void Show(List L) {
	Position node;
	node = L->Next;
	while (node != NULL) {
		printf("%d\n", node->Element);
		node = node->Next;
	}
}
int IsEmpty(List L) {//判断链表是否为空
	return L->Next == NULL;
}
int IsLast(Position P, List L) {//判断当前是否为最后一个元素
	return P->Next == NULL;
}

Position Find(int X, List L) {//查找
	Position P;
	P = L->Next;
	while (P != NULL && P->Element != X)
		P = P->Next;
	return P;
}

Position FindPrevious(int X, List L) {
	Position P;
	P = L;
	while (P->Next != NULL && P->Next->Element != X) {
		P = P->Next;
	}
	return P;
};

void Delete(int X, List L) {
	Position P, TmpCell;
	P = FindPrevious(X, L);
	if (!IsLast(P, L)) {
		TmpCell = P->Next;
		P->Next = TmpCell->Next;
		free(TmpCell);
	}
}

void Insert(int X, List L, Position P) {//插入操作（插入到P的后面）
	Position TmpCell;
	TmpCell = malloc(sizeof(struct Node));
	if (TmpCell == NULL)//节点申请失败
		exit(0);
	TmpCell->Element = X;
	TmpCell->Next = P->Next;
	P->Next = TmpCell;
}
void DeleteList(List L) {//销毁链表
	Position p;
	while (L->Next) {
		p = L->Next;
		L->Next = p->Next;
		free(p);
	}
	free(L);
}

int main() {
	Position p;
	p = Creat(5);//未给初始的头结点赋值，其为一个随机的数
	Show(p);
	printf("\n");
	Insert(10, p, Find(3, p));
	Show(p);
	printf("\n");
	Delete(2, p);
	Show(p);
}
