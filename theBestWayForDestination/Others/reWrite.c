//
//  reWrite.c
//  theBestWayForDestination
//
//  Created by 高浩岚 on 2022/3/1.
//

#include "reWrite.h"
#include <string.h>
#include <stdlib.h>

void DFSaLine(GraphArrays g,int i,LNode* ln,PartLNode* pp,char nnname[])
{
    EdgeNode* p=g->arrays[i].edge;
    while(p)
    {
        if(!strcmp(p->info.transportation, nnname))
        {
            int findme=p->adjvex;
            LNode* rnan=ln;
            LNode* nan=(LNode *)malloc (sizeof (LNode));
            
            strcpy(nan->inf.endTime,p->info.endTime);
            strcpy(nan->inf.name, g->arrays[findme].data);
            strcpy(nan->inf.transportation, nnname);
            nan->inf.fee=p->info.fee;
            nan->next=NULL;
            rnan->next=nan;
            rnan=nan;
            
            PartLNode* rnpan=pp;
            PartLNode* npan=(PartLNode *)malloc (sizeof (PartLNode));
            strcpy(npan->partTimeTime, p->info.startTime);
            npan->next=NULL;
            rnpan->next=npan;
            rnpan=npan;
            DFSaLine(g,p->adjvex,rnan,rnpan,nnname);
        }
        p=p->link;//指向下一个节点
    }
}



void reWrite(Graph* g)
{
    FILE* kkk=fopen("/Users/gaohaolan/高浩岚的本地文件/theBestWayForDestination/theBestWayForDestination/testText/trainLineOrder.txt", "r");
    char kich[11];
    int ki=0;
    while (fgets(kich, 11, kkk)!=NULL) {
        ki++;
    }
    //printf("Pay attention:%d\n",ki);
    fclose(kkk);
    FILE* fff= fopen("/Users/gaohaolan/高浩岚的本地文件/theBestWayForDestination/theBestWayForDestination/Text/trainTimetables.txt", "w");
    char noww[200]="                    火车时刻表\n";
    fputs(noww, fff);
    char now[200]=" 火车车次    火车站名     到站时间       发车时间    票价\n";
    fputs(now, fff);
    FILE* reo1=fopen("/Users/gaohaolan/高浩岚的本地文件/theBestWayForDestination/theBestWayForDestination/testText/trainLineOrder.txt", "r");
    for (int i=1; i<=ki; i++) {
        char firstCity[20];
        char reoo1[20];
        fscanf(reo1, "%s",reoo1);   //不会读取每行最后的空格！
        //printf("%s",reoo1);
        char reooo1[10];
        fgets(reooo1, 20, reo1);   //负责读取每行最后的空格！
        //printf("%s",reoo1);
        for (int j=1; j<=g->numVertexes; j++) {
            int mark=0;
            EdgeNode* p;
            p=g->arrays[j].edge;
            while (p!=NULL) {
                //judge
                if ((!strcmp(p->info.transportation,reoo1))&&(p->isFirst==1)) {
                    strcpy(firstCity, g->arrays[j].data);
                    mark=1;
                    break;
                }
                p=p->link;
            }
            if (mark) {
                break;
            }
        }
      //  printf("%s\n",firstCity);
        PartLNode* pan;//有头节点
        pan=(PartLNode *)malloc (sizeof (PartLNode));
        strcpy(pan->partTimeTime,"000211000");
        pan->next=NULL;
        LNode* an;//无头节点
        an=(LNode *)malloc (sizeof (LNode));
        strcpy(an->inf.endTime, "------");
        strcpy(an->inf.name, firstCity);
        strcpy(an->inf.transportation, reoo1);
        an->inf.fee=0;
        an->next=NULL;
        int chuancan=findadj(firstCity, g);
    
        DFSaLine(g, chuancan, an, pan, reoo1);
        
        PartLNode* nnn=(PartLNode *)malloc (sizeof (PartLNode));
        strcpy(nnn->partTimeTime,"------");
        nnn->next=NULL;
        
        PartLNode* mmm=pan;
        while (mmm->next!=NULL) {
            mmm=mmm->next;
        }
        mmm->next=nnn;
        
//        LNode* tp;
//        tp=an;
//        while (tp)
//        {
//            printf ("%s  ",tp->inf.transportation);
//            printf ("%s  ",tp->inf.name);
//            printf ("%s  ",tp->inf.endTime);
//            printf ("%d  \n",tp->inf.fee);
//            tp=tp->next;
//        }
        
//        PartLNode* tpp;
//        tpp=pan->next;
//        while (tpp) {
//            printf ("%s  \n",tpp->partTimeTime);
//            tpp=tpp->next;
//        }
        
        LNode* fin1=an;
        PartLNode* fin2=pan;
        fin2=fin2->next;
        strcpy(fin1->inf.startTime,fin2->partTimeTime);
        fin1=fin1->next;
        while (fin1!=NULL){
            fin2=fin2->next;
            strcpy(fin1->inf.startTime,fin2->partTimeTime);
            fin1=fin1->next;
        }
        
        LNode* tp;
        tp=an;
        while (tp){
//            printf ("%s  ",tp->inf.transportation);
//            printf ("%s  ",tp->inf.name);
//            printf ("%s  ",tp->inf.endTime);
//            printf ("%s  ",tp->inf.startTime);
//            printf ("%d  \n",tp->inf.fee);
            
            fputs("   ", fff);
            fputs(tp->inf.transportation, fff);
            fputs("       ", fff);
            fputs(tp->inf.name, fff);
            fputs("\t", fff);
            fputs(tp->inf.endTime, fff);
            fputs("        ", fff);
            fputs(tp->inf.startTime, fff);
            fputs("    ", fff);
            char temm[10];
            sprintf(temm, "%d", tp->inf.fee);
            fputs(temm, fff);
            fputs("\n", fff);
            tp=tp->next;
        }
        //printf("hhh\n");
        
    }
    
    
    fclose(fff);
    fclose(reo1);
}
