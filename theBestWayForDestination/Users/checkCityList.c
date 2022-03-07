//
//  checkCityList.c
//  theBestWayForDestination
//
//  Created by 高浩岚 on 2022/2/18.
//

#include "checkCityList.h"
#include <stdlib.h>


void checkCityList(void){
    int num = 0;
    system("clear");
    printf("\n\n");
    for (int i=0; i<22; i++) {
        printf("*  ");
    }
    printf("*");
    printf("\n\n");
    printf("\t\t  🧾🏠所有城市清单\n");
    FILE* fp;
    char str[100];
 
    fp = fopen("/Users/gaohaolan/高浩岚的本地文件/theBestWayForDestination/theBestWayForDestination/Text/cityList.txt", "r");
    
    while (fscanf(fp, "%s", str) != EOF)
    {
        if (num%3==0) {
            printf("\n\t\t%s\t",str);
        }
        else
            printf("%s\t", str);
        num++;
    }
    
    fclose(fp);
    printf("\n\n\n");
    for (int i=0; i<22; i++) {
        printf("*  ");
    }
    printf("*\n");
    printf("按Enter键以返回...");
    getchar();
    getchar();
}
