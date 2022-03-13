//
//  reWriteair.c
//  theBestWayForDestination
//
//  Created by 高浩岚 on 2022/3/10.
//

#include "reWriteair.h"
#include <string.h>
#include <stdlib.h>

void reWriteair(Graph* g){
    FILE* fff= fopen("/Users/gaohaolan/高浩岚的本地文件/theBestWayForDestination/theBestWayForDestination/Text/aircraftTimetables.txt", "w");
    char noww[200]="                    飞机时刻表\n";
    fputs(noww, fff);
    char now[200]="  航班号    起点站   终点站    起飞时间    到达时间   票价\n";
    fputs(now, fff);
    printf("%d\n",g->numVertexes);
    for (int j=1; j<=g->numVertexes; j++) {
        EdgeNode* p;
        p=g->arrays[j].edge;
        printf("out\n");
        while (p!=NULL) {
            printf("in\n");
                fputs("  ", fff);
            printf("in5\n");
                fputs(p->info.transportation, fff);
            printf("in6\n");
                fputs("    ", fff);
                fputs(g->arrays[j].data, fff);
            printf("in7\n");
                fputs("     ", fff);
                fputs(g->arrays[p->adjvex].data, fff);
            printf("in8\n");
                fputs("     ", fff);
                fputs(p->info.startTime, fff);
            printf("in9\n");
                fputs("     ", fff);
                fputs(p->info.endTime, fff);
            printf("in0\n");
                fputs("    ", fff);
                char buff[20];
                sprintf(buff, "%d",p->info.fee);
                fputs(buff, fff);
            printf("in67\n");
                fputs("\n", fff);
            printf("in2\n");
                p=p->link;
            printf("in3\n");
        }
    }
    fclose(fff);
}
