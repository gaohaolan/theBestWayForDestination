//
//  lessFee.h
//  theBestWayForDestination
//
//  Created by 高浩岚 on 2022/3/7.
//

#ifndef lessFee_h
#define lessFee_h

#include <stdio.h>
#include "createGraph.h"
#include "minimumOfTransits.h"

void dfs2(Graph* g, int startc, int endc, int visited[], int path[], int cnt, int* flag);  //会打印出来所有可能的路线！
void findAllPath2(Graph* g, char start[], char end[],int* flag);
void lessFee(Graph* g);
#endif /* lessFee_h */
