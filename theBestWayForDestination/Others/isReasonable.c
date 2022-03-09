//
//  isReasonable.c
//  theBestWayForDestination
//
//  Created by 高浩岚 on 2022/3/8.
//

#include "isReasonable.h"
#include "howLong.h"

int isReasonable(Graph* g, int c, int b, int a){
    char t1[20];
    char t2[20];
    for (EdgeNode* e=g->arrays[b].edge; e!=NULL; e=e->link) {
        if (e->adjvex==c) {
            strcpy(t2, e->info.startTime);
        }
    }
    for (EdgeNode* e=g->arrays[a].edge; e!=NULL; e=e->link) {
        if (e->adjvex==b) {
            strcpy(t1, e->info.endTime);
        }
    }
    
    if (howLong(t2, t1)<0) {
        return 1;
    }
    return 0;
}
