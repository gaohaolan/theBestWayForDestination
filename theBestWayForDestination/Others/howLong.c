//
//  howLong.c
//  theBestWayForDestination
//
//  Created by 高浩岚 on 2022/2/20.
//

#include "howLong.h"
#include "string.h"
#include <stdlib.h>

int howLong(char stime[],char etime[]){
    char st[30];
    char et[30];
    strcpy(et, etime);
    strcpy(st, stime);
    char* et1=strtok(et,"：");
    int hour2=atoi(et1);
    //printf("%d\n",iet1);
    char* et2=strtok(NULL,"：");
    int minute2=atoi(et2);
    //printf("%s\n",et2);
    char* st1=strtok(st,"：");
    int hour1=atoi(st1);
    char* st2=strtok(NULL,"：");
    int minute1=atoi(st2);
    
    int ih,im;         //ih是小时差，im是分钟差；
    ih=hour2-hour1;
    im=minute2-minute1;
    if(im<0){
        im=60+im;
        ih--;
    }
    
    return ih*60+im;
}
