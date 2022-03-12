//
//  showUsersContents.h
//  theBestWayForDestination
//
//  Created by 高浩岚 on 2022/2/15.
//

#include "showUsersContents.h"
#include <stdlib.h>
void showUsersContents(void){
    system("clear");
    printf("\n\n");
    for (int i=0; i<22; i++) {
        printf("*  ");
    }
    printf("*");
    printf("\n");
    printf("\t\t\t 👤使用者 操作选单\n\n\n");
    printf("中转火车次数最少\t中转飞机次数最少\t火车费用最少\n飞机费用最少\t\t火车耗时最少\t\t飞机耗时最少\n查看火车城市\t\t查看火车线路\t\t查看飞机城市\n查看飞机线路\n\n退出身份\n");
    printf("\n");
    for (int i=0; i<22; i++) {
        printf("*  ");
    }
    printf("*");
}
