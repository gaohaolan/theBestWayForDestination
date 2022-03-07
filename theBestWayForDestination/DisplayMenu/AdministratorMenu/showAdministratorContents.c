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
    printf("\t\t\t   管理员 操作选单\n\n");
    printf("\t查看城市\t查看线路\t新加城市\n\t新加线路\t更改城市\t更改线路\n\t删去城市\t删去线路\t退出身份\n\n");
    printf("\n");
    for (int i=0; i<22; i++) {
        printf("*  ");
    }
    printf("*");
}
