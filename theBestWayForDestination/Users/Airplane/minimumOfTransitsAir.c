//
//  minimumOfTransitsAir.c
//  theBestWayForDestination
//
//  Created by 高浩岚 on 2022/3/12.
//

#include "minimumOfTransitsAir.h"
#define FFFM 200

//返回u第一个邻接点
int FirstAdjvex(Graph* gair,int u, int vised[])
{
    EdgeNode* p = gair->arrays[u].edge;
    while(p!= NULL){
        if(vised[p->adjvex])
            p = p->link;     //跳过访问过的
        else
            return p->adjvex;
    }
    return -1;//表示未找到邻接点
}


//返回相对于邻接点u的后一个邻接点
int NextAdjvex(Graph* gair, int u, int v, int vised[])
{
    EdgeNode* p = gair->arrays[u].edge;
    //先找到v
    while(p!=NULL){
        if(p->adjvex == v)
            break;
        else
            p=p->link;
    }
    p = p->link;
    while(p != NULL){           //查找下一个邻接点
        if(vised[p->adjvex])
            p = p->link;
        else
            return p->adjvex;
    }
    return -1;          //表示无下一邻接点
}


//一次只能遍历一个连通分支(参考，类比DFS1)
int BFS1(Graph* gair,int u, int vised[],int e,int* flag, int path[])
{
    int lu=1;
    LinkQueue* Q = NULL;
    InitQueue(Q);
    //先访问再入队
    vised[u] = 1;
    //cout<<u+1<<" ";
    //printf("%s",gair->arrays[u].data);
    //printf("-->");
    path[0]=u;
    Enqueue(Q,u);
    
    while (!IsEmpty(Q)) {        //队非空
        u=GetTop(Q);
        Dequeue(Q);
        for(int v = FirstAdjvex(gair, u, vised); v>=1; v=NextAdjvex(gair,u,v,vised)) {     //出队元素u 的所有相邻点入队
            if(!vised[v]){
                vised[v]=1;
                path[lu++]=v;
                if (v==e) {
                    //statements;
                    //printf("%s",gair->arrays[v].data);
                    *flag=1;
                    return lu;
                }
                Enqueue(Q,v);
                //cout<<v+1<<" ";
                //printf("%s",gair->arrays[v].data);
                //printf("-->");
            }
        }
    }
    return -1;
}


//广度优先遍历
int BFSTraverse1(Graph* gair, int s, int e, int* flag, int path[])
{
    int vised[FFFM];
    //访问数组初始化
    for(int i=0; i<=gair->numVertexes; i++){
        vised[i]=0;
    }
    
    //不一定是连通图
    
    return BFS1(gair,s,vised,e,flag,path)+1;
    
    
    //cout<<endl;
        
}


void minimumOfTransitsAir(Graph* gair){
    system("clear");  //清屏
    FILE* f=fopen("/Users/gaohaolan/高浩岚的本地文件/theBestWayForDestination/theBestWayForDestination/Routes/routesAir.txt", "a");
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
    printf("\t\t  中转航班次数最少方案：\n\n");
    fputs("从",f);
    fputs(cityStart, f);
    fputs("到",f);
    fputs(cityEnd, f);
    fputs("的航班中转次数最少路线为：\n👉🏻",f);
    
    int path[FFFM];
    int flag=0;
    int s=findadjair(cityStart, gair);
    int e=findadjair(cityEnd, gair);
    int sum=BFSTraverse1(gair, s, e, &flag,path);
    
    if (flag==0) {
        printf("\n\n🚫无法到达目的地！暂无线路可以抵达！\n");
        fputs("🚫无法到达目的地！暂无线路可以抵达！\n", f);
    }
    else{
        for (int i=1; i<sum; i++) {
            printf("%s",gair->arrays[path[i-1]].data);
            fputs(gair->arrays[path[i-1]].data, f);
            printf("-->");
        }
        printf("%s",gair->arrays[e].data);
        printf("\n");
        fputs("\n", f);
    }
    fputs("\n", f);
    fclose(f);
    
    printf("\n");
    for (int i=0; i<22; i++) {
        printf("*  ");
    }
    printf("*\n\n\n");
    printf("线路已保存至：“theBestWayForDestination/theBestWayForDestination/Routes/routesAir.txt”。\n\n按Enter键以返回...");
    getchar();
    getchar();
}
