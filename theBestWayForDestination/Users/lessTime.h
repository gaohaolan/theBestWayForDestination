//
//  lessTime.h
//  theBestWayForDestination
//
//  Created by 高浩岚 on 2022/3/7.
//

#ifndef lessTime_h
#define lessTime_h

#include <stdio.h>
#include "createGraph.h"
#include "minimumOfTransits.h"


void dfs3(Graph* g, int startc, int endc, int visited[], int path[], int cnt, int* flag);  //会打印出来所有可能的路线！
void findAllPath3(Graph* g, char start[], char end[],int* flag);
void lessTime(Graph* g);
#endif /* lessTime_h */
