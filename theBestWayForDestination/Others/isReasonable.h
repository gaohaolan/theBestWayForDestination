//
//  isReasonable.h
//  theBestWayForDestination
//
//  Created by 高浩岚 on 2022/3/8.
//

#ifndef isReasonable_h
#define isReasonable_h

#include <stdio.h>
#include "createGraph.h"

typedef struct isRea{
    char start[20];
    char end[20];
    char line[20];
    struct isRea* next;
};

int isReasonable(int c, int b, int a);
#endif /* isReasonable_h */
