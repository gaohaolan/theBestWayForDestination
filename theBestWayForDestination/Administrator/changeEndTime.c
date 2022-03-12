//
//  changeEndTime.c
//  theBestWayForDestination
//
//  Created by 高浩岚 on 2022/3/3.
//

#include "changeEndTime.h"
#include "taskCompleted.h"
#include <string.h>
#include "reWrite.h"


void changeEndTime(Graph* g,char vexs[]){
    char beginsta[20];
    char endsta[20];
    system("clear");
    printf("\n\n\n\n\n请输入区间起点站与终点站：\n\n起点站👉🏻");
    scanf("%s",beginsta);
    printf("终点站👉🏻");
    scanf("%s",endsta);
    EdgeNode* j=g->arrays[1].edge;
    for (int i=1; i<=g->numVertexes; i++) {
        if (!strcmp(g->arrays[i].data, beginsta)) {
            for (j=g->arrays[i].edge; j!=NULL ; j=j->link) {
                if (!strcmp(endsta, g->arrays[j->adjvex].data)) {
                    break;
                }
            }
            break;
        }
    }
    system("clear");
    printf("\n\n\n\n\n线路%s从起点站%s到终点站%s的到达时间：\n\n原时间为🕒%s",vexs,beginsta,endsta,j->info.endTime);
    char endTime[20];
    printf("\n\n\n");
    for (int i=0; i<22; i++) {
        printf("*  ");
    }
    printf("*\n新时间为🕔");
    scanf("%s",endTime);
    strcpy(j->info.endTime, endTime);
    reWrite(g);
    getchar();
    taskCompleted();
}
