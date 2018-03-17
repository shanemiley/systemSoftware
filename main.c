// Orphan Example
// The child process is adopted by init process, when parent process dies.
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <syslog.h>
#include <sys/stat.h>
#include <time.h>

#include "backup.h"
#include "permission.h"
#include "logger.h"
#include "modified.h"
#include "audit.h"

int main()
{

  char *srcToBackup = "/home/shane/Desktop/SSAssignment/var/www/html/";

  char *destOfBackup = "/home/shane/Desktop/SSAssignment/liveBackup";

  //char *destOfBackup = "/home/shane/Desktop/SSAssignment/liveBackup";
  modified();

  time_t now;
  struct tm newyear;
  double seconds;
  time(&now); /* get current time; same as: now = time(NULL)  */
  newyear = *localtime(&now);
  newyear.tm_hour = 20;
  newyear.tm_min = 21;
  newyear.tm_sec = 0;

    
   
   

  while (1)
  {
   

    time(&now);
    seconds = difftime(now, mktime(&newyear));
    printf("\n%.f", seconds);
    if (seconds == 0)
    {
      backup(srcToBackup, destOfBackup);
    }
    sleep(1);
  }
  return 0;
}