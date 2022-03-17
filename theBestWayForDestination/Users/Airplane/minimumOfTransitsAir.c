//
//  minimumOfTransitsAir.c
//  theBestWayForDestination
//
//  Created by 高浩岚 on 2022/3/12.
//

#include "minimumOfTransitsAir.h"
#define MADDD 200
#include "isReasonable.h"
#include "totalFee.h"
#include "theMiniTrans.h"
#include "compareTrans.h"
#include "minimumOfTransits.h"



void dfsair(Graph* g, int startc, int endc, int visited[], int path[], int cnt, int* flag){
    int v=startc;
    int f=endc;
    if (cnt>=2) {
        if (isReasonable(g, v, path[cnt-1], path[cnt-2])) {
            visited[v] = 1;
            path[cnt++] = v;
            if(v == f)
            {
                FILE* f1=fopen("/Users/gaohaolan/高浩岚的本地文件/theBestWayForDestination/theBestWayForDestination/testText/miniLinesChoiceair.txt", "a");
                for(int i = 0; i <cnt; i++)
                {
                    fprintf(f1, "%d",path[i]);
                    fputs(" ", f1);
                    *flag=1;
                    //printf("%d",path[i]);
                    //printf("站 ");
                    
                }
                //printf("\n");
                fputs("\n", f1);
                fclose(f1);
                //return;
            }
         
            for(EdgeNode* e = g->arrays[v].edge; e!=NULL; e = e->link)
            {
                if(!visited[e->adjvex])
                {
                    dfsair(g, e->adjvex, endc, visited, path, cnt, flag);
                                 
                }
            }
            visited[v]=0;               //回溯法
            cnt--;                  //易错！
        }
    }
    
    else{
        visited[v] = 1;
        path[cnt++] = v;
        if(v == f)
        {
            FILE* f2=fopen("/Users/gaohaolan/高浩岚的本地文件/theBestWayForDestination/theBestWayForDestination/testText/miniLinesChoiceair.txt", "a");
            for(int i = 0; i <cnt; i++)
            {
                fprintf(f2, "%d",path[i]);
                fputs(" ", f2);
                *flag=1;
               // printf("%d",path[i]);
                //printf("站 ");
            }
           // printf("\n");
            fputs("\n", f2);
            fclose(f2);
            //return;
        }
     
        for(EdgeNode* e = g->arrays[v].edge; e!=NULL; e = e->link)
        {
            if(!visited[e->adjvex])
            {
                dfsair(g, e->adjvex, endc, visited, path, cnt, flag);
                             
            }
        }
        visited[v]=0;               //回溯法
        cnt--;                  //易错！
    }
}

void findAllPathair(Graph* g, char start[], char end[],int* flag){
    int startc=findadj(start, g);
    int endc=findadj(end, g);
    
    if(!strcmp(start, end))
        printf("TEST%sNOTTHIS\n",start);  //正常情况下，不会出现在程序运行中...
    else
    {
        int visited[MADDD];
        for(int i=0;i<=g->numVertexes;i++)
        {
            visited[i]=0;
        }   //初始化数组visited的元素值为0，表示均未访问
        int path[MADDD];
        dfsair(g, startc, endc, visited, path, 0, flag);
    }
}

//返回u第一个邻接点
//int FirstAdjvex(Graph* gair,int u, int vised[])
//{
//    EdgeNode* p = gair->arrays[u].edge;
//    while(p!= NULL){
//        if(vised[p->adjvex])
//            p = p->link;     //跳过访问过的
//        else
//            return p->adjvex;
//    }
//    return 0;//表示未找到邻接点
//}
//
//
////返回相对于邻接点u的后一个邻接点
//int NextAdjvex(Graph* gair, int u, int v, int vised[])
//{
//    EdgeNode* p = gair->arrays[u].edge;
//    //先找到v
//    while(p!=NULL){
//        if(p->adjvex == v)
//            break;
//        else
//            p=p->link;
//    }
//    p = p->link;
//    while(p != NULL){           //查找下一个邻接点
//        if(vised[p->adjvex])
//            p = p->link;
//        else
//            return p->adjvex;
//    }
//    return 0;          //表示无下一邻接点
//}
//
//
////一次只能遍历一个连通分支(参考，类比DFS1)
//int BFS1(Graph* gair,int u, int vised[],int e,int* flag, int path[])
//{
//    int lu=1;
//    LinkQueue Q;//=(LinkQueue*)malloc(sizeof(LinkQueue));
//    printf("is it here?\n");
//    InitQueue(&Q);
//    //printf("is it here?\n");
//    //先访问再入队
//    vised[u] = 1;
//    //cout<<u+1<<" ";
//    printf("%s",gair->arrays[u].data);
//    printf("-->");
//    path[0]=u;
//    EnLinkQueue(&Q,u);
////    QNode* t=Q->front->next;
////    if (t==NULL) {
////        printf("的确是空的\n");
////    }
////    else
////        printf("非空\n");
//    //printf("%d\n",u);
//    while (!QueueEmpty(&Q)) {        //队非空
//        printf("gogogo\n");
//        u=ReadLinkQueue(&Q);
//        printf("next->%d\n",u);
//        path[lu++]=DeLinkQueue(&Q);
//
//        printf("ok\n");
//        for(int v = FirstAdjvex(gair, u, vised); v>=1; v=NextAdjvex(gair,u,v,vised)) {     //出队元素u 的所有相邻点入队
//            printf("%d\n",v);
//            if(!vised[v]){
//                vised[v]=1;
//                printf("%d\n",v);
//                //path[lu++]=v;
//                if (v==e) {
//                    //statements;
//                    //printf("%s",gair->arrays[v].data);
//                    *flag=1;
//                    printf("return\n");
//                    return (lu-1);
//                }
////                QNode* t=Q->front->next;
////                if (t==NULL) {
////                    printf("的确是空的!\n");
////                }
//                EnLinkQueue(&Q,v);
////                QNode* t1=Q->front;
////                if (t1==NULL) {
////                    printf("的确是空的\n");
////                }
////                while (t!=NULL) {
////                    printf("：：%d\n",t->data);
////                    t=t->next;
////                }
//                printf("in:%d\n",v);
//                //cout<<v+1<<" ";
//                printf("%s",gair->arrays[v].data);
//                printf("-->");
//            }
//        }
//        //printf("another loop\n");
//    }
//    return -1;
//}
//
//
////广度优先遍历
//int BFSTraverse1(Graph* gair, int s, int e, int* flag, int path[])
//{
//    int vised[FFFM];
//    //访问数组初始化
//    for(int i=0; i<=gair->numVertexes; i++){
//        vised[i]=0;
//    }
//
//    //不一定是连通图
//    printf("in bfs1\n");
//    return BFS1(gair,s,vised,e,flag,path)+1;
//
//
//    //cout<<endl;
//
//}


void minimumOfTransitsAir(Graph* gair){
    system("clear");  //清屏
    FILE* f=fopen("/Users/gaohaolan/高浩岚的本地文件/theBestWayForDestination/theBestWayForDestination/testText/miniLinesChoiceair.txt", "w");
    char cityStart[30];
    printf("\n\n\n\n\n请先输入想要出发的起始城市：\n👉🏻");
    scanf("%s",cityStart);
    printf("\n再输入抵达城市：\n👉🏻");
    char cityEnd[30];
    scanf("%s",cityEnd);
    system("clear");  //清屏
    printf("\n\n");
    for (int i=0; i<22; i++) {
        printf("*  ");
    }
    printf("*");
    printf("\n\n");
    printf("\t\t  所有中转航班次数最少方案：\n\n");
    int flag=0;
    findAllPathair(gair, cityStart, cityEnd, &flag);
    fclose(f);
    
    FILE* f1=fopen("/Users/gaohaolan/高浩岚的本地文件/theBestWayForDestination/theBestWayForDestination/testText/miniLinesChoiceair.txt", "r");
    int sum=0;
    char buf[1024];
    while (fgets(buf, 1024, f)!=NULL) {
        sum++;
    }
    //printf("%d",sum);
    fclose(f1);
    
    FILE* f2=fopen("/Users/gaohaolan/高浩岚的本地文件/theBestWayForDestination/theBestWayForDestination/testText/miniLinesChoiceair.txt", "r");
    int transArray[sum];
    char buff[1024];
    for (int i=0; i<sum; i++) {
        transArray[i]=compareTrans(fgets(buff, 1024, f2), gair);
    }
    fclose(f2);
    
//    for (int t=0; t<sum; t++) {
//        printf("%d\n",transArray[t]);
//    }
    
    
    int theMini=theMiniTrans(transArray,sum);
    //printf("MT:%d",theMini);
    int howRep=0;
    for (int t=0; t<sum; t++) {
        if (transArray[t]==theMini) {
            howRep++;
        }
    }
    
    int readLine[howRep];
    for (int t=0,b=0; t<sum; t++) {
        if (transArray[t]==theMini) {
            readLine[b]=t+1;
            b++;
        }
    }
    
    FILE* f3= fopen("/Users/gaohaolan/高浩岚的本地文件/theBestWayForDestination/theBestWayForDestination/Routes/routesAir.txt", "a");
    
    fputs("从", f3);
    fputs(cityStart, f3);
    fputs("到", f3);
    fputs(cityEnd, f3);
    fputs("的航班中转次数最少路线为：\n", f3);
    //重点关注这里！
    
    if (flag==0) {
        printf("🚫无法到达目的地！暂无线路可以抵达！\n");
        fputs("🚫无法到达目的地！暂无线路可以抵达！\n", f3);
    }
    
    for (int y=0; y<howRep; y++) {
        fputs("👉🏻", f3);
        FILE* f4= fopen("/Users/gaohaolan/高浩岚的本地文件/theBestWayForDestination/theBestWayForDestination/testText/miniLinesChoiceair.txt", "r");
        for (int i=1; i<readLine[y]; i++) {
            char inst[60];
            fgets(inst, 60, f4);
        }
        char itisit[60];
        fgets(itisit, 60, f4);  //所以说写代码的时候一定要注意连贯性和完整性！就像现在，我坐在图书馆里（刚吃完饭回来），都不知道接下来要实现什么功能了...
        //又想起来了！
        char* bu=strtok(itisit, " ");
        NumN* h=(NumN*)malloc(sizeof(NumN));   //无头节点！
        h->next=NULL;
        h->se=atoi(bu);
        NumN* r=h;
        int i=0;
        for ( ; bu!=NULL; i++) {
            bu=strtok(NULL, " \n");
            
            
            if (bu!=NULL) {
                NumN* e=(NumN*)malloc(sizeof(NumN));
                e->next=NULL;
                e->se=atoi(bu);
                //printf("%d\n",atoi(bu));
                r->next=e;
                r=e;
            }
            
        }
        r=h;
        int allCity=0;
        for ( ; r!=NULL; r=r->next) {
            allCity++;
        }
        r=h;
        //现在是把城市下标链表转换成线路表并且存储到最终文件里
        //printf("allcity:%d",allCity);
        int cityNumArray[allCity];
        for (int s=1; s<allCity; s++) {
            cityNumArray[s-1]=r->se;
            fputs(gair->arrays[r->se].data, f3);
            printf("%s",gair->arrays[r->se].data);
            fputs("-->", f3);
            printf("-->");
            r=r->next;
        }
        fputs(gair->arrays[r->se].data, f3);
        cityNumArray[allCity-1]=r->se;
        printf("%s",gair->arrays[r->se].data);
        fputs("\n出发时间为：", f3);
        r=h;
        char time[20];
        EdgeNode* e=gair->arrays[r->se].edge;
        for ( ; e!=NULL; e=e->link) {
            if (e->adjvex==r->next->se) {
                strcpy(time, e->info.startTime);
            }
        }
        fputs(time, f3);
        
        if (theMini==0) {
            fputs("\n中转城市为：", f3);
            fputs("无需中转城市！\n乘坐路线为：", f3);
            char lineInfo[20];
            e=gair->arrays[r->se].edge;
            for ( ; e!=NULL; e=e->link) {
                if (e->adjvex==r->next->se) {
                    strcpy(lineInfo, e->info.transportation);
                }
            }
            fputs(lineInfo, f3);
        }
        else{
           
            //现在来处理线路
            fputs("\n依次换乘的路线与城市为：", f3);
//            int transCityNum[40];  //transcitynum
//            int ini=0;
            for(int kun=1; kun<allCity-1; kun++){
                char t1[20];
                char t2[20];
                int a=cityNumArray[kun-1];
                int b=cityNumArray[kun];
                int c=cityNumArray[kun+1];
                //printf("ini:%d\n",c);
                for (EdgeNode* e=gair->arrays[b].edge; e!=NULL; e=e->link) {
                    if (e->adjvex==c) {
                        strcpy(t2, e->info.transportation);
                    }
                }
                for (EdgeNode* e=gair->arrays[a].edge; e!=NULL; e=e->link) {
                    if (e->adjvex==b) {
                        strcpy(t1, e->info.transportation);
                    }
                }
                if (strcmp(t1, t2)) {
//                    transCityNum[ini]=b;
//                    ini++;
                    fputs(t1, f3);
                    fputs("---", f3);
                    fputs(gair->arrays[b].data, f3);
                    fputs("---", f3);
                }
                if (kun==(allCity-2)) {
                    char lastLine[20];
                    EdgeNode* rr=gair->arrays[b].edge;
                    for ( ; rr!=NULL; rr=rr->link) {
                        //printf("b=%d,c=%d\n,==%d",b,c,rr->adjvex);
                        if ((rr->adjvex)==c) {
                            strcpy(lastLine, rr->info.transportation);
                            //printf("ok");
                        }
                    }
                    fputs(lastLine, f3);
                    //printf("%s",lastLine);
                }
            }
        }
        
        fputs("\n", f3);
        printf("\n");
        fclose(f4);
    }
    fputs("\n", f3);
    printf("\n");
    fclose(f3);
    
    
    
    printf("\n");
    for (int i=0; i<22; i++) {
        printf("*  ");
    }
    printf("*\n\n\n");
    printf("线路已保存至：“theBestWayForDestination/theBestWayForDestination/Routes/routesAir.txt”。\n\n按Enter键以返回...");
    //deleteTempFile
    remove("/Users/gaohaolan/高浩岚的本地文件/theBestWayForDestination/theBestWayForDestination/testText/miniLinesChoiceair.txt");
    getchar();
    getchar();
}
