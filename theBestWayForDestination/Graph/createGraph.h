//
//  createGraph.h
//  theBestWayForDestination
//
//  Created by 高浩岚 on 2022/2/15.
//

#ifndef createGraph_h
#define createGraph_h

#include <stdio.h>
#include<stdlib.h>
#include <string.h>

#define MAX 39


typedef struct CityInfo
{
    int partTime;
    char startTime[20];
    char endTime[20];
    char transportation[10];
    int fee;
}CityInfo;

typedef struct EdgeNode //边
{
    //边节点
    int adjvex;    //该邻接点在顶点数组中的下标
    CityInfo info;
    int isFirst;  //如果该边包含起点，则为1，否则为0
    struct EdgeNode *link;   //指向下一个邻接点
}EdgeNode;

typedef struct ArrayNode
{
    char data[20];  //顶点名称
    EdgeNode *edge;  //指向边节点
}ArrayNode,Arrays[MAX]; //顶点数组


typedef struct Graph{  //图存放顶点和边
    Arrays arrays;
    int numVertexes,numEdges;  //结点数以及边数，本系统中边数没有用？
}Graph,*GraphArrays;




Graph* createGraph(void);
void printgraph(Graph* g);
int isCityRepeat(Graph* g,char vexs[]);
int findadj(char vexs[],Graph* g);

#endif /* createGraph_h */
