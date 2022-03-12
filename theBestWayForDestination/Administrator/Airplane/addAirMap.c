//
//  addAirMap.c
//  theBestWayForDestination
//
//  Created by 高浩岚 on 2022/3/12.
//

#include "addAirMap.h"
#include <stdlib.h>
#include "taskCompleted.h"
#include <string.h>
#include "howLong.h"
#include "reWriteair.h"

//新加一个航班时刻表
void addAirMap(Graph* gair){
    system("clear");  //清屏
    char newLine[20];
    printf("\n\n\n\n\n请输入新加航班名称：\n👉🏻");
    scanf("%s",newLine);
    
    system("clear");
    printf("\n\n\n\n\n输入新加航班%s的出发城市\n👉🏻",newLine);
    char startCity[20];
    scanf("%s",startCity);
    
    //图结构进行加边
    char endCity[1024];
    printf("\n输入到达城市名称\n👉🏻");
    scanf("%s",endCity);
    
    system("clear");
    printf("\n\n\n\n现在请输入%s,出发%s到达%s的...\n\n",newLine,startCity,endCity);
    EdgeNode* f1=gair->arrays[findadj(startCity, gair)].edge;
        if (f1==NULL) {
            EdgeNode* ane=(EdgeNode*)malloc(sizeof(EdgeNode));
            printf("出发时间：");
            char stt[20];
            scanf("%s",stt);
            strcpy(ane->info.startTime, stt);
            printf("到达时间：");
            char ett[20];
            scanf("%s",ett);
            strcpy(ane->info.endTime, ett);
            printf("票价：");
            int pp;
            scanf("%d",&pp);
            ane->info.fee=pp;
            strcpy(ane->info.transportation, newLine);
            int ppttt=howLong(stt, ett);
            ane->info.partTime=ppttt;
            ane->link=NULL;
            ane->adjvex=findadj(endCity, gair);
            gair->arrays[findadj(startCity, gair)].edge=ane;
        }
        else{
            EdgeNode* ane=(EdgeNode*)malloc(sizeof(EdgeNode));
            printf("出发时间：");
            char stt[20];
            scanf("%s",stt);
            strcpy(ane->info.startTime, stt);
            printf("到达时间：");
            char ett[20];
            scanf("%s",ett);
            strcpy(ane->info.endTime, ett);
            printf("票价：");
            int pp;
            scanf("%d",&pp);
            ane->info.fee=pp;
            strcpy(ane->info.transportation, newLine);
            int ppttt=howLong(stt, ett);
            ane->info.partTime=ppttt;
            ane->adjvex=findadj(endCity, gair);
            ane->link=f1;
            gair->arrays[findadj(startCity, gair)].edge=ane;
        }
    getchar();
    reWriteair(gair);
    taskCompleted();
}
