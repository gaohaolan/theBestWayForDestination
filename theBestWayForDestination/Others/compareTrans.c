//
//  compareTrans.c
//  theBestWayForDestination
//
//  Created by 高浩岚 on 2022/3/9.
//

#include "compareTrans.h"
#include "minimumOfTransits.h"

int compareTrans(char vexs[], Graph* g){
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
    
    int transTimes=0;
    if (i>=3) {
        for (int j=1; j<=i-2; j++) {
            int c=allArray[j+1];
            int b=allArray[j];
            int a=allArray[j-1];
            char t1[20];
            char t2[20];
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
                transTimes++;
            }
        }
        return transTimes;
    }
    else
        return 0;
}
