//
//  changeEndTimeAir.c
//  theBestWayForDestination
//
//  Created by 高浩岚 on 2022/3/12.
//

#include "changeEndTimeAir.h"
#include "taskCompleted.h"
#include <string.h>
#include "reWriteair.h"

void changeEndTimeAir(Graph* gair,char vexs[]){
    
    //现在找到航班对应的边节点
    EdgeNode* jj=gair->arrays[1].edge;
    for (int i=1; i<=gair->numVertexes; i++) {
        EdgeNode* j=gair->arrays[i].edge;
        while (j!=NULL) {
            if (!strcmp(j->info.transportation, vexs)) {
                jj=j;
                break;
            }
            else
                j=j->link;
        }
    }
    
    system("clear");
    printf("\n\n\n\n\n航班%s的到达时间：\n\n原时间为🕔%s",vexs,jj->info.endTime);
    char endTime[20];
    printf("\n\n\n");
    for (int i=0; i<22; i++) {
        printf("*  ");
    }
    printf("*\n新时间为🕔");
    scanf("%s",endTime);
    strcpy(jj->info.endTime, endTime);
    reWriteair(gair);
    getchar();
    taskCompleted();
}
