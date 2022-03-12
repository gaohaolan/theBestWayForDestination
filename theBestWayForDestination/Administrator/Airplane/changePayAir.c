//
//  changePayAir.c
//  theBestWayForDestination
//
//  Created by 高浩岚 on 2022/3/12.
//

#include "changePayAir.h"
#include "taskCompleted.h"
#include <string.h>
#include "reWriteair.h"

void changePayAir(Graph* gair,char vexs[]){
    
    //现在找到航班对应的边节点
    EdgeNode* jj=gair->arrays[1].edge;
    for (int i=1; i<=gair->numEdges; i++) {
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
    printf("\n\n\n\n\n航班%s的票价：\n\n原票价为💵%d",vexs,jj->info.fee);
    int pay;
    printf("\n\n\n");
    for (int i=0; i<22; i++) {
        printf("*  ");
    }
    printf("*\n新票价为💵");
    scanf("%d",&pay);
    jj->info.fee=pay;
    reWriteair(gair);
    getchar();
    taskCompleted();
}
