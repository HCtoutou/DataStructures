#include<stdio.h>
#include<stdlib.h>
#include"DisjSet.h"

void Initialize(DisjSet S) {
	int i;

	for (i = NumSets; i > 0; i--)
		S[i] = 0;
}

void SetUnion(DisjSet S, SetType Root1, SetType Root2) {
	S[Root2] = Root1;
}

/*void SetUnion(DisjSet S, SetType Root1, SetType Root2) {
	if (S[Root2] < S[Root1])
		S[Root1] = Root2;
	else {
		if (S[Root1] == S[Root2])
			S[Root1]--;
		S[Root2] = Root1;
	}
}*/

SetType Find(ElemenType X, DisjSet S) {
	if (S[X] <= 0)
		return X;
	else
		return Find(S[X], S);
}

/*用路径压缩进行不相交集的Find操作*/
/*SetType Find(ElemenType X, DisjSet S) {
	if (S[X] <= 0)
		return X;
	else
		return S[X] = Find(S[X], X);
}*/

int main() {
	DisjSet S;
	Initialize(S);
	SetUnion(S, 2, 3);
	SetUnion(S, 2, 4);
	printf("%d\n", Find(3, S));
	return 0;
}
