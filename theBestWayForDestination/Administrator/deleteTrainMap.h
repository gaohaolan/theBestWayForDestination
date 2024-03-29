//
//  deleteTrainMap.h
//  theBestWayForDestination
//
//  Created by 高浩岚 on 2022/3/1.
//

#ifndef deleteTrainMap_h
#define deleteTrainMap_h

#include <stdio.h>
#include "createGraph.h"

typedef struct tempLineName{
    char tempLN[10];
    struct tempLineName* link;
}tempLineName;

typedef struct tempLineNum{
    int tempLM;
    struct tempLineNum* link;
}tempLineNum;


void deleteTrainMap(Graph* g);
int isLineRepeat(Graph* g,char vexs[]);
#endif /* deleteTrainMap_h */
