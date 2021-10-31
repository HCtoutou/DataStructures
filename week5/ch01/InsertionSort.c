#include"Sort.h"


void InsertionSort(int A[], int N) {
	int j, P;

	int Tmp;
	for (P = 1; P < N; P++) {
		Tmp = A[P];
		for (j = P; j > 0 && A[j - 1] > Tmp; j--)//从后往前查找Tmp的正确位置
			A[j] = A[j - 1];
		A[j] = Tmp;
	}
}

