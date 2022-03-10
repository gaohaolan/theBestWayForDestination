//
//  totalFee.c
//  theBestWayForDestination
//
//  Created by 高浩岚 on 2022/3/10.
//

#include "totalFee.h"
#include "minimumOfTransits.h"

int totalFee(char vexs[],Graph* g){
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
    
    int totalFee=0;
    
    for (int j=1; j<=i-1; j++) {
        int b=allArray[j];
        int a=allArray[j-1];
        for (EdgeNode* e=g->arrays[a].edge; e!=NULL; e=e->link) {
            if (e->adjvex==b) {
                totalFee=totalFee+e->info.fee;
            }
        }
    }
    return totalFee;
}

