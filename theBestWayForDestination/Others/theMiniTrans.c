//
//  theMiniTrans.c
//  theBestWayForDestination
//
//  Created by 高浩岚 on 2022/3/9.
//

#include "theMiniTrans.h"
#include "minimumOfTransits.h"

int theMiniTrans(int arrays[], int sum){
    int m=arrays[0];
    for(int k=0; k<sum; k++) {
        if (arrays[k]<m) {
            m=arrays[k];
        }
    }
    return m;
}
