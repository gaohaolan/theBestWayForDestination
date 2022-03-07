//
//  addCity.c
//  theBestWayForDestination
//
//  Created by 高浩岚 on 2022/2/13.
//

#include "addCity.h"
#include <stdio.h>
#include <stdlib.h>
#include "taskCompleted.h"
#include "createGraph.h"
#include <string.h>

//新加城市
void addCity(Graph* g){
    system("clear");  //清屏
    //printf("\n\n\n\n\n操作成功！\n\n按Enter键以继续...");
    FILE * pFile;
    pFile = fopen ("/Users/gaohaolan/高浩岚的本地文件/theBestWayForDestination/theBestWayForDestination/Text/cityList.txt","a");
    char cityString[30];
    printf("\n\n\n\n\n请分别输入想要新加的城市（“结束”来完成操作）：\n👉🏻");
    scanf("%s",cityString);
    while (strcmp(cityString,"结束")) {
        if(isCityRepeat(g, cityString))
        {
            printf("\n🚫新加城市名称与已有城市名称重合！\n请重新输入...\n👉🏻");
            scanf("%s",cityString);
        }
        else
        {
            fputs(cityString, pFile);
            fputs("\n", pFile);
            g->numVertexes++;
            strcpy(g->arrays[g->numVertexes].data,cityString);
            g->arrays[g->numVertexes].edge = NULL;
            getchar();
            taskCompleted();
            system("clear");
            printf("\n\n\n\n\n请继续输入想要新加的城市（“结束”来完成操作）：\n👉🏻");
            scanf("%s",cityString);
        }
    }
    getchar();
    fclose(pFile);
    taskCompleted();
}
