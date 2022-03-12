//
//  createGraphair.c
//  theBestWayForDestination
//
//  Created by 高浩岚 on 2022/3/10.
//

#include "createGraphair.h"
#include "howLong.h"

int findadjair(char vexs[],Graph* g)   //找到城市存放的下标
{
    int i;
    for(i=1;i<=g->numVertexes;i++)
    {
        if(strcmp(vexs,g->arrays[i].data)==0)
            break;
    }
    return i;
}


int isCityRepeatair(Graph* g,char vexs[]){   //城市是否有重复?
    for (int i=1; i<=g->numVertexes; i++) {
        if (!strcmp(g->arrays[i].data,vexs)) {
            return 1;
        }
    }
    return 0;
}


//预先从文件中建图！
Graph* createGraphair(void){
    
    Graph* g1;
    g1=(Graph*)malloc(sizeof(Graph));
    g1->numEdges=0;
    g1->numVertexes=0;

    FILE* fp;
    char str[30];
    
    fp = fopen("/Users/gaohaolan/高浩岚的本地文件/theBestWayForDestination/theBestWayForDestination/Text/cityListAir.txt", "r");
    
    while (fscanf(fp, "%s", str) != EOF)
    {
        //getchar();
        g1->numVertexes++;
        strcpy(g1->arrays[g1->numVertexes].data,str);               //这里的结构数组vexs[]下标从1开始!
        //printf("%s-",g1->arrays[g1->numVertexes].data);
        g1->arrays[g1->numVertexes].edge=NULL;
        //printf("%s\n",g1->arrays[g1->numVertexes].data);
    }
    fclose(fp);
    
//初始化边节点信息。    ！！！易错！正在改正，不管怎样，还是要感谢胡奥！
    //int lines=howManyLines();
    //printf("%d\n",lines);
    FILE* fp1=fopen("/Users/gaohaolan/高浩岚的本地文件/theBestWayForDestination/theBestWayForDestination/Text/aircraftTimetables.txt", "r");
    char haolei[1024];
    fgets(haolei,1024,fp1);
    //printf("%s",haolei);
    fgets(haolei,1024,fp1);
    //printf("%s",haolei);
//    FILE* fp2=fopen("/Users/gaohaolan/高浩岚的本地文件/theBestWayForDestination/theBestWayForDestination/testText/howManyPartLines.txt", "r");
    //char jiayou[200];
    
    char startTime[200];
    char endTime[200];
    char transline[100];
    int fee;
    char firstname[200];
    char enddname[200];
    
//    char startTime2[200];
//    char endTime2[200];
//    char transline2[100];
//    int fee2=0;
//    char enddname[200];
    
    while (fgets(haolei, 1024, fp1)!=NULL) {
        
        //printf("%s-",jiayou);
       
        //printf("line:%d\n",jiayou2);
        //printf("ok\n");
        char *temp = strtok(haolei,"\n\t\r ");
        //printf("here?\n");
        strcpy(transline,temp);
        //printf("%s\n",transline);
        temp = strtok(NULL,"\n\t\r ");
        strcpy(firstname,temp);
        //printf("%s\n",firstname);
        temp = strtok(NULL,"\n\t\r ");
        strcpy(enddname,temp);
        //printf("%s\n",enddname);
        temp = strtok(NULL,"\n\t\r ");
        strcpy(startTime,temp);
        //printf("%s\n",startTime);
        temp = strtok(NULL,"\n\t\r ");
        strcpy(endTime,temp);
        //printf("%s\n",endTime);
        temp = strtok(NULL,"\n\t\r ");
        //printf("加油1\n");
        //printf("%s",temp);
        //printf("加油2\n");
        fee=atoi(temp);
       // printf("%s",temp);
        //printf("%d\n",fee);
       // printf("加油3\n");
       // int flag=0;
            
        int firstnum=findadjair(firstname, g1);
        int endnum=findadjair(enddname, g1);
            //printf("%d\n",firstnum);
            //printf("%d\n",endnum);
           
        EdgeNode *p, *b;
        b=(EdgeNode*)malloc(sizeof(EdgeNode));
        b->adjvex=endnum;
        
        int pparttime=howLong(startTime,endTime);
        //printf("ok?\n");
        strcpy(b->info.endTime,endTime);
        b->info.partTime=pparttime;
        strcpy(b->info.startTime,startTime);
        b->info.fee=fee;
        strcpy(b->info.transportation,transline);
        b->link=NULL;
        //链表追加结点
        //printf("ok?\n");
        p=g1->arrays[firstnum].edge;
        if(p!=NULL)
        {
            while(p->link!=NULL)
                p=p->link;
                p->link=b;         //巧妙！安在最后面！
            }
        else
            g1->arrays[firstnum].edge=b;
        
        g1->numEdges++;     //边数增加1
    }
    fclose(fp1);
    //fclose(fp2);
    return g1;
}



//图（城市）的邻接表输出
void printgraphair(Graph* g){
    int i,k;
    EdgeNode* p;
    printf("———飞机时刻表————\n");
    //printf("%s-",g->arrays[1].data);
    for(i=1;i<=g->numVertexes;i++)
    {
        printf("%s  ->",g->arrays[i].data);
        p=g->arrays[i].edge;
        while(p!=NULL)
        {
            
            k=p->adjvex;
            //printf("%2d",p->adjvex);
            printf("  %s e-s ",p->info.endTime);
            printf("%s   ",p->info.startTime);
            printf("%s ",p->info.transportation);
            printf("%s",g->arrays[k].data);
            
            if(p->link!=NULL)
               printf("  ->");
            p=p->link;
        }
        printf("\n");
    }
    printf("————————————\n");
}

