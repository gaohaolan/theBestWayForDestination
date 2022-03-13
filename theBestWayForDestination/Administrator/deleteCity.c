//
//  deleteCity.c
//  theBestWayForDestination
//
//  Created by 高浩岚 on 2022/3/2.
//

#include "deleteCity.h"
#include "taskCompleted.h"
#include <string.h>
#include "reWrite.h"
#include "deleteTrainMap.h"
#include "createGraph.h"


void deleteCity(Graph* g){
    system("clear");  //清屏
    char deleteCN[30];
    printf("\n\n\n\n\n请输入想要删去的城市名称（“结束”来完成操作）：\n👉🏻");
    scanf("%s",deleteCN);
    while (strcmp(deleteCN,"结束")) {
        if(!isCityRepeat(g, deleteCN))
        {
            printf("\n🚫要删去的城市不存在！\n请重新输入...\n👉🏻");
            scanf("%s",deleteCN);
        }
        else
        {
            int whereCity=findadj(deleteCN, g);
            allL* a=(allL*)malloc(sizeof(allL));  //有头节点！
            strcpy(a->line, "HHH");
            a->link=NULL;
            allL* r=a;
            EdgeNode* e=g->arrays[whereCity].edge;
            while (e!=NULL) {
                allL* b=(allL*)malloc(sizeof(allL));
                strcpy(b->line, e->info.transportation);
                e=e->link;
                r->link=b;
                r=r->link;
            }
            r->link=NULL;
            for (int t=1; t<whereCity; t++) {
                e=g->arrays[t].edge;
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
            for (int m=whereCity+1; m<=g->numVertexes; m++) {
                e=g->arrays[m].edge;
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
                for (int i=1; i<=g->numVertexes; i++) {
                    EdgeNode* e=g->arrays[i].edge;
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
                                    g->arrays[i].edge->link=NULL;
                                }
                                else{
                                    free(e);
                                    g->arrays[i].edge=NULL;
                                }
                
                            }
                            else if ((e->link==NULL)&&(j>1)){
                                EdgeNode* n1=g->arrays[i].edge;
                                
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
                                    g->arrays[i].edge=e->link;
                                    free(e);
                                    e=NULL;
                                }
                                else{
                                    g->arrays[i].edge->link=e->link;
                                    free(e);
                                    e=NULL;
                                }
                            }
                            else if ((e->link!=NULL)&&(j>1)){
                                EdgeNode* n2=g->arrays[i].edge;
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
                //getchar();
                //printf("safe\n");
                
                FILE* fffp=fopen("/Users/gaohaolan/高浩岚的本地文件/theBestWayForDestination/theBestWayForDestination/testText/trainLineOrder.txt","r");
                int num=0;
                char buf[1024];
                while (fgets(buf,1024,fffp) != NULL) {
                    num++;
                }
                //printf("total:%d\n",num);
                fclose(fffp);
                
                FILE* ppp12=fopen("/Users/gaohaolan/高浩岚的本地文件/theBestWayForDestination/theBestWayForDestination/testText/trainLineOrder.txt","r");
                int whichLine=1;    //所删除线路在文件的哪一行
                for (int ji=1; ji<=num; ji++) {
                    char temp4[10];
                    fgets(temp4, 10, ppp12);
                    strtok(temp4, "\n\t\r ");
                    //printf("*%ss",lineNum);
                    //printf("%s*",temp4);
                    if (!strcmp(temp4, lineNum)) {
                        //printf("Same\n");
                        break;
                    }
                    else{
                        whichLine++;
                    }
                }
                fclose(ppp12);
                
                //printf("locate:%d\n",whichLine);

                FILE *ffffp=fopen("/Users/gaohaolan/高浩岚的本地文件/theBestWayForDestination/theBestWayForDestination/testText/trainLineOrder.txt","r");
                tempLineName* temp1=(tempLineName *)malloc (sizeof (tempLineName));  //有头节点
                strcpy(temp1->tempLN, "NO!");
                temp1->link=NULL;
                tempLineName* e1=temp1;
                for (int i=1; i<whichLine; i++) {
                    e1->link=(tempLineName *)malloc (sizeof (tempLineName));
                    char temp3[10];
                    fgets(temp3, 10, ffffp);
                    strtok(temp3, "\n\t\r ");
                    strcpy(e1->link->tempLN, temp3);
                    e1->link->link=NULL;
                    e1=e1->link;
                }
                char temp[10];
                fgets(temp, 10, ffffp);
                if (num!=whichLine) {
                    for (int j=whichLine; j<num; j++) {
                        e1->link=(tempLineName *)malloc (sizeof (tempLineName));
                        char tempp[10];
                        fgets(tempp, 10, ffffp);
                        strtok(tempp, "\n\t\r ");
                        strcpy(e1->link->tempLN, tempp);
                        e1->link->link=NULL;
                        e1=e1->link;
                    }
                }
                e1=temp1->link;
                fclose(ffffp);
                FILE *fffffp=fopen("/Users/gaohaolan/高浩岚的本地文件/theBestWayForDestination/theBestWayForDestination/testText/trainLineOrder.txt","w");
                while (e1!=NULL) {
                    fputs(e1->tempLN, fffffp);
                    fputs("\n", fffffp);   //换行符就这样子跟上了！
                    e1=e1->link;
                }
                fclose(fffffp);

                //同样的操作对于howManyPartLines.txt
                FILE *p4=fopen("/Users/gaohaolan/高浩岚的本地文件/theBestWayForDestination/theBestWayForDestination/testText/howManyPartLines.txt","r");
                tempLineNum* tempp1=(tempLineNum *)malloc (sizeof (tempLineNum));  //有头节点
                tempp1->tempLM=211985;
                tempp1->link=NULL;
                tempLineNum* ee1=tempp1;
                for (int i=1; i<whichLine; i++) {
                    ee1->link=(tempLineNum *)malloc (sizeof (tempLineNum));
                    char tempp3[10];
                    fgets(tempp3, 10, p4);
                    strtok(tempp3, "\n\t\r ");
                    int lala=atoi(tempp3);
                    ee1->link->tempLM=lala;
                    ee1->link->link=NULL;
                    ee1=ee1->link;
                }
                char temp9[10];
                fgets(temp9, 10, p4);
                if (num!=whichLine) {
                    for (int j=whichLine; j<num; j++) {
                        ee1->link=(tempLineNum *)malloc (sizeof (tempLineNum));
                        char temppp[10];
                        fgets(temppp, 10, p4);
                        strtok(temppp, "\n\t\r ");
                        int lala2=atoi(temppp);
                        ee1->link->tempLM=lala2;
                        ee1->link->link=NULL;
                        ee1=ee1->link;
                    }
                }
                ee1=tempp1->link;
                fclose(p4);
                FILE *p5=fopen("/Users/gaohaolan/高浩岚的本地文件/theBestWayForDestination/theBestWayForDestination/testText/howManyPartLines.txt","w");
                while (ee1!=NULL) {
                    fprintf(p5, "%d",ee1->tempLM);
                    fputs("\n", p5);   //换行符就这样子跟上了！
                    ee1=ee1->link;
                }
                fclose(p5);
                
                an=an->link;
            }
            
            //再删去城市结点！
            cityTempD* ctd=(cityTempD*)malloc(sizeof(cityTempD));  //有头节点！
            strcpy(ctd->city, "CCC");
            ctd->link=NULL;
            cityTempD* r1=ctd;
           
            for (int t=1; t<whereCity; t++) {
                cityTempD* b1=(cityTempD*)malloc(sizeof(cityTempD));
                strcpy(b1->city, g->arrays[t].data);
                r1->link=b1;
                r1=b1;
            }
            r1->link=NULL;
            for (int m=whereCity+1; m<=g->numVertexes; m++) {
                cityTempD* b1=(cityTempD*)malloc(sizeof(cityTempD));
                strcpy(b1->city, g->arrays[m].data);
                r1->link=b1;
                r1=b1;
            }
            r1->link=NULL;
            
            cityTempD* LLL=ctd->link;
            int cl=0;
            while (LLL)
            {
                //printf ("%s->",LLL->city);
                cl++;
                LLL=LLL->link;
            }
            
            FILE* o2o =fopen("/Users/gaohaolan/高浩岚的本地文件/theBestWayForDestination/theBestWayForDestination/Text/cityList.txt","w");
            cityTempD* dac=ctd->link;
            for (int fin=1; fin<=cl; fin++) {
                fputs(dac->city, o2o);
                fputs("\n", o2o);
                //printf("%s-",dac->city);
                dac=dac->link;
            }
            fclose(o2o);
            
            
            for (int gai=1; gai<=g->numVertexes; gai++) {
                EdgeNode* ling=g->arrays[gai].edge;
                while (ling!=NULL) {
                    if (ling->adjvex>=whereCity) {
                        ling->adjvex=(ling->adjvex)-1;
                    }
                    ling=ling->link;
                }
            }
            
            for (int zgai=0; zgai<(g->numVertexes-whereCity); zgai++) {
                strcpy(g->arrays[whereCity+zgai].data, g->arrays[whereCity+1+zgai].data);
            }
            
            for (int jxg=0; jxg<(g->numVertexes-whereCity); jxg++) {
                g->arrays[whereCity+jxg].edge=g->arrays[whereCity+jxg+1].edge;
            }
            
            //free(g->arrays[g->numVertexes].edge);
            g->arrays[g->numVertexes].edge=NULL;
            
            g->numVertexes--;
            
            
            
            
            
            
            reWrite(g);
            *g=*createGraph();
            getchar();
            taskCompleted();
            system("clear");
            printf("\n\n\n\n\n请继续输入想要删去的城市（“结束”来完成操作）：\n👉🏻");
            scanf("%s",deleteCN);
            
        }
    }
    getchar();
    //差点就错了，这个地方真的很易错！
    taskCompleted();
}
