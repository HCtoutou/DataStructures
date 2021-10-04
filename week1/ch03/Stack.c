#include<stdio.h>
#include<stdlib.h>
#include"Stack.h"

int IsEmpty(Stack S) {
	return S->Next == NULL;
}
Stack CreatStack(void) {//创建一个空栈
	Stack S;
	S = malloc(sizeof(struct Node));
	if (S == NULL)
		exit(0);
	S->Next = NULL;
	MakeEmpty(S);
	return S;
}

void MakeEmpty(Stack S) {//将栈置空
	if (S == NULL)
		printf("Must use CreatStack first");
	else
		while (!IsEmpty(S))
			Pop(S);
}

void Push(int X, Stack S) {//入栈操作
	PtrToNode TmpCell;
	TmpCell = malloc(sizeof(struct Node));
	if (TmpCell == NULL)
		exit(0);
	else {
		TmpCell->Element = X;
		TmpCell->Next = S->Next;
		S->Next = TmpCell;
	}
}

int Top(Stack S) {//查看栈顶元素
	if (!IsEmpty(S))
		return S->Next->Element;
	printf("Empty Stack");
	return 0;
}

void Pop(Stack S) {//出栈操作
	PtrToNode FirstCell;
	if (IsEmpty(S))
		printf("Empty Stack");
	else {
		FirstCell = S->Next;
		S->Next = S->Next->Next;
		free(FirstCell);
	}
}
void DisposeStack(Stack S) {//删除栈
	if (!IsEmpty)
		Pop(S);
	free(S);
}

int main() {//测试
	Stack S;
	S=CreatStack();
	for (int i = 0; i < 5; i++) {
		int n;
		scanf("%d", &n);
		Push(n, S);
	}
		printf("当前栈顶元素为%d\n", Top(S));
		Pop(S);
		printf("出栈成功！\n");
		printf("当前栈顶元素为：%d\n", Top(S));
		DisposeStack(S);

}
