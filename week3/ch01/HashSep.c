#include<stdio.h>
#include<stdlib.h>
#include"HashSep.h"


int Hash(int Key, int TableSize) {
	return Key % TableSize;
}

HashTable InitializeTable(int TableSize) {
	HashTable H;
	int i;

	if (TableSize < 7) {
		printf("Table size too small\n");
		return NULL;
	}

	/*Alloc table*/
	H = malloc(sizeof(struct HashTbl));
	if (H == NULL)
		printf("Out of space!!\n");
	/*设置表的大小为一素数*/
	//H->TableSize = NextPrime(TableSize);
	H->TableSize = TableSize;

	/*Alloc array of list*/
	H->TheLists = malloc(sizeof(List) * H->TableSize);
	if (H->TheLists == NULL)
		printf("Out of space!!");

	/*Allocte list headers*/
	for (i = 0; i < H->TableSize; i++) {
		H->TheLists[i] = malloc(sizeof(struct ListNode));
		if (H->TheLists[i] == NULL)
			printf("Out of space!!");
		else
			H->TheLists[i]->Next = NULL;
	}
	return H;
}

Position Find(int Key, HashTable H) {
	Position P;
	List L;

	L = H->TheLists[Hash(Key, H->TableSize)];
	P = L->Next;
	while (P != NULL && P->Element != Key)
		/*Probably need strcmp*/
		P = P->Next;
	return P;
}

Position FindPre(int Key, HashTable H) {
	Position P;
	List L;

	L = H->TheLists[Hash(Key, H->TableSize)];
	P = L;
	while (P ->Next!= NULL && P->Next->Element != Key)
		/*Probably need strcmp*/
		P = P->Next;
	if (P->Next == NULL)
		return NULL;
	else
		return P;
}

void Insert(int Key, HashTable H) {
	Position Pos, NewCell;
	List L;

	Pos = Find(Key, H);
	if (Pos == NULL) {	/*Key is not found*/
		NewCell = malloc(sizeof(struct ListNode));
		if (NewCell == NULL)
			printf("Out of space!!");
		else {
			/*插到链表头部*/
			L = H->TheLists[Hash(Key, H->TableSize)];
			NewCell->Next = L->Next;
			NewCell->Element = Key;
			L->Next = NewCell;
		}
	}
}

HashTable Delete(int Key, HashTable H) {
	Position P;
	List L;
	P = FindPre(Key, H);
	if (P == NULL)
		printf("Not found %d\n", Key);
	else {
		L = P->Next;
		P->Next = L->Next;
		free(L);
	}
	return H;
}

void DestroyTable(HashTable H) {
	for (int i = 0; i < H->TableSize; i++) {
		while (H->TheLists[i]->Next != NULL) {
			List L;
			L = H->TheLists[i]->Next;
			H->TheLists[i]->Next = L->Next;
			free(L);
		}
		free(H->TheLists[i]);
	}
	//free(H->TheLists);
	H->TheLists = NULL;
	//free(H);
	//H->TheLists = NULL;
}


int main() {
	HashTable H;
	H=InitializeTable(10);
	Insert(0, H);
	Insert(1, H);
	Insert(4, H);
	Insert(9, H);
	Insert(16, H);
	Insert(25, H);
	Insert(36, H);
	Insert(49, H);
	printf("%d\n", Find(36, H)->Element);
	H = Delete(36, H);
	if (Find(36, H) == NULL)
		printf("not found\n");
	else
		printf("%d\n", Find(36, H)->Element);
	DestroyTable(H);
	return 0;
}
