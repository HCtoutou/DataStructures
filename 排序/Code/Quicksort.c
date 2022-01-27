
#include"Sort.h"

#define Cutoff (3)
void Quicksort(int A[], int N) {
	Qsort(A, 0, N - 1);
}

int Median3(int A[], int Left, int Right) {
	int Center = (Left + Right) / 2;

	if (A[Left] > A[Center])
		Swap(&A[Left], &A[Center]);
	if (A[Left] > A[Right])
		Swap(&A[Left], &A[Right]);
	if (A[Center] > A[Right])
		Swap(&A[Center], &A[Right]);

	Swap(&A[Center], &A[Right - 1]);
	return A[Right - 1];
}

void Qsort(int A[], int Left, int Right) {
	int i, j;
	int Pivot;

	if (Left + Cutoff <= Right) {
		Pivot = Median3(A, Left, Right);
		i = Left;
		j = Right - 1;
		for (;;) {
			while (A[++i] < Pivot) {}
			while (A[--j] > Pivot) {}
			if (i < j)
				Swap(&A[i], &A[j]);
			else
				break;
		}
		Swap(&A[i], &A[Right - 1]);

		Qsort(A, Left, i - 1);
		Qsort(A, i + 1, Right);
	}
	else
		InsertionSort(A + Left, Right - Left + 1);
}
