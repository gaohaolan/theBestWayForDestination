//
//  Queue.c
//  theBestWayForDestination
//
//  Created by 高浩岚 on 2022/3/12.
//

#include "Queue.h"
#include<stdlib.h>


//队列基本操作

//初始化链队列，头节点置空
void InitQueue(LinkQueue *Q)
{
    Q->front = Q->rear = NULL;
}

//判断链队列是否为空
int QueueEmpty(LinkQueue *Q)
{
    return(Q->front == NULL && Q->rear == NULL);
}

//入队
void EnLinkQueue(LinkQueue *Q, int v)
{
    QNode *p;
    p = (QNode *)malloc(sizeof(QNode));//为新的节点分配空间
    p->data = v;
    p->next = NULL;
    if(QueueEmpty(Q))
        Q->front = Q->rear = p;
    else
    {
        Q->rear->next = p;  //将新的节点连接到队列
        Q->rear = p;             //指向队列尾
    }
}

//出队
int DeLinkQueue(LinkQueue *Q)
{
    int i;
    QNode *s;
    if(QueueEmpty(Q))     //判断队列是否为空
        printf("Error,the linkqueue is empty!");
    s = Q->front;
    i = s->data;
    if(Q->front == Q->rear)   //判断队列是否只有一个节点
        Q->front = Q->rear = NULL;
    else
        Q->front = s->next;
    free(s);
    return i;

}

//读取队列头元素，不改变队列状态
int ReadLinkQueue(LinkQueue *Q)
{
    int i;
    if(QueueEmpty(Q))     //判断队列是否为空
        printf("Error,the linkqueue is empty!");
    i = Q->front->data;
    return i;
}




////初始化
//void InitQueue(LinkQueue* Q)
//{
//    Q->front = Q->rear = (QNode*)malloc(sizeof(QNode));       //头尾均指向头指针
//    Q->front->next = NULL;           //尾部赋空
//}
//
////尾部插入
//void Enqueue(LinkQueue* Q,int data)
//{
//    QNode* p = (QNode*)malloc(sizeof(QNode));
//    p->data = data;
//    p->next = NULL;
//
//    Q->rear->next = p;
//    Q->rear = p;
//}
//
////空->1;非空->0
//int IsEmpty(LinkQueue *Q)
//{
//    if(Q->front==Q->rear)
//        return 1;
//    else
//        return 0;
//}
//
////头部删除；注意删除的节点为尾节点时，重新将尾节点指向头结点
//void Dequeue(LinkQueue* Q)
//{
//    if(!IsEmpty(Q))
//    {
//        printf("not empty!\n");
//        Q->front->next = Q->front->next->next;
//        if(IsEmpty(Q))
//            Q->rear = Q->front;     //删除尾节点，重新将尾指针指向头
//    }
//}
//
////获取队头元素
//int GetTop(LinkQueue* Q)
//{
//    if(!IsEmpty(Q))
//    {
//        printf("get num:%d\n",Q->front->next->data);
//        return Q->front->next->data;
//    }
//    else return -211;
//}
//
//
//
//
//
