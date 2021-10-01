#ifndef _List_H
struct Node;
typedef struct Node* PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;

List MakeEmpty(List L);
Position Creat(int n);//创建链表
void Show(List L);//打印链表
int IsEmpty(List L);//判断链表是否为空
int IsLast(Position P, List L);//判断当前位置是否为最后一个
Position Find(int X, List L);//查找
void Delete(int X, List L);//删除
Position FindPrevious(int X, List L);//查找当前位置的前驱
void Insert(int X, List L, Position P);//插入
void DeleteList(List L);
Position Header(List L);
Position First(List L);
Position Advance(Position P);
int Retrieve(Position P);
#endif

struct Node {
	int Element;
	Position Next;
};
