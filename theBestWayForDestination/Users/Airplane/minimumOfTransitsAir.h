//
//  minimumOfTransitsAir.h
//  theBestWayForDestination
//
//  Created by 高浩岚 on 2022/3/12.
// t

#ifndef minimumOfTransitsAir_h
#define minimumOfTransitsAir_h

#include <stdio.h>
#include "createGraphair.h"
#include "Queue.h"



void dfsair(Graph* g, int startc, int endc, int visited[], int path[], int cnt, int* flag);
void findAllPathair(Graph* g, char start[], char end[],int* flag);

////BFS
//int FirstAdjvex(Graph* gair,int u, int vised[]);
//int NextAdjvex(Graph* gair, int u, int v, int vised[]);
//int BFS1(Graph* gair,int u, int vised[],int e, int* flag, int path[]);
//int BFSTraverse1(Graph* gair, int s, int e, int* flag, int path[]);
void minimumOfTransitsAir(Graph* gair);
#endif /* minimumOfTransitsAir_h */

