#ifndef _Stack_h
struct Node;
typedef struct Node *PtrToNode;
typedef PtrToNode Stack;

int IsEmpty(Stack S);//判断栈是否为空
Stack CreatStack(void);
void DisposeStack(Stack S);
void MakeEmpty(Stack S);
void Push(int X, Stack S);//入栈
int Top(Stack S);
void Pop(Stack S);//出栈
#endif

struct Node {
	int Element;
	PtrToNode Next;
};
