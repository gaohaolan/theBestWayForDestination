//
//  addTrainMap.h
//  theBestWayForDestination
//
//  Created by 高浩岚 on 2022/2/18.
//

#ifndef addTrainMap_h
#define addTrainMap_h

#include <stdio.h>
#include "createGraph.h"
void addTrainMap(Graph* g);

typedef struct city123{
    char cityName[20];
    struct city123* link;
}city123;

#endif /* addTrainMap_h */
