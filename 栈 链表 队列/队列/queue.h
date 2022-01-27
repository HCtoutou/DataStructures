#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED

typedef int ElementType;

struct QueueRecord;
typedef struct QueueRecord* Queue;

int IsEmpty(Queue Q);
int IsFull(Queue Q);
Queue CreateQueue(int MaxElements);
void DisposeQueue(Queue Q);		//销毁队列
void MakeEmpty(Queue Q);	//使队列为空
void Enqueue(Queue Q, ElementType X);
void Dequeue(Queue Q);
int Front(Queue Q);		//返回队列的队首元素
int FrontAndDequeue(Queue Q);	//返回队首元素并出队

#endif // QUEUE_H_INCLUDED
