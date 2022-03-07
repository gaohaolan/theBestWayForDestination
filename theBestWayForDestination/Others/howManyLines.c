//
//  howManyLines.c
//  theBestWayForDestination
//
//  Created by 高浩岚 on 2022/2/19.
//

#include "howManyLines.h"
int howManyLines(void){
    FILE* fp=fopen("/Users/gaohaolan/高浩岚的本地文件/theBestWayForDestination/theBestWayForDestination/Text/trainTimetables.txt","r");
    int num=0;
    char buf[1024];
    while (fgets(buf,1024,fp) != NULL) {
        num++;
    }
    return num;
}
