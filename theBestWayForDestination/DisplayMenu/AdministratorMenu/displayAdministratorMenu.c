//
//  displayAdministratorMenu.c
//  theBestWayForDestination
//
//  Created by 高浩岚 on 2022/2/14.
//

#include "displayAdministratorMenu.h"
#include <string.h>
#include <stdlib.h>
#include "displayMenu.h"
#include "addCity.h"
#include "taskCompleted.h"
#include "showContents.h"
#include "showAdministratorContents.h"
#include "createGraph.h"
#include "checkCityList.h"
#include "checkTrainMap.h"
#include "addTrainMap.h"
#include "howManyLines.h"
#include "modifyCityName.h"
#include "deleteTrainMap.h"
#include "deleteCity.h"
#include "modifyTrainMap.h"



//显示管理员选单与操作。
void displayAdministratorMenu(Graph* g){
    showAdministratorContents();
    char addACity[20]="新加城市";
    char deleteACity[20]="删去城市";
    char modifyACity[20]="更改城市";
    char checkTheCityList[20]="查看城市";
    char checkTheTrainMap[20]="查看线路";
    char addATrainMap[20]="新加线路";
    char deleteATrainMap[20]="删去线路";
    char exitMyAdministrator[20]="退出身份";
    char modifyATrainMap[20]="更改线路";
    char temp[38];
    
    printf("👉🏻请输入想要进行的操作名称：\n");
    scanf("%s",temp);

    while (strcmp(temp, exitMyAdministrator)!=0)
    {
        if (strcmp(temp, addACity)==0)
        {
            addCity(g);
        }
        else if (strcmp(temp, deleteACity)==0)
        {
            deleteCity(g);
        }
        else if (strcmp(temp, modifyACity)==0)
        {
            modifyCityName(g);
        }
        else if (strcmp(temp, checkTheTrainMap)==0)
        {
            checkTrainMap();
        }
        else if (strcmp(temp, checkTheCityList)==0)
        {
            checkCityList();
        }
        else if (strcmp(temp, addATrainMap)==0)
        {
            addTrainMap(g);
        }
        else if(strcmp(temp, deleteATrainMap)==0)
        {
            deleteTrainMap(g);
        }
        else if(strcmp(temp, modifyATrainMap)==0){
            modifyTrainMap(g);
        }
        else
        {
            printf("拼写有误，请重新输入：\n");
            scanf("%s",temp);
            continue;
        }
        showAdministratorContents();
        printf("👉🏻请继续输入想要进行的操作：\n");
        scanf("%s",temp);
    }
    printf("已成功退出 管理员 身份。👋🏻\n");
}
