//
//  showAdministratorContents.c
//  theBestWayForDestination
//
//  Created by 高浩岚 on 2022/2/15.
//

#include "showAdministratorContents.h"
#include <stdlib.h>

void showAdministratorContents(void){
    system("clear");
    printf("\n\n");
    for (int i=0; i<22; i++) {
        printf("*  ");
    }
    printf("*");
    printf("\n");
    printf("\t\t\t   💁🏻‍♂️管理员 操作选单\n\n");
    printf("查看火车城市\t查看火车线路\t新加火车城市\t新加火车线路\n更改火车城市\t更改火车线路\t删去火车城市\t删去火车线路\n查看飞机城市\t查看飞机线路\t新加飞机城市\t新加飞机线路\n更改飞机城市\t更改飞机线路\t删去飞机城市\t删去飞机线路\n\n退出身份\n");
    printf("\n");
    for (int i=0; i<22; i++) {
        printf("*  ");
    }
    printf("*");
}
