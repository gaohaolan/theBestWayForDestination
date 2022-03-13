//
//  deleteCityAir.c
//  theBestWayForDestination
//
//  Created by 高浩岚 on 2022/3/11.
//

#include "deleteCityAir.h"
#include "taskCompleted.h"
#include <string.h>
#include "reWriteair.h"
#include "deleteAirMap.h"


void deleteCityAir(Graph* gair){
    system("clear");  //清屏
    char deleteCN[30];
    printf("\n\n\n\n\n请输入想要删去的飞机城市名称（“结束”来完成操作）：\n👉🏻");
    scanf("%s",deleteCN);
    while (strcmp(deleteCN,"结束")) {
        if(!isCityRepeatair(gair, deleteCN))
        {
            printf("\n🚫要删去的飞机城市不存在！\n请重新输入...\n👉🏻");
            scanf("%s",deleteCN);
        }
        else
        {     //搜集所有被删去的线路
            int whereCity=findadjair(deleteCN, gair);
            allL* a=(allL*)malloc(sizeof(allL));  //有头节点！
            strcpy(a->line, "HHH");
            a->link=NULL;
            allL* r=a;
            EdgeNode* e=gair->arrays[whereCity].edge;
            while (e!=NULL) {
                allL* b=(allL*)malloc(sizeof(allL));
                strcpy(b->line, e->info.transportation);
                e=e->link;
                r->link=b;
                r=r->link;
            }
            r->link=NULL;
            for (int t=1; t<whereCity; t++) {
                e=gair->arrays[t].edge;
                while (e!=NULL) {
                    if (e->adjvex==whereCity) {
                        allL* b=(allL*)malloc(sizeof(allL));
                        strcpy(b->line,e->info.transportation);
                        r->link=b;
                        r=r->link;
                        break;
                    }
                    else
                        e=e->link;
                }
            }
            r->link=NULL;
            for (int m=whereCity+1; m<=gair->numVertexes; m++) {
                e=gair->arrays[m].edge;
                while (e!=NULL) {
                    if (e->adjvex==whereCity) {
                        allL* b=(allL*)malloc(sizeof(allL));
                        strcpy(b->line,e->info.transportation);
                        r->link=b;
                        r=r->link;
                        break;
                    }
                    else
                        e=e->link;
                }
            }
            r->link=NULL;
            
            //print打印
            allL* L=a->link;
            int acl=0;
            while (L)
            {
                //printf ("%s->",L->line);
                acl++;
                L=L->link;
            }
//            printf ("\n");
            
            
            allL* an=a->link;
            for (int d=1; d<=acl; d++) {
                char lineNum[10];
                strcpy(lineNum, an->line);
                for (int i=1; i<=gair->numVertexes; i++) {
                    EdgeNode* e=gair->arrays[i].edge;
                    int j=0;
                    while (e!=NULL) {
                        if (strcmp(e->info.transportation,lineNum)) {
                            e=e->link;
                            j++;
                            //printf("不要走这里\n");
                        }
                        else{
                            //printf("Special7\n");
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
                                    //printf("inner\n");
                                }
                                //printf("out\n");
                                n2->link=e->link;
                                free(e);
                                e=NULL;
                            }
                            break;
                        }
                    }
                }
                
                //所有与被删除线路相关的边节点已经被删去
                
                an=an->link;
            }
            
            //再删去城市结点！
            cityTempD* ctd=(cityTempD*)malloc(sizeof(cityTempD));  //有头节点！
            strcpy(ctd->city, "CCC");
            ctd->link=NULL;
            cityTempD* r1=ctd;
           
            for (int t=1; t<whereCity; t++) {
                cityTempD* b1=(cityTempD*)malloc(sizeof(cityTempD));
                strcpy(b1->city, gair->arrays[t].data);
                r1->link=b1;
                r1=b1;
            }
            r1->link=NULL;
            for (int m=whereCity+1; m<=gair->numVertexes; m++) {
                cityTempD* b1=(cityTempD*)malloc(sizeof(cityTempD));
                strcpy(b1->city, gair->arrays[m].data);
                r1->link=b1;
                r1=b1;
            }
            r1->link=NULL;
            
            cityTempD* LLL=ctd->link;
            int cl=0;
            while (LLL)
            {
                cl++;
                LLL=LLL->link;
            }
            
            FILE* o2o =fopen("/Users/gaohaolan/高浩岚的本地文件/theBestWayForDestination/theBestWayForDestination/Text/cityListAir.txt","w");
            cityTempD* dac=ctd->link;
            for (int fin=1; fin<=cl; fin++) {
                fputs(dac->city, o2o);
                fputs("\n", o2o);
                dac=dac->link;
            }
            fclose(o2o);
            
            //printf("ok\n");
            for (int gai=1; gai<=gair->numVertexes; gai++) {
                EdgeNode* ling=gair->arrays[gai].edge;
                while (ling!=NULL) {
                    if (ling->adjvex>whereCity) {
                        ling->adjvex=(ling->adjvex)-1;
                    }
                    ling=ling->link;
                }
            }
            //printf("ok1\n");
            for (int zgai=0; zgai<(gair->numVertexes-whereCity); zgai++) {
                strcpy(gair->arrays[whereCity+zgai].data, gair->arrays[whereCity+1+zgai].data);
            }
            //printf("ok2\n");
            for (int jxg=0; jxg<(gair->numVertexes-whereCity); jxg++) {
                gair->arrays[whereCity+jxg].edge=gair->arrays[whereCity+jxg+1].edge;
            }
            //printf("ok3\n");
            //free(gair->arrays[gair->numVertexes].edge);
            gair->arrays[gair->numVertexes].edge=NULL;
            
            
            //printf("ok4\n");
            gair->numVertexes--; //可不能只--！
            
            //printf("ok5\n");
            reWriteair(gair);     //ADD1
            *gair=*createGraphair();     //ADD2
            getchar();
            taskCompleted();
            system("clear");
            printf("\n\n\n\n\n请继续输入想要删去的飞机城市（“结束”来完成操作）：\n👉🏻");
            scanf("%s",deleteCN);
            
        }
    }
    getchar();
    //太易错！       //是的，刚才又错了一次...
    taskCompleted();
}
