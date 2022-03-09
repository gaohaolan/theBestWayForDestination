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
#include "compareTrans.h"
#include "theMiniTrans.h"
#define MAXT 1024

void dfs1(Graph* g, int startc, int endc, int visited[], int path[], int cnt)
{
    int v=startc;
    int f=endc;
    if (cnt>=2) {
        if (isReasonable(g, v, path[cnt-1], path[cnt-2])) {
            visited[v] = 1;
            path[cnt++] = v;
            if(v == f)
            {
                FILE* f1=fopen("/Users/gaohaolan/高浩岚的本地文件/theBestWayForDestination/theBestWayForDestination/testText/miniLinesChoice.txt", "a");
                for(int i = 0; i <cnt; i++)
                {
                    fprintf(f1, "%d",path[i]);
                    fputs(" ", f1);
                    //printf("%d",path[i]);
                    //printf("站 ");
                    
                }
                //printf("\n");
                fputs("\n", f1);
                fclose(f1);
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
    }
    
    else{
        visited[v] = 1;
        path[cnt++] = v;
        if(v == f)
        {
            FILE* f2=fopen("/Users/gaohaolan/高浩岚的本地文件/theBestWayForDestination/theBestWayForDestination/testText/miniLinesChoice.txt", "a");
            for(int i = 0; i <cnt; i++)
            {
                fprintf(f2, "%d",path[i]);
                fputs(" ", f2);
                //printf("%d",path[i]);
                //printf("站 ");
            }
            //printf("\n");
            fputs("\n", f2);
            fclose(f2);
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
}
 

//输出顶点i到顶点j之间的所有简单路径(不包含回路)
void findAllPath(Graph* g, char start[], char end[])
{
    int startc=findadj(start, g);
    int endc=findadj(end, g);
    
    if(!strcmp(start, end))
        printf("TEST%sNOTTHIS\n",start);  //正常情况下，不会出现在程序运行中...
    else
    {
        int visited[MAXT];
        for(int i=0;i<=g->numVertexes;i++)
        {
            visited[i]=0;
        }   //初始化数组visited的元素值为0，表示均未访问
        int path[MAXT];
        dfs1(g, startc, endc, visited, path, 0);
    }
 
}



void minimumOfTransits(Graph* g){
    system("clear");  //清屏
    FILE* f=fopen("/Users/gaohaolan/高浩岚的本地文件/theBestWayForDestination/theBestWayForDestination/testText/miniLinesChoice.txt", "w");
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
    fclose(f);
    
    FILE* f1=fopen("/Users/gaohaolan/高浩岚的本地文件/theBestWayForDestination/theBestWayForDestination/testText/miniLinesChoice.txt", "r");
    int sum=0;
    char buf[1024];
    while (fgets(buf, 1024, f)!=NULL) {
        sum++;
    }
    //printf("%d",sum);
    fclose(f1);
    
    FILE* f2=fopen("/Users/gaohaolan/高浩岚的本地文件/theBestWayForDestination/theBestWayForDestination/testText/miniLinesChoice.txt", "r");
    int transArray[sum];
    char buff[1024];
    for (int i=0; i<sum; i++) {
        transArray[i]=compareTrans(fgets(buff, 1024, f2), g);
    }
    fclose(f2);
    
//    for (int t=0; t<sum; t++) {
//        printf("%d\n",transArray[t]);
//    }
    
    
    int theMini=theMiniTrans(transArray,sum);
    //printf("MT:%d",theMini);
    int howRep=0;
    for (int t=0; t<sum; t++) {
        if (transArray[t]==theMini) {
            howRep++;
        }
    }
    
    int readLine[howRep];
    for (int t=0,b=0; t<sum; t++) {
        if (transArray[t]==theMini) {
            readLine[b]=t+1;
            b++;
        }
    }
    
    FILE* f3= fopen("/Users/gaohaolan/高浩岚的本地文件/theBestWayForDestination/theBestWayForDestination/Routes/routes.txt", "a");
    
    fputs("从", f3);
    fputs(cityStart, f3);
    fputs("到", f3);
    fputs(cityEnd, f3);
    fputs("的火车中转次数最少路线为：\n", f3);
    
    
    for (int y=0; y<howRep; y++) {
        fputs("👉🏻", f3);
        FILE* f4= fopen("/Users/gaohaolan/高浩岚的本地文件/theBestWayForDestination/theBestWayForDestination/testText/miniLinesChoice.txt", "r");
        for (int i=1; i<readLine[y]; i++) {
            char inst[60];
            fgets(inst, 60, f4);
        }
        char itisit[60];
        fgets(itisit, 60, f4);  //所以说写代码的时候一定要注意连贯性和完整性！就像现在，我坐在图书馆里（刚吃完饭回来），都不知道接下来要实现什么功能了...
        //又想起来了！
        char* bu=strtok(itisit, " ");
        NumN* h=(NumN*)malloc(sizeof(NumN));   //无头节点！
        h->next=NULL;
        h->se=atoi(bu);
        NumN* r=h;
        int i=0;
        for ( ; bu!=NULL; i++) {
            bu=strtok(NULL, " \n");
            
            
            if (bu!=NULL) {
                NumN* e=(NumN*)malloc(sizeof(NumN));
                e->next=NULL;
                e->se=atoi(bu);
                //printf("%d\n",atoi(bu));
                r->next=e;
                r=e;
            }
            
        }
        r=h;
        int allCity=0;
        for ( ; r!=NULL; r=r->next) {
            allCity++;
        }
        r=h;
        //现在是把城市下标链表转换成线路表并且存储到最终文件里
        int cityNumArray[allCity];
        for (int s=1; s<allCity; s++) {
            cityNumArray[s-1]=r->se;
            fputs(g->arrays[r->se].data, f3);
            fputs("-->", f3);
            r=r->next;
        }
        fputs(g->arrays[r->se].data, f3);
        fputs("\n出发时间为：", f3);
        r=h;
        char time[20];
        EdgeNode* e=g->arrays[r->se].edge;
        for ( ; e!=NULL; e=e->link) {
            if (e->adjvex==r->next->se) {
                strcpy(time, e->info.startTime);
            }
        }
        fputs(time, f3);
        fputs("\n中转城市为：", f3);
        if (theMini==0) {
            fputs("无需中转城市！\n乘坐路线为：", f3);
            char lineInfo[20];
            e=g->arrays[r->se].edge;
            for ( ; e!=NULL; e=e->link) {
                if (e->adjvex==r->next->se) {
                    strcpy(lineInfo, e->info.transportation);
                }
            }
            fputs(lineInfo, f3);
        }
        else{
           
            //现在来处理火车线路
            fputs("\n依次换乘的路线与城市为：", f3);
//            int transCityNum[40];  //transcitynum
//            int ini=0;
            for(int kun=1; kun<allCity-1; kun++){
                char t1[20];
                char t2[20];
                int a=cityNumArray[kun-1];
                int b=cityNumArray[kun];
                int c=cityNumArray[kun+1];
                for (EdgeNode* e=g->arrays[b].edge; e!=NULL; e=e->link) {
                    if (e->adjvex==c) {
                        strcpy(t2, e->info.transportation);
                    }
                }
                for (EdgeNode* e=g->arrays[a].edge; e!=NULL; e=e->link) {
                    if (e->adjvex==b) {
                        strcpy(t1, e->info.transportation);
                    }
                }
                if (strcmp(t1, t2)) {
//                    transCityNum[ini]=b;
//                    ini++;
                    fputs(t1, f3);
                    fputs("---", f3);
                    fputs(g->arrays[b].data, f3);
                    fputs("---", f3);
                }
                if (kun==allCity-2) {
                    fputs(t2, f3);
                }
            }
        }
        
        fputs("\n", f3);
        fclose(f4);
    }
    fputs("\n", f3);
    fclose(f3);
    
    
    
    printf("\n");
    for (int i=0; i<22; i++) {
        printf("*  ");
    }
    printf("*\n\n\n");
    printf("线路已保存至：“theBestWayForDestination/theBestWayForDestination/Routes/routes.txt”。\n\n按Enter键以返回...");
    //deleteTempFile
    remove("/Users/gaohaolan/高浩岚的本地文件/theBestWayForDestination/theBestWayForDestination/testText/miniLinesChoice.txt");
    getchar();
    getchar();
}
