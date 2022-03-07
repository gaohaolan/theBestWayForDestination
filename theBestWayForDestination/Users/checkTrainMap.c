//
//  checkTrainMap.c
//  theBestWayForDestination
//
//  Created by 高浩岚 on 2022/2/18.
//

#include "checkTrainMap.h"
#include <stdlib.h>
#include <string.h>
#define MAX_LINE 100


void checkTrainMap(void){
    system("clear");
    printf("\n\n");
    for (int i=0; i<22; i++) {
        printf("*  ");
    }
    printf("*");
    printf("\n");
    printf("\t\t   🧾🚉所有车次清单\n火车车次   火车站名   到站时间      发车时间    票价\n");
    
    char buf[MAX_LINE];  //缓冲区
    FILE *fp = fopen("/Users/gaohaolan/高浩岚的本地文件/theBestWayForDestination/theBestWayForDestination/Text/trainTimetables.txt","r");
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
