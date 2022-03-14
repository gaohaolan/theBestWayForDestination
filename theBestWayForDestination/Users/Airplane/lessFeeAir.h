//
//  lessFeeAir.h
//  theBestWayForDestination
//
//  Created by 高浩岚 on 2022/3/14.
//

#ifndef lessFeeAir_h
#define lessFeeAir_h
#include <stdio.h>
#include "createGraphair.h"


//void ShortestPath_DIJ2(Graph* gair, int v0, int D[], int Path[]);
void dfsair3(Graph* g, int startc, int endc, int visited[], int path[], int cnt, int* flag);
void Dijkstra(Graph* gair, char start[]);
void lessFeeAir(Graph* gair);
#endif /* lessFeeAir_h */
