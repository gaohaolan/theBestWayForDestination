//
//  Queue.h
//  theBestWayForDestination
//
//  Created by 高浩岚 on 2022/3/12.
//

#ifndef Queue_h
#define Queue_h

#include <stdio.h>


//使用队列，进行BFS，以求出最少中转次数。
//队列基本操作：初始化->入队->判空->获取队头->出队->遍历测试

typedef struct QNode{
    int data;
    struct QNode* next;
}QNode;

typedef struct LinkQueue{
    QNode* front;
    QNode* rear;
}LinkQueue;

void InitQueue(LinkQueue* Q);
void Enqueue(LinkQueue* Q, int data);
int IsEmpty(LinkQueue* Q);
void Dequeue(LinkQueue* Q);
int GetTop(LinkQueue* Q);


#endif /* Queue_h */
