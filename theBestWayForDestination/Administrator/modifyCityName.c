//
//  modifyCityName.c
//  theBestWayForDestination
//
//  Created by 高浩岚 on 2022/3/1.
//

#include "modifyCityName.h"
#include <stdio.h>
#include <stdlib.h>
#include "taskCompleted.h"
#include "createGraph.h"
#include <string.h>
#include "reWrite.h"


void modifyCityName(Graph* g){
    FILE * pFile;
    pFile = fopen ("/Users/gaohaolan/高浩岚的本地文件/theBestWayForDestination/theBestWayForDestination/Text/cityList.txt","w");
    system("clear");  //清屏
    char cityString[30];
    printf("\n\n\n\n\n请分别输入想要变更名称的火车城市原名称（“结束”来完成操作）：\n👉🏻");
    scanf("%s",cityString);
    while (strcmp(cityString,"结束")) {
        if(!isCityRepeat(g, cityString))
        {
            printf("\n🚫要更改的火车城市名称不存在！\n请重新输入...\n👉🏻");
            scanf("%s",cityString);
        }
        else
        {
            system("clear");
            int i=findadj(cityString, g);
            printf("\n\n\n\n\n要将%s更改为：👉🏻",g->arrays[i].data);
            char newCityName[20];
            scanf("%s",newCityName);
            strcpy(g->arrays[i].data, newCityName);
            getchar();
            taskCompleted();
            system("clear");
            printf("\n\n\n\n\n请继续输入想要更改名称的火车城市（“结束”来完成操作）：\n👉🏻");
            scanf("%s",cityString);
        }
    }
    getchar();
    for (int i=1; i<=g->numVertexes; i++) {
        fputs(g->arrays[i].data, pFile);
        fputc('\n', pFile);
    }
    fclose(pFile);
    //reWrite(g);
    taskCompleted();
}
