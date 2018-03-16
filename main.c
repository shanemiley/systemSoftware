// Orphan Example
// The child process is adopted by init process, when parent process dies.
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


 

int main()
{
    time_t now;
    struct tm newyear;
    double seconds;
    char *src = "home/shane/Desktop/SSAssignment/testsrc.txt"; 
    char *dest = "/home/shane/Desktop/SSAssignment/testdest.txt";
    time(&now);  /* get current time; same as: now = time(NULL)  */
    newyear = *localtime(&now);
    newyear.tm_hour = 15; 
    newyear.tm_min = 40; 
    newyear.tm_sec = 0;
  
     //time(&now);
   while(1) {
             sleep(1);
             
             time(&now);
             seconds = difftime(now,mktime(&newyear));
             printf("\n%.f", seconds);
             if (seconds == 0) {
               backup(src, dest);
	     }
     }
    return 0;
}