//
//  deleteCity.h
//  theBestWayForDestination
//
//  Created by 高浩岚 on 2022/3/2.
//

#ifndef deleteCity_h
#define deleteCity_h

#include <stdio.h>
#include "createGraph.h"

typedef struct allL{
    char line[10];
    struct allL* link;
}allL;

typedef struct cityTempD{
    char city[20];
    struct cityTempD* link;
}cityTempD;



void deleteCity(Graph* g);
#endif /* deleteCity_h */
