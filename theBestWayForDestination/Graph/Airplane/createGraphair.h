//
//  createGraphair.h
//  theBestWayForDestination
//
//  Created by 高浩岚 on 2022/3/10.
//

#ifndef createGraphair_h
#define createGraphair_h

#include <stdio.h>
#include<stdlib.h>
#include <string.h>
#include "createGraph.h"
#define MAX 39


void printgraphair(Graph* g);
int isCityRepeatair(Graph* g,char vexs[]);
int findadjair(char vexs[],Graph* g);

Graph* createGraphair(void);
#endif /* createGraphair_h */
