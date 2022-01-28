#include<stdlib.h>
#include"Sort.h"

void MSort(int A[], int TmpArray[], int Left, int Right) {
	int Center;

	if (Left < Right) {
		Center = (Left + Right) / 2;	//分割
		MSort(A, TmpArray, Left, Center); //对左半部分进行排序（递归）
		MSort(A, TmpArray, Center + 1, Right); //对右半部分进行排序（递归）
		Merge(A, TmpArray, Left, Center + 1, Right); //合并
	}
}

void Mergesort(int A[], int N) { //驱动历程
	int* TmpArray;

	TmpArray = malloc(N * sizeof(int));
	if (TmpArray != NULL) {
		MSort(A, TmpArray, 0, N - 1);
		free(TmpArray);
	}
	else {
		printf("No space for tmp array!!!");
		exit(1);
	}
}

//合并
void Merge(int A[], int TmpArray[], int Lpos, int Rpos, int RightEnd) {
	int i, LeftEnd, NumElement, TmpPos;

	LeftEnd = Rpos - 1;
	TmpPos = Lpos;
	NumElement = RightEnd - Lpos + 1;

	while (Lpos <= LeftEnd && Rpos <= RightEnd)
		if (A[Lpos] <= A[Rpos])
			TmpArray[TmpPos++] = A[Lpos++];
		else
			TmpArray[TmpPos++] = A[Rpos++];

	while (Lpos <= LeftEnd)	/*Copy rest of first half*/
		TmpArray[TmpPos++] = A[Lpos++];
	while (Rpos <= RightEnd)	/*Copy rest of second half*/
		TmpArray[TmpPos++] = A[Rpos++];

	/*Copy TmpArray back*/ //将合并的数组移动到原数组
	for (i = 0; i < NumElement; i++, RightEnd--)
		A[RightEnd] = TmpArray[RightEnd];
}
