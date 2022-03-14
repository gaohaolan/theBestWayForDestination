//
//  displayUsersMenu.c
//  theBestWayForDestination
//
//  Created by 高浩岚 on 2022/2/14.
//

#include "displayUsersMenu.h"
#include <string.h>
#include <stdlib.h>
#include "displayMenu.h"
#include "taskCompleted.h"
#include "showContents.h"
#include "showUsersContents.h"
#include "createGraph.h"
#include "checkCityList.h"
#include "checkTrainMap.h"
#include "howManyLines.h"
#include "minimumOfTransits.h"
#include "lessTime.h"
#include "lessFee.h"
#include "checkCityListair.h"
#include "checkAirMap.h"
#include "minimumOfTransitsAir.h"
#include "lessTimeAir.h"
#include "lessFeeAir.h"




//显示使用者选单与操作。
void displayUsersMenu(Graph* g,Graph* gair){
    showUsersContents();
    char checkTheCityList[20]="查看火车城市";
    char checkTheTrainMap[20]="查看火车线路";
    char exitMyUser[20]="退出身份";
    char traintrans[30]="中转火车次数最少";
    char planetrans[30]="中转飞机次数最少";
    char traintime[30]="火车耗时最少";
    char planetime[30]="飞机耗时最少";
    char trainfee[30]="火车费用最少";
    char planefee[30]="飞机费用最少";
    char checkTheCityListair[20]="查看飞机城市";
    char checkTheTrainMapair[20]="查看飞机线路";
    char temp[38];
    
    
    
    printf("👉🏻请输入想要进行的操作名称：\n");
    scanf("%s",temp);

    while (strcmp(temp, exitMyUser)!=0)
    {
        if (strcmp(temp, checkTheTrainMap)==0)
        {
            checkTrainMap();
        }
        else if (strcmp(temp, traintrans)==0)
        {
            minimumOfTransits(g);
        }
        else if (strcmp(temp, planetrans)==0)
        {
            minimumOfTransitsAir(gair);
        }
        else if (strcmp(temp, checkTheCityList)==0)
        {
            checkCityList();
        }
        else if (strcmp(temp, traintime)==0)
        {
            lessTime(g);
        }
        else if(strcmp(temp, planetime)==0)
        {
            lessTimeAir(gair);
        }
        else if (strcmp(temp, trainfee)==0)
        {
            lessFee(g);
        }
        else if(strcmp(temp, planefee)==0)
        {
            lessFeeAir(gair);
        }
        else if(strcmp(temp, checkTheCityListair)==0)
        {
            checkCityListair();
        }
        else if(strcmp(temp, checkTheTrainMapair)==0)
        {
            checkAirMap();
        }
        else
        {
            printf("🚫拼写有误，请重新输入：\n");
            scanf("%s",temp);
            continue;
        }
        showUsersContents();
        printf("👉🏻请继续输入想要进行的操作：\n");
        scanf("%s",temp);
    }
    printf("已成功退出 使用者 身份。👋🏻\n");
}
