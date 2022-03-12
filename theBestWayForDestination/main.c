//
//  main.c
//  theBestWayForDestination
//
//  Created by 高浩岚 on 2022/2/11.
//

#include <stdio.h>
#include <stdlib.h>
#include "displayMenu.h"
#include "createGraph.h"
#include "createGraphair.h"


int main(int argc, const char * argv[])
{
    //初始化，将已经预置的城市 分别 建图。
    remove("/Users/gaohaolan/高浩岚的本地文件/theBestWayForDestination/theBestWayForDestination/Routes/routes.txt");
    remove("/Users/gaohaolan/高浩岚的本地文件/theBestWayForDestination/theBestWayForDestination/Routes/routesAir.txt");
    Graph* g;
    Graph* gair;
    g=createGraph();
    gair=createGraphair();
    
    //显示选单与操作。
    displayMenu(g,gair);
    
    //结束作业展示，程序结束。
    system("clear");
    printgraph(g);
    printgraphair(gair);
    //printf("\n\n\n\n\n高浩岚 202013407047  \n谢谢林老师的指导😃\n\n\n\n\n");
    return 0;
}
