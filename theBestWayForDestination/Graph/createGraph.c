//
//  createGraph.c
//  theBestWayForDestination
//
//  Created by 高浩岚 on 2022/2/15.
//

#include "createGraph.h"
#include "howManyLines.h"
#include "howLong.h"

int findadj(char vexs[],Graph* g)   //找到城市存放的下标
{
    int i;
    for(i=1;i<=g->numVertexes;i++)
    {
        if(strcmp(vexs,g->arrays[i].data)==0)
            break;
    }
    return i;
}

int isCityRepeat(Graph* g,char vexs[]){   //城市是否有重复?
    for (int i=1; i<=g->numVertexes; i++) {
        if (!strcmp(g->arrays[i].data,vexs)) {
            return 1;
        }
    }
    return 0;
}

//预先从文件中建图！
Graph* createGraph(void){
    Graph* g1;
    g1=(Graph*)malloc(sizeof(Graph));
    g1->numEdges=0;
    g1->numVertexes=0;

    FILE* fp;
    char str[30];

    fp = fopen("/Users/gaohaolan/高浩岚的本地文件/theBestWayForDestination/theBestWayForDestination/Text/cityList.txt", "r");
    
    while (fscanf(fp, "%s", str) != EOF)
    {
        g1->numVertexes++;
        strcpy(g1->arrays[g1->numVertexes].data,str);               //这里的结构数组vexs[]下标从1开始!
        //printf("%s-",g1->arrays[g1->numVertexes].data);
        g1->arrays[g1->numVertexes].edge=NULL;
        //printf("%s-",g1->arrays[g1->numVertexes].data);
    }
    fclose(fp);
    
//初始化边节点信息。    ！！！易错！正在改正，不管怎样，还是要感谢胡奥！
    int lines=howManyLines();
    //printf("%d\n",lines);
    FILE* fp1=fopen("/Users/gaohaolan/高浩岚的本地文件/theBestWayForDestination/theBestWayForDestination/Text/trainTimetables.txt", "r");
    char haolei[1024];
    fgets(haolei,1024,fp1);
    fgets(haolei,1024,fp1);
    FILE* fp2=fopen("/Users/gaohaolan/高浩岚的本地文件/theBestWayForDestination/theBestWayForDestination/testText/howManyPartLines.txt", "r");
    char jiayou[200];
    
    char startTime1[200];
    char endTime1[200];
    char transline1[100];
    int fee1;
    char firstname[200];
    
    char startTime2[200];
    char endTime2[200];
    char transline2[100];
    int fee2=0;
    char enddname[200];
    
    for (int i=0; i<lines-2; ) {
        fgets(jiayou, 20, fp2);
        //printf("%s-",jiayou);
        int jiayou2=atoi(jiayou);
        //printf("line:%d\n",jiayou2);
        fgets(haolei, 1024, fp1);
        i++;
        char *temp = strtok(haolei,"\n\t\r ");
        strcpy(transline1,temp);
        //printf("%s\n",transline1);
        temp = strtok(NULL,"\n\t\r ");
        strcpy(firstname,temp);
        //printf("%s\n",firstname);
        temp = strtok(NULL,"\n\t\r ");
        strcpy(endTime1,temp);
        //printf("%s\n",endTime1);
        temp = strtok(NULL,"\n\t\r ");
        strcpy(startTime1,temp);
        //printf("%s\n",startTime1);
        temp = strtok(NULL,"\n\t\r ");
        //printf("加油1\n");
        //printf("%s",temp);
        //printf("加油2\n");
        fee1=atoi(temp);
       // printf("%s",temp);
       // printf("%d\n",fee1);
       // printf("加油3\n");
        int flag=0;
        
        for (int j=1; j<=jiayou2-1; j++) {
            fgets(haolei,1024,fp1);
            i++;
            char *temp1 = strtok(haolei,"\n\t\r ");
            strcpy(transline2,temp1);
            //printf("%s\n",transline2);
            temp1 = strtok(NULL,"\n\t\r ");
            strcpy(enddname,temp1);
           // printf("%s后\n",enddname);
            temp1 = strtok(NULL,"\n\t\r ");
            strcpy(endTime2,temp1);
            //printf("%s\n",endTime2);
            temp1 = strtok(NULL,"\n\t\r ");
            strcpy(startTime2,temp1);
            //printf("%s\n",startTime2);
            temp1 = strtok(NULL,"\n\t\r ");
            fee2=atoi(temp1);
            //printf("%d\n",fee2);
            
            int firstnum=findadj(firstname, g1);
            int endnum=findadj(enddname, g1);
            //printf("%d\n",firstnum);
            //printf("%d\n",endnum);
           
            EdgeNode *p, *b;
            b=(EdgeNode*)malloc(sizeof(EdgeNode));
            b->adjvex=endnum;
          
             int pparttime=howLong(startTime1,endTime2);
             strcpy(b->info.endTime,endTime2);
             b->info.partTime=pparttime;
             strcpy(b->info.startTime,startTime1);
             b->info.fee=fee2;
             strcpy(b->info.transportation,transline1);
             b->link=NULL;
            if (flag==0) {
                flag=1;
                b->isFirst=1;
            }
            else
                b->isFirst=0;
            //链表追加结点
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
            
            
            strcpy(startTime1, startTime2);
            strcpy(endTime1, endTime2);
            fee1=fee2;
            strcpy(transline1, transline2);
            strcpy(firstname, enddname);
        }
    }
    fclose(fp1);
    fclose(fp2);
    return g1;
}



//图（城市）的邻接表输出
void printgraph(Graph* g){
    int i,k;
    EdgeNode* p;
    printf("———时刻表————\n");
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
            printf("%s",p->info.transportation);
            printf("%s",g->arrays[k].data);
            
            if(p->link!=NULL)
               printf("  ->");
            p=p->link;
        }
        printf("\n");
    }
    printf("————————————\n");
}
