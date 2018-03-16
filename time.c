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



 
int main()
{
    time_t now;
    struct tm newyear;
    double seconds;
    time(&now);  /* get current time; same as: now = time(NULL)  */
    newyear = *localtime(&now);
    newyear.tm_hour = 21; 
    newyear.tm_min = 23; 
    newyear.tm_sec = 0;
  
     time(&now);
     
     seconds = difftime(now,mktime(&newyear));
     printf("\n%.f", seconds);
    getchar();
 
    return 0;
}