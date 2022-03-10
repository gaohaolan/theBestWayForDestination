//
//  totalTime.c
//  theBestWayForDestination
//
//  Created by 高浩岚 on 2022/3/10.
//

#include "totalTime.h"
#include "minimumOfTransits.h"
#include "howLong.h"

int totalTime(char vexs[],Graph* g){
    char* bu=strtok(vexs, " ");
    NumN* h=(NumN*)malloc(sizeof(NumN));
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
    //printf("Sum:%d\n",i);
    
    r=h;
    int allArray[i];
    for (int j=1; j<=i; j++) {
        allArray[j-1]=r->se;
        r=r->next;
    }
    
    int totalTime=0;
    char startTime[20];
    char endTime[20];
    int b=allArray[1];
    int a=allArray[0];
    for (EdgeNode* e=g->arrays[a].edge; e!=NULL; e=e->link) {
        if (e->adjvex==b) {
            strcpy(startTime, e->info.startTime);
        }
    }
    b=allArray[i-1];
    a=allArray[i-2];
    for (EdgeNode* e=g->arrays[a].edge; e!=NULL; e=e->link) {
        if (e->adjvex==b) {
            strcpy(endTime, e->info.endTime);
        }
    }
    totalTime=howLong(startTime, endTime);
    return totalTime;
}
