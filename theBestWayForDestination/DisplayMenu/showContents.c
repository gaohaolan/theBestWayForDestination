//
//  showContents.c
//  theBestWayForDestination
//
//  Created by 高浩岚 on 2022/2/13.
//

#include "showContents.h"
#include <stdlib.h>
void showContents(void){
    system("clear");
    //printf("1");
    printf("\n\n");
    for (int i=0; i<22; i++) {
        printf("*  ");
    }
    printf("*");
    printf("\n\n\n\n\n");
    printf("\t\t🔎  最 优 出 行 方 案 推 荐 系 统\n\n\n\n\n");
    for (int i=0; i<22; i++) {
        printf("*  ");
    }
    printf("*");
    printf("\n\n以中文输入您的身份：使用者 还是 管理员\n或者是 退出系统？\n");
}
