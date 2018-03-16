#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include "permission.h"

void lock(char * src){
    char mode[] = "0777";
    char* buf = src;
    int i;
    i = strtol(mode, 0, 8);

    chmod(buf,i);


}
void unlock(char * src){
    char mode[] = "0777";
    char* buf = src;
    int i;
    i = strtol(mode, 0, 8);

    chmod(buf,i);


}