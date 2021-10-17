#pragma once
typedef unsigned int Index;
typedef Index Position;

struct HashTbl;
typedef struct HashTbl* HashTable;

HashTable InitializeTable(int TableSize);
void DestroyTable(HashTable H);
void Delete(int Key, HashTable H);
Position Find(int Key, HashTable H);
void Insert(int Key, HashTable H);
int Hash(int Key,int TableSize);
HashTable Rehash(HashTable H);

/*Place in the implementation*/
enum KindOfEntry{Legitimate,Empty,Deleted};

struct HashEntry {
	int Element;
	enum KindOfEntry Info;
};
typedef struct HashEntry Cell;

struct HashTbl {
	int TableSize;
	Cell* TheCells;
};
