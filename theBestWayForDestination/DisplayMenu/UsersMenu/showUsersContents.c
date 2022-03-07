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
    printf("\t\t\t   使用者 操作选单\n\n");
    printf("\t\t查看城市\n\t\t查看线路\n\t\t退出身份\n\n");
    printf("\n");
    for (int i=0; i<22; i++) {
        printf("*  ");
    }
    printf("*");
}
