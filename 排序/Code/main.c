#include<stdio.h>

void Printf_A(int A[], int N) {
	for (int i = 0; i < N; i++)
		printf("%d\n", A[i]);
	printf("\n");
}

void Swap(int* a, int* b) {
	int t = *a; *a = *b; *b = t;
}

int main() {
	int A[5] = { 1,5,12,4,3 };

	InsertionSort(A, 5);
	Printf_A(A, 5);

	/*希尔排序*/
	/*ShellSort(A, 5);
	Printf_A(A, 5);
	*/

	/*归并排序*/
	/*Mergesort(A, 5);
	Printf_A(A, 5);
	*/

	/*堆排序*/
	/*HeapSort(A, 5);
	Printf_A(A, 5);
	*/

	/*快速排序*/
	/*Quicksort(A, 5);
	Printf_A(A, 5);
	*/
	return 0;
}
