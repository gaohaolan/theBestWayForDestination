//
//  Queue.c
//  theBestWayForDestination
//
//  Created by 高浩岚 on 2022/3/12.
//

#include "Queue.h"
#include<stdlib.h>


//队列基本操作

//初始化
void InitQueue(LinkQueue* Q)
{
    Q->front = Q->rear = (QNode*)malloc(sizeof(QNode));       //头尾均指向头指针
    Q->front->next = NULL;           //尾部赋空
}

//尾部插入
void Enqueue(LinkQueue* Q,int data)
{
    QNode* p = (QNode*)malloc(sizeof(QNode));
    p->data = data;
    p->next = NULL;
    
    Q->rear->next = p;
    Q->rear = p;
}

//空->1;非空->0
int IsEmpty(LinkQueue *Q)
{
    if(Q->front==Q->rear)
        return 1;
    else
        return 0;
}

//头部删除；注意删除的节点为尾节点时，重新将尾节点指向头结点
void Dequeue(LinkQueue* Q)
{
    if(!IsEmpty(Q))
    {
        Q->front->next = Q->front->next->next;
        if(IsEmpty(Q))
            Q->rear = Q->front;     //删除尾节点，重新将尾指针指向头
    }
}

//获取队头元素
int GetTop(LinkQueue* Q)
{
    if(!IsEmpty(Q))
    {
        return Q->front->next->data;
    }
    else return -211;
}





