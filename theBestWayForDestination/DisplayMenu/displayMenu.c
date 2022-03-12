//
//  displayMenu.c
//  theBestWayForDestination
//
//  Created by 高浩岚 on 2022/2/13.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "displayMenu.h"
#include "displayAdministratorMenu.h"
#include "taskCompleted.h"
#include "showContents.h"
#include "Password.h"
#include "createGraph.h"
#include "displayUsersMenu.h"

//首先要选择是使用者还是管理员。
void displayMenu(Graph* g, Graph* gair){
    showContents();
    char iAmUser[20]="使用者";
    char iAmAdministrator[20]="管理员";
    char exitMySystem[20]="退出系统";
    char temp[38];
    scanf("%s",temp);
    while (strcmp(temp, exitMySystem)!=0)
    {
        if (strcmp(temp, iAmAdministrator)==0)
        {
            password();
            char passwords[30];
            scanf("%s",passwords);
            if(strcmp(passwords, "5252")==0)
            {
                displayAdministratorMenu(g,gair);
                system("clear");
            }
            else
            {
                system("clear");
                printf("\n\n\n\n\n🚫管理员密码输入错误！\n\n按Enter键来重新登入...");
                getchar();
                getchar();  //"暂停页面"
            }
        }
        else if (strcmp(temp, iAmUser)==0)
        {
            FILE* F= fopen("/Users/gaohaolan/高浩岚的本地文件/theBestWayForDestination/theBestWayForDestination/Routes/routes.txt", "w");   //存放火车路线.txt
            FILE* FA= fopen("/Users/gaohaolan/高浩岚的本地文件/theBestWayForDestination/theBestWayForDestination/Routes/routesAir.txt", "w");      //存放飞机路线.txt
            displayUsersMenu(g,gair);
            fclose(F);
            fclose(FA);
            system("clear");
        }
        else
        {
            printf("🚫拼写有误，请重新输入：\n");
            scanf("%s",temp);
            continue;
        }
        showContents();
        
        scanf("%s",temp);
    }
    printf("已成功退出此系统。👋🏻\n");
}
