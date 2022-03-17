//
//  reWrite.h
//  theBestWayForDestination
//
//  Created by 高浩岚 on 2022/3/1.
//

#ifndef reWrite_h
#define reWrite_h

#include <stdio.h>
#include "createGraph.h"

typedef struct Info
{
    char startTime[20];
    char endTime[20];
    char transportation[10];
    int fee;
    char name[20];
}Info;

typedef struct LNode
{
   Info inf;
   struct LNode* next;
}LNode, *LINK;  //LINK为指针类型，不用带*号

typedef struct PartLNode
{
    char partTimeTime[20];
    struct PartLNode* next;
}PartLNode;


void DFSaLine(GraphArrays g,int i,LNode* ln,PartLNode* pp,char nnname[]);
void reWrite(Graph* g);
#endif /* reWrite_h */
