//
//  lessFee.c
//  theBestWayForDestination
//
//  Created by 高浩岚 on 2022/3/7.
//

#include "lessFee.h"
#include <stdlib.h>
#include <string.h>
#include "isReasonable.h"
#include "compareTrans.h"
#include "theMiniTrans.h"
#include "totalFee.h"
#define MA 60


void dfs2(Graph* g, int startc, int endc, int visited[], int path[], int cnt, int* flag){
    int v=startc;
    int f=endc;
    if (cnt>=2) {
        if (isReasonable(g, v, path[cnt-1], path[cnt-2])) {
            visited[v] = 1;
            path[cnt++] = v;
            if(v == f)
            {
                FILE* f1=fopen("/Users/gaohaolan/高浩岚的本地文件/theBestWayForDestination/theBestWayForDestination/testText/lessfee.txt", "a");
                for(int i = 0; i <cnt; i++)
                {
                    fprintf(f1, "%d",path[i]);
                    fputs(" ", f1);
                    *flag=1;
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
                    dfs2(g, e->adjvex, endc, visited, path, cnt, flag);
                                 
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
            FILE* f2=fopen("/Users/gaohaolan/高浩岚的本地文件/theBestWayForDestination/theBestWayForDestination/testText/lessfee.txt", "a");
            for(int i = 0; i <cnt; i++)
            {
                fprintf(f2, "%d",path[i]);
                fputs(" ", f2);
                *flag=1;
               // printf("%d",path[i]);
                //printf("站 ");
            }
           // printf("\n");
            fputs("\n", f2);
            fclose(f2);
            //return;
        }
     
        for(EdgeNode* e = g->arrays[v].edge; e!=NULL; e = e->link)
        {
            if(!visited[e->adjvex])
            {
                dfs2(g, e->adjvex, endc, visited, path, cnt, flag);
                             
            }
        }
        visited[v]=0;               //回溯法
        cnt--;                  //易错！
    }
}

void findAllPath2(Graph* g, char start[], char end[],int* flag){
    int startc=findadj(start, g);
    int endc=findadj(end, g);
    
    if(!strcmp(start, end))
        printf("TEST%sNOTTHIS\n",start);  //正常情况下，不会出现在程序运行中...
    else
    {
        int visited[MA];
        for(int i=0;i<=g->numVertexes;i++)
        {
            visited[i]=0;
        }   //初始化数组visited的元素值为0，表示均未访问
        int path[MA];
        dfs2(g, startc, endc, visited, path, 0, flag);
    }
}


void lessFee(Graph* g){
    system("clear");  //清屏
    FILE* f=fopen("/Users/gaohaolan/高浩岚的本地文件/theBestWayForDestination/theBestWayForDestination/testText/lessfee.txt", "w");
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
    printf("\t\t  所有火车费用最少方案：\n\n");
    int flag=0;
    findAllPath2(g, cityStart, cityEnd, &flag);
    fclose(f);
    
    FILE* f1=fopen("/Users/gaohaolan/高浩岚的本地文件/theBestWayForDestination/theBestWayForDestination/testText/lessfee.txt", "r");
    int sum=0;
    char buf[1024];
    while (fgets(buf, 1024, f)!=NULL) {
        sum++;
    }
    //printf("%d",sum);
    fclose(f1);
    
    FILE* f2=fopen("/Users/gaohaolan/高浩岚的本地文件/theBestWayForDestination/theBestWayForDestination/testText/lessfee.txt", "r");
    int LessFee[sum];
    char buff[1024];
    for (int i=0; i<sum; i++) {
        LessFee[i]=totalFee(fgets(buff, 1024, f2), g);
    }
    fclose(f2);
    
//    for (int t=0; t<sum; t++) {
//        printf("%d\n",transArray[t]);
//    }
    
    
    int theLessFee=theMiniTrans(LessFee,sum);
    //printf("MT:%d",theMini);
    int howRep=0;
    for (int t=0; t<sum; t++) {
        if (LessFee[t]==theLessFee) {
            howRep++;
        }
    }
    
    int readLine[howRep];
    for (int t=0,b=0; t<sum; t++) {
        if (LessFee[t]==theLessFee) {
            readLine[b]=t+1;
            b++;
        }
    }
    
    FILE* f3= fopen("/Users/gaohaolan/高浩岚的本地文件/theBestWayForDestination/theBestWayForDestination/Routes/routes.txt", "a");
    
    fputs("从", f3);
    fputs(cityStart, f3);
    fputs("到", f3);
    fputs(cityEnd, f3);
    fputs("的火车费用最少的路线为：\n", f3);
    //重点关注这里！
    
    if (flag==0) {
        printf("🚫无法到达目的地！暂无线路可以抵达！\n");
        fputs("🚫无法到达目的地！暂无线路可以抵达！\n", f3);
    }
    
    for (int y=0; y<howRep; y++) {
        fputs("👉🏻", f3);
        FILE* f4= fopen("/Users/gaohaolan/高浩岚的本地文件/theBestWayForDestination/theBestWayForDestination/testText/lessfee.txt", "r");
        for (int i=1; i<readLine[y]; i++) {
            char inst[60];
            fgets(inst, 60, f4);
        }
        char itisit[60];
        fgets(itisit, 60, f4);
        //不能屈服向往从前
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
        //printf("allcity:%d",allCity);
        int cityNumArray[allCity];
        for (int s=1; s<allCity; s++) {
            cityNumArray[s-1]=r->se;
            fputs(g->arrays[r->se].data, f3);
            printf("%s",g->arrays[r->se].data);
            fputs("-->", f3);
            printf("-->");
            r=r->next;
        }
        fputs(g->arrays[r->se].data, f3);
        cityNumArray[allCity-1]=r->se;
        printf("%s",g->arrays[r->se].data);
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
        fputs("\n", f3);
        fputs("总费用为：", f3);
        char buuf[38];
        sprintf(buuf, "%d",theLessFee);
        fputs(buuf, f3);
        fputs("\n", f3);
        printf("\n");
        fclose(f4);
    }
    fputs("\n", f3);
    printf("\n");
    fclose(f3);
    
    
    
    printf("\n");
    for (int i=0; i<22; i++) {
        printf("*  ");
    }
    printf("*\n\n\n");
    printf("线路已保存至：“theBestWayForDestination/theBestWayForDestination/Routes/routes.txt”。\n\n按Enter键以返回...");
    //deleteTempFile
    remove("/Users/gaohaolan/高浩岚的本地文件/theBestWayForDestination/theBestWayForDestination/testText/lessfee.txt");
    getchar();
    getchar();
    
    
    
}
