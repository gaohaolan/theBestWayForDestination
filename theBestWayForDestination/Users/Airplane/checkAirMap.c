//
//  checkAirMap.c
//  theBestWayForDestination
//
//  Created by 高浩岚 on 2022/3/11.
//

#include "checkAirMap.h"
#include <stdlib.h>
#include <string.h>
#define MAX_LINE 100

void checkAirMap(void){
    system("clear");
    printf("\n\n");
    for (int i=0; i<22; i++) {
        printf("*  ");
    }
    printf("*");
    printf("\n\n");
    printf("\t\t\t🧾✈️ 所有航班清单\n\n  航班号   起点站   终点站   出发时间   到达时间   票价\n");
    
    char buf[MAX_LINE];  //缓冲区
    FILE *fp = fopen("/Users/gaohaolan/高浩岚的本地文件/theBestWayForDestination/theBestWayForDestination/Text/aircraftTimetables.txt","r");
    for (int j=1; j<=2; j++) {
            fgets(buf,MAX_LINE,fp);
        }
    while(fgets(buf,MAX_LINE,fp) != NULL){
         printf("%s",buf);
    }
    fclose(fp);
    
    printf("\n");
    for (int i=0; i<22; i++) {
        printf("*  ");
    }
    printf("*\n");
    printf("按Enter键以返回...");
    getchar();
    getchar();
}
