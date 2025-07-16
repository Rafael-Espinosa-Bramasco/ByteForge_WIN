#include <stdio.h>

#ifndef BFINFO_H
#define BFINFO_H

static char* version = "1.1.0";
static char* verBuild = "16072025";
static char* verType = "Beta";

static inline void getAppInfo(void){
    printf("\n\tByte Forge\n");
    printf("\t  Version: %s\n",version);
    printf("\t  Build: %s\n",verBuild);
    printf("\t  Version type: %s\n\n",verType);
    return;
}

#endif // BFINFO_H