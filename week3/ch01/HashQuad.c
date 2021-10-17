#include<stdio.h>
#include<stdlib.h>
#include"HashQuad.h"

int Hash(int Key, int TableSize) {
	return Key % TableSize;
}

void DestroyTable(HashTable H) {
	free(H->TheCells);
	free(H);
}

HashTable InitializeTable(int TableSize) {
	HashTable H;
	int i;

	if (TableSize < 7) {
		printf("Table size too small\n");
		return NULL;
	}

	H = malloc(sizeof(struct HashTbl));

	H->TableSize = TableSize;

	H->TheCells = malloc(sizeof(Cell) * H->TableSize);
	if (H->TheCells == NULL)
		printf("Out of space\n");

	for (i = 0; i < H->TableSize; i++)
		H->TheCells[i].Info = Empty;

	return H;
}

Position Find(int Key, HashTable H) {
	Position CurrentPos;
	int CollisionNum;

	CollisionNum = 0;
	CurrentPos = Hash(Key, H->TableSize);
	while (H->TheCells[CurrentPos].Info != Empty && H->TheCells[CurrentPos].Element != Key) {
		CurrentPos += 2 * ++CollisionNum - 1;
		if (CurrentPos >= H->TableSize)
			CurrentPos -= H->TableSize;
	}
	if (H->TheCells[CurrentPos].Info != Legitimate)
		printf("not found %d\n", Key);
	return CurrentPos;
}

void Insert(int Key, HashTable H) {
	Position Pos;

	Pos = Find(Key, H);
	if (H->TheCells[Pos].Info != Legitimate) {
		/*Ok to insert here*/
		H->TheCells[Pos].Info = Legitimate;
		H->TheCells[Pos].Element = Key;
		/*Probably need strcpy!*/
		printf("insert %d ok\n", Key);
	}
}

void Delete(int Key, HashTable H) {
	int Pos;
	Pos=Find(Key, H);
	if (H->TheCells[Pos].Info != Legitimate)
		printf("not found,can not delete\n");
	else
		H->TheCells[Pos].Info = Deleted;


}

HashTable Rehash(HashTable H) {
	int i, OldSize;
	Cell* OldCells;

	OldCells = H->TheCells;
	OldSize = H->TableSize;

	/*Get a new,empty table*/
	H = InitializeTable(2 * OldSize);

	/*Scan through old table,reinserting into new*/
	for (i = 0; i < OldSize; i++)
		if (OldCells[i].Info == Legitimate)
			Insert(OldCells[i].Element, H);

	free(OldCells);

	return H;
}


int main() {
	HashTable H;
	H = InitializeTable(13);
	Insert(1, H);
	Insert(4, H);
	Insert(5, H);
	Insert(17, H);
	printf("%d\n", Find(17, H));
	Delete(18, H);
	Delete(17, H);
	printf("%d\n", Find(17, H));
	Delete(17, H);
	DestroyTable(H);
	return 0;
}
