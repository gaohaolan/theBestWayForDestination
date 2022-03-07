//
//  modifyTrainMap.c
//  theBestWayForDestination
//
//  Created by 高浩岚 on 2022/3/3.
//

#include "modifyTrainMap.h"
#include "taskCompleted.h"
#include <string.h>
#include "reWrite.h"
#include "deleteTrainMap.h"
#include "changeStartTime.h"
#include "changeEndTime.h"
#include "changePay.h"

void modifyTrainMap(Graph* g){
    system("clear");  //清屏
    char modifyLine[20];
    printf("\n\n\n\n\n请输入想要更改的线路：\n👉🏻");
    scanf("%s",modifyLine);
    while (!isLineRepeat(g, modifyLine)) {
        system("clear");
        printf("\n\n\n\n\n🚫线路不存在！请重新输入想要更改的线路：\n👉🏻");
        scanf("%s",modifyLine);
    }
    system("clear");
    printf("\n\n\n\n\n输入想要对%s进行的操作：\n更改发车时间\t更改到站时间\t更改区间票价\n退出\n\n👉🏻",modifyLine);
    char option[30];
    scanf("%s",option);
    while (strcmp(option,"退出")) {
        if (!strcmp(option,"更改发车时间")) {
            changeStartTime(g, modifyLine);
        }
        else if(!strcmp(option,"更改到站时间")){
            changeEndTime(g, modifyLine);
        }
        else if(!strcmp(option,"更改区间票价")){
            changePay(g, modifyLine);
        }
        system("clear");
        printf("\n\n\n\n\n继续输入想要对%s进行的操作：\n\n更改发车时间\t更改到站时间\t更改区间票价\n或者是 退出？\n\n👉🏻",modifyLine);
        scanf("%s",option);
    }
}
