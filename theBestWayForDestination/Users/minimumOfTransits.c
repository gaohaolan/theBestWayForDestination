//
//  minimumOfTransits.c
//  theBestWayForDestination
//
//  Created by 高浩岚 on 2022/3/7.
//

#include "minimumOfTransits.h"
#include <stdlib.h>
#include <string.h>
#include "isReasonable.h"
#define MAXT 1024

void dfs1(Graph* g, int startc, int endc, int visited[], char path[], int cnt)
{
    int v=startc;
    int f=endc;
    
    visited[v] = 1;
    path[cnt++] = v;
    if(v == f)
    {
        for(int i = 0; i <cnt; i++)
        {
            
            printf("%d",path[i]);
            printf("站 ");
        }
        printf("\n");
        //return;
    }
 
    for(EdgeNode* e = g->arrays[v].edge; e!=NULL; e = e->link)
    {
        if(!visited[e->adjvex])
        {
            dfs1(g, e->adjvex, endc, visited, path, cnt);
                         
        }
    }
    visited[v]=0;               //回溯法
    cnt--;                  //易错！
}
 

//输出顶点i到顶点j之间的所有简单路径(不包含回路)
void findAllPath(Graph* g, char start[], char end[])
{
    int startc=findadj(start, g);
    int endc=findadj(end, g);
    
    if(!strcmp(start, end))
        printf("TEST%sNOTTHIS\n",start);
    else
    {
        int visited[MAXT];
        for(int i=0;i<=g->numVertexes;i++)
        {
            visited[i]=0;
        }   //初始化数组visited的元素值为0，表示均未访问
        char path[MAXT];
        dfs1(g, startc, endc, visited, path, 0);
    }
 
}



void minimumOfTransits(Graph* g){
    system("clear");  //清屏
    char cityStart[30];
    printf("\n\n\n\n\n请先输入想要出发的起始城市：\n👉🏻");
    scanf("%s",cityStart);
    printf("\n再输入抵达城市：\n👉🏻");
    char cityEnd[30];
    scanf("%s",cityEnd);
    system("clear");  //清屏
    printf("\n\n");
    for (int i=0; i<22; i++) {
        printf("*  ");
    }
    printf("*");
    printf("\n\n");
    printf("\t\t  所有可行方案：\n");
    findAllPath(g, cityStart, cityEnd);
    printf("\n");
    for (int i=0; i<22; i++) {
        printf("*  ");
    }
    printf("*\n");
    printf("按Enter键以返回...");
    getchar();
    getchar();
}
