#include<stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <syslog.h>
#include <sys/stat.h>
#include <time.h>
#include "backup.h"
#include "permission.h"

void backup(char * src, char * dest){
    lock(src);
  
   
    char buf[BUFSIZ];  
    
    printf("%s\n",src);
    printf("%s\n",dest);
    snprintf(buf, sizeof(buf), "cp --recursive %s %s",src,dest);
    system(buf);
    printf("done\n");
    unlock(src);
}





 