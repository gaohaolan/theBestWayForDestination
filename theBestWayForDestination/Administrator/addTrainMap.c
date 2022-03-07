//
//  addTrainMap.c
//  theBestWayForDestination
//
//  Created by 高浩岚 on 2022/2/18.
//

#include "addTrainMap.h"
#include <stdlib.h>
#include "taskCompleted.h"
#include <string.h>
#include "deleteTrainMap.h"
#include "howLong.h"
#include "reWrite.h"

//新加一个列车时刻表
void addTrainMap(Graph* g){
    system("clear");  //清屏
    char newLine[20];
    printf("\n\n\n\n\n请输入新加线路名称：\n👉🏻");
    //getchar();
    scanf("%s",newLine);
    while (isLineRepeat(g,newLine)) {
        system("clear");
        printf("\n\n\n\n\n🚫线路已经存在！请重新输入新加的线路：\n👉🏻");
        //getchar();
        scanf("%s",newLine);
    }
    system("clear");
    printf("\n\n\n\n\n输入新加线路%s的途径城市个数\n👉🏻",newLine);
    int citySum;
    //getchar();
    scanf("%d",&citySum);
    FILE* f1= fopen("/Users/gaohaolan/高浩岚的本地文件/theBestWayForDestination/theBestWayForDestination/testText/trainLineOrder.txt","a");
    fputs(newLine, f1);
    fputs("\n", f1);
    fclose(f1);
    FILE* f2= fopen("/Users/gaohaolan/高浩岚的本地文件/theBestWayForDestination/theBestWayForDestination/testText/howManyPartLines.txt","a");
    fprintf(f2, "%d",citySum);
    fputs("\n", f2);   //换行符就这样子跟上了！
    fclose(f2);
    
    //图结构进行加边
    char allCityinLine[1024];
    printf("\n\n\n\n\n请按顺序输入所有城市名称（以,分隔）：\n👉🏻");
    
   // getchar();
   // getchar();
    //getchar();
    //getchar();
    scanf("%s",allCityinLine);
    city123* c1=(city123*)malloc(sizeof(city123));
    c1->link=NULL;
    city123* cc;
    //printf("test1\n");
    //printf("%s\n",allCityinLine);
    char* temp;
    temp = strtok(allCityinLine,",\n\r\0");
    //printf("test1\n");
    //printf("%s",temp);
    //printf("test2\n");
    //printf("2%s",allCityinLine);
    //printf("%s==",temp);
    //cc=(city123*)malloc(sizeof(city123));
    strcpy(c1->cityName, temp);
    //cc->link=NULL;
    city123* r=c1;
    //printf("test3\n");
    for (int i=1; i<citySum; i++) {
        cc=(city123*)malloc(sizeof(city123));
        char *temp2 = strtok(NULL,",\r\n\0");
        //printf("inner\n");
        //printf("%s\n",temp2);
        strcpy(cc->cityName, temp2);
        cc->link=NULL;
        r->link=cc;
        r=cc;
    }
    r->link=NULL;
    city123* newwc=c1;
    //printf("1这里没有问题！\n");
    
    city123* tryp=c1;
    while (tryp!=NULL) {
        //printf("%s->",tryp->cityName);
        tryp=tryp->link;
    }
    
    int flag=0;  //起点城市！！！
    
    for (int n=1; n<citySum; n++) {
        system("clear");
        char fircn[20];
        char nexcn[20];
        strcpy(fircn, newwc->cityName);
        //printf("%s\n",fircn);
        newwc=newwc->link;
        strcpy(nexcn, newwc->cityName);
        //printf("%s\n",nexcn);
        printf("\n\n\n\n现在请输入%s从%s到%s的...\n\n",newLine,fircn,nexcn);
        EdgeNode* f1=g->arrays[findadj(fircn, g)].edge;
        if (f1==NULL) {
            //printf("lll这里没有问题！\n");
            EdgeNode* ane=(EdgeNode*)malloc(sizeof(EdgeNode));
            printf("出发时间：");
            char stt[20];
            scanf("%s",stt);
            strcpy(ane->info.startTime, stt);
            printf("到达时间：");
            char ett[20];
            scanf("%s",ett);
            strcpy(ane->info.endTime, ett);
            if (flag==0) {
                flag=1;
                ane->isFirst=1;
            }
            else
                ane->isFirst=0;
            printf("区间票价：");
            int pp;
            scanf("%d",&pp);
            ane->info.fee=pp;
            strcpy(ane->info.transportation, newLine);
            int ppttt=howLong(stt, ett);
            ane->info.partTime=ppttt;
            ane->link=NULL;
            ane->adjvex=findadj(nexcn, g);
            g->arrays[findadj(fircn, g)].edge=ane;
        }
        else{
            //printf("lll这里没有问题！\n");
            EdgeNode* ane=(EdgeNode*)malloc(sizeof(EdgeNode));
            printf("出发时间：");
            char stt[20];
            scanf("%s",stt);
            strcpy(ane->info.startTime, stt);
            printf("到达时间：");
            char ett[20];
            scanf("%s",ett);
            strcpy(ane->info.endTime, ett);
            if (flag==0) {
                flag=1;
                ane->isFirst=1;
            }
            else
                ane->isFirst=0;
            printf("区间票价：");
            int pp;
            scanf("%d",&pp);
            ane->info.fee=pp;
            strcpy(ane->info.transportation, newLine);
            int ppttt=howLong(stt, ett);
            ane->info.partTime=ppttt;
            ane->adjvex=findadj(nexcn, g);
            ane->link=f1;
            g->arrays[findadj(fircn, g)].edge=ane;
        }
        
    }
    //printf("5这里没有问题！\n");
    //printgraph(g);
    getchar();
    reWrite(g);
    taskCompleted();
}
