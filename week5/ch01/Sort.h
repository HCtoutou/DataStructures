#pragma once

void Printf_A(int A[], int N);//打印序列

void InsertionSort(int A[], int N);//插入排序

void ShellSort(int A[], int N);//希尔排序

void PercDown(int A[], int i, int N);//堆排序中的下滤操作
void HeapSort(int A[], int N);//堆排序
void Swap(int* a, int* b);

void MSort(int A[], int TmpArray[], int Left, int Right);//归并排序
void Mergesort(int A[], int N);
void Merge(int A[], int TmpArray[], int Lpos, int Rpos, int RightEnd);

void Quicksort(int A[], int N);//快速排序驱动例程
int Median3(int A[], int Left, int Right);
void Qsort(int A[], int Left, int Right);
