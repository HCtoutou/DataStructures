#include<stdio.h>
#include"List.h"
List ReverseList(List L) {//反转链表
	Position prev = NULL;
	Position q = L->Next;
	while (q) {
		Position node = q->Next;
		q->Next = prev;
		prev = q;
		q = node;
	}
	L->Next = prev;
	return L;
}
