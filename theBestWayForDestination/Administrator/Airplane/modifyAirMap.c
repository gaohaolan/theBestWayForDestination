//
//  modifyAirMap.c
//  theBestWayForDestination
//
//  Created by 高浩岚 on 2022/3/11.
//

#include "modifyAirMap.h"
#include "taskCompleted.h"
#include <string.h>
#include "reWriteair.h"
#include "changeStartTimeAir.h"
#include "changeEndTimeAir.h"
#include "changePayAir.h"


void modifyAirMap(Graph* gair){
    system("clear");  //清屏
    char modifyLine[20];
    printf("\n\n\n\n\n请输入想要更改的航班：\n👉🏻");
    scanf("%s",modifyLine);
    system("clear");
    printf("\n\n\n\n\n输入想要对%s进行的操作：\n\n🕒更改出发时间\t🕔更改到达时间\t💵更改航班票价\n\n退出\n\n👉🏻",modifyLine);
    char option[30];
    scanf("%s",option);
    while (strcmp(option,"退出")) {
        if (!strcmp(option,"更改出发时间")) {
            changeStartTimeAir(gair, modifyLine);
        }
        else if(!strcmp(option,"更改到达时间")){
            changeEndTimeAir(gair, modifyLine);
        }
        else if(!strcmp(option,"更改航班票价")){
            changePayAir(gair, modifyLine);
        }
        system("clear");
        printf("\n\n\n\n\n继续输入想要对%s进行的操作：\n\n🕒更改出发时间\t🕔更改到达时间\t💵更改航班票价\n\n或者是 退出？\n\n👉🏻",modifyLine);
        scanf("%s",option);
    }
}
