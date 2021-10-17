//分离链接法
#pragma once
struct ListNode;
typedef struct ListNode* Position;
struct HashTbl;
typedef struct HashTbl* HashTable;

HashTable InitializeTable(int TableSize);
int Hash(int Key, int TableSize);
void DestroyTable(HashTable H);
Position Find(int Key, HashTable H);
Position FindPre(int Key, HashTable H);//返回Key值前面的节点，删除时需要
void Insert(int Key,HashTable H);
HashTable Delete(int Key, HashTable H);

struct ListNode {
	int Element;
	Position Next;
};
typedef Position List;


struct HashTbl {
	int TableSize;
	List* TheLists;
};
