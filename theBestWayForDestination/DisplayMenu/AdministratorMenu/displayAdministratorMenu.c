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
#include "checkCityListair.h"
#include "checkAirMap.h"
#include "createGraphair.h"
#include "modifyAirMap.h"
#include "modifyAirCityName.h"
#include "addCityair.h"
#include "deleteAirMap.h"
#include "addAirMap.h"
#include "deleteCityAir.h"




//显示管理员选单与操作。
void displayAdministratorMenu(Graph* g,Graph* gair){
    showAdministratorContents();
    char addACity[20]="新加火车城市";
    char deleteACity[20]="删去火车城市";
    char modifyACity[20]="更改火车城市";
    char checkTheCityList[20]="查看火车城市";
    char checkTheTrainMap[20]="查看火车线路";
    char addATrainMap[20]="新加火车线路";
    char deleteATrainMap[20]="删去火车线路";
    char exitMyAdministrator[20]="退出身份";
    char modifyATrainMap[20]="更改火车线路";
    char addACityair[20]="新加飞机城市";
    char deleteACityair[20]="删去飞机城市";
    char modifyACityair[20]="更改飞机城市";
    char checkTheCityListair[20]="查看飞机城市";
    char checkTheTrainMapair[20]="查看飞机线路";
    char addATrainMapair[20]="新加飞机线路";
    char deleteATrainMapair[20]="删去飞机线路";
    char modifyATrainMapair[20]="更改飞机线路";
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
        else if(strcmp(temp, checkTheCityListair)==0){
            checkCityListair();
        }
        else if(strcmp(temp, checkTheTrainMapair)==0){
            checkAirMap();
        }
        else if(strcmp(temp, modifyACityair)==0){
            modifyAirCityName(gair);
        }
        else if(strcmp(temp, modifyATrainMapair)==0){
            modifyAirMap(gair);
        }
        else if(strcmp(temp, addACityair)==0){
            addCityair(gair);
        }
        else if(strcmp(temp, addATrainMapair)==0){
            addAirMap(gair);
        }
        else if(strcmp(temp, deleteATrainMapair)==0){
            deleteAirMap(gair);
        }
        else if(strcmp(temp, deleteACityair)==0){
            deleteCityAir(gair);
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
