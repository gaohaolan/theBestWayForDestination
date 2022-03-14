//
//  lessTimeAir.h
//  theBestWayForDestination
//
//  Created by 高浩岚 on 2022/3/14.
//

#ifndef lessTimeAir_h
#define lessTimeAir_h

#include <stdio.h>
#include "createGraphair.h"


void dfsair2(Graph* gair, int startc, int endc, int visited[], int path[], int cnt, int* flag);  //会打印出来所有可能的路线！
void findAllPathair2(Graph* gair, char start[], char end[],int* flag);
void lessTimeAir(Graph* gair);
#endif /* lessTimeAir_h */
