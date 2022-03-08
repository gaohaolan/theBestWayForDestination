//
//  minimumOfTransits.h
//  theBestWayForDestination
//
//  Created by 高浩岚 on 2022/3/7.
//

#ifndef minimumOfTransits_h
#define minimumOfTransits_h

#include <stdio.h>
#include "createGraph.h"
typedef struct NumN{
    int se;
    struct NumN* next;
}NumN;

void dfs1(Graph* g, int startc, int endc, int visited[], char path[], int cnt);
void findAllPath(Graph* g, char start[], char end[]);
void minimumOfTransits(Graph* g);
#endif /* minimumOfTransits_h */
