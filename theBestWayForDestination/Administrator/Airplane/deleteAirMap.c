//
//  deleteAirMap.c
//  theBestWayForDestination
//
//  Created by 高浩岚 on 2022/3/11.
//

#include "deleteAirMap.h"
#include <stdlib.h>
#include "taskCompleted.h"
#include <string.h>
#include "reWriteair.h"

void deleteAirMap(Graph* gair){
    system("clear");  //清屏
    char lineNum[10];
    printf("\n\n\n\n\n请输入想要删除的飞机线路（“结束”来完成操作）：\n👉🏻");
    scanf("%s",lineNum);
    while (strcmp(lineNum,"结束")) {       //先排除没有的线路！
            for (int i=1; i<=gair->numVertexes; i++) {
                EdgeNode* e=gair->arrays[i].edge;
                int j=0;
                while (e!=NULL) {
                    if (strcmp(e->info.transportation,lineNum)) {
                        e=e->link;
                        j++;
                    }
                    else{
                        if ((e->link==NULL)&&(j<2)) {
                            if (j==1) {
                                free(e);
                                e=NULL;
                                gair->arrays[i].edge->link=NULL;
                            }
                            else{
                                free(e);
                                gair->arrays[i].edge=NULL;
                            }
            
                        }
                        else if ((e->link==NULL)&&(j>1)){
                            EdgeNode* n1=gair->arrays[i].edge;
                            
                            for (int t=1; t<j; t++) {
                                n1=n1->link;
                                //printf("inner\n");
                            }
                            n1->link=NULL;
                            free(e);
                            e=NULL;
                        }
                        else if ((e->link!=NULL)&&(j<2)){
                            if (j==0) {
                                gair->arrays[i].edge=e->link;
                                free(e);
                                e=NULL;
                            }
                            else{
                                gair->arrays[i].edge->link=e->link;
                                free(e);
                                e=NULL;
                            }
                        }
                        else if ((e->link!=NULL)&&(j>1)){
                            EdgeNode* n2=gair->arrays[i].edge;
                            for (int t=1; t<j; t++) {
                                n2=n2->link;
                            }
                            n2->link=e->link;
                            free(e);
                            e=NULL;
                        }
                        break;
                    }
                }
            }
            getchar();
            taskCompleted();     //对于飞机图的操作已经完成！现在再写入文件里
            
            
            system("clear");
            printf("\n\n\n\n\n请继续输入想要删除的飞机线路（“结束”来完成操作）：\n👉🏻");
            scanf("%s",lineNum);
        
    }
    getchar();
    
    reWriteair(gair);
    taskCompleted();
}
