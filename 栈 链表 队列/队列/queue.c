#include"queue.h"
#include<stdio.h>
#include<stdlib.h>

#define MinQueueSize (5)


struct QueueRecord {
    int Capacity;
    int Front;
    int Rear;
    int Size;
    int *Array;
};

int IsEmpty(Queue Q) {
    return Q->Size == 0;
}

int IsFull(Queue Q) {
    return Q->Size == Q->Capacity;
}

Queue CreateQueue(int MaxElements) {
    Queue Q;

    if (MaxElements < MinQueueSize)
        printf("Queue size is too small");

    Q = malloc(sizeof(struct QueueRecord));
    if (Q == NULL)
        printf("Out of space!!");

    Q->Array = malloc(sizeof(int) * MaxElements);
    if (Q->Array == NULL)
        printf("Out of space!!");

    Q->Capacity = MaxElements;
    MakeEmpty(Q);

    return Q;
}

void MakeEmpty(Queue Q) {
    Q->Size = 0;
    Q->Front = 1;
    Q->Rear = 0;
}

void DisposeQueue(Queue Q) {
    if (Q != NULL) {
        free(Q->Array);
        free(Q);
    }
}

static int Succ(int value, Queue Q) {
    if (++value == Q->Capacity)
        value = 0;
    return value;
}

void Enqueue(Queue Q, ElementType X) {
    if (IsFull(Q))
        printf("Full queue");
    else {
        Q->Size++;
        Q->Rear = Succ(Q->Rear, Q);
        Q->Array[Q->Rear] = X;
    }
}

ElementType Front(Queue Q) {
    if (IsEmpty(Q))
        printf("Empty queue");
    else
        return Q->Array[Q->Front];
}

void Dequeue(Queue Q) {
    if (IsEmpty(Q))
        printf("Empty queue");
    else {
        Q->Front = Succ(Q->Front, Q);
        Q->Size--;
    }
}

ElementType FrontAndDequeue(Queue Q) {
    ElementType X;
    if (IsEmpty(Q))
        printf("Empty queue");
    else {
        X = Q->Array[Q->Front];
        Q->Front = Succ(Q->Front, Q);
        Q->Size--;
    }
    return X;
}

int main() {

    Queue Q;

    Q = CreateQueue(10);
    Enqueue(Q, 1);
    Enqueue(Q, 2);
    Dequeue(Q);
    printf("%d\n", Front(Q));
    printf("%d\n", FrontAndDequeue(Q));
    printf("%d", IsEmpty(Q));
    DisposeQueue(Q);

    return 0;

}
