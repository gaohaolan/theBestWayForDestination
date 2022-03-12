//
//  modifyAirCityName.c
//  theBestWayForDestination
//
//  Created by 高浩岚 on 2022/3/11.
//

#include "modifyAirCityName.h"
#include <stdio.h>
#include <stdlib.h>
#include "taskCompleted.h"
#include "createGraph.h"
#include <string.h>
#include "createGraphair.h"
#include "reWriteair.h"


void modifyAirCityName(Graph* gair){
    FILE * pFile;
    pFile = fopen ("/Users/gaohaolan/高浩岚的本地文件/theBestWayForDestination/theBestWayForDestination/Text/cityListAir.txt","w");
    system("clear");  //清屏
    char cityString[30];
    printf("\n\n\n\n\n请分别输入想要变更名称的飞机城市原名称（“结束”来完成操作）：\n👉🏻");
    scanf("%s",cityString);
    while (strcmp(cityString,"结束")) {
        if(!isCityRepeatair(gair, cityString))
        {
            printf("\n🚫要更改的飞机城市名称不存在！\n请重新输入...\n👉🏻");
            scanf("%s",cityString);
        }
        else
        {
            system("clear");
            int i=findadjair(cityString, gair);
            printf("\n\n\n\n\n要将%s更改为：👉🏻",gair->arrays[i].data);
            char newCityName[20];
            scanf("%s",newCityName);
            strcpy(gair->arrays[i].data, newCityName);
            getchar();
            taskCompleted();
            system("clear");
            printf("\n\n\n\n\n请继续输入想要更改名称的飞机城市（“结束”来完成操作）：\n👉🏻");
            scanf("%s",cityString);
        }
    }
    getchar();
    for (int i=1; i<=gair->numVertexes; i++) {
        fputs(gair->arrays[i].data, pFile);
        fputc('\n', pFile);
    }
    fclose(pFile);
    reWriteair(gair);
    taskCompleted();
}
