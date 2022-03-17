//
//  addCityair.c
//  theBestWayForDestination
//
//  Created by 高浩岚 on 2022/3/11.
//

#include "addCityair.h"
#include <stdio.h>
#include <stdlib.h>
#include "taskCompleted.h"
#include "createGraphair.h"
#include <string.h>


void addCityair(Graph* gair){
    system("clear");  //清屏
    FILE * pFile;
    pFile = fopen ("/Users/gaohaolan/高浩岚的本地文件/theBestWayForDestination/theBestWayForDestination/Text/cityListAir.txt","a");
    char cityString[30];
    printf("\n\n\n\n\n请分别输入想要新加的飞机城市（“结束”来完成操作）：\n👉🏻");
    scanf("%s",cityString);
    while (strcmp(cityString,"结束")) {
        if(isCityRepeatair(gair, cityString))
        {
            printf("\n🚫新加飞机城市名称与已有城市名称重合！\n请重新输入...\n👉🏻");
            scanf("%s",cityString);
        }
        else
        {
            fputs(cityString, pFile);
            fputs("\n", pFile);
            gair->numVertexes++;
            strcpy(gair->arrays[gair->numVertexes].data,cityString);
            gair->arrays[gair->numVertexes].edge = NULL;
            getchar();
            taskCompleted();
            system("clear");
            printf("\n\n\n\n\n请继续输入想要新加的飞机城市（“结束”来完成操作）：\n👉🏻");
            scanf("%s",cityString);
        }
    }
    getchar();
    fclose(pFile);
    taskCompleted();
}
