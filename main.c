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
#include "push_live.h"

int main()
{

  logger("The backup and log program has begun");
  char *srcToBackup = "/home/shane/Desktop/SSAssignment/var/www/html/";
  char *destOfBackup = "/home/shane/Desktop/SSAssignment/liveBackup";

  char *src = "/home/shane/Desktop/SSAssignment/var/www/html/intranet";
  char *dest = "/home/shane/Desktop/SSAssignment/var/www/html/live";

  int pid = fork();

  if (pid > 0)
  {
    logger("Parent process created\n");
    logger("calling audit\n");

    if(audit()== 0){
      printf("audit executed successfully \n");
      logger("audit executed successfully \n");
    } else {
      printf("audit failed\n");
      logger("audit failed\n");
    }

    logger("after audit \n");

  
    exit(EXIT_SUCCESS);
  }
  // else if (pid == 0)
  // {
  //   logger("child process created\n");
  //   if (setsid() < 0)
  //   {
  //     logger("setsid fail\n");
  //     exit(EXIT_FAILURE);
  //   }
  //   logger("calling backup in child\n");
  //   backup(srcToBackup, destOfBackup, src, dest);
  //   // umask(0);
  //   // if (chdir("/") < 0)
  //   // {
  //   //   exit(EXIT_FAILURE);
  //   // }
  //   // int x;
  //   // for (x = sysconf(_SC_OPEN_MAX); x >= 0; x--)
  //   // {
  //   //   close(x);
  //   // }
  // }
  // int pid2 = fork();

  // if (pid2 > 0)
  // {
  //   printf("Parent process 2\n");
  
  //   exit(EXIT_SUCCESS);
  // }
  // else if (pid2 == 0)
  // {
  //   printf("child process 2\n");
  //   if (setsid() < 0)
  //   {
  //     exit(EXIT_FAILURE);
  //   }
  //    modified();


  //   // umask(0);
  //   // if (chdir("/") < 0)
  //   // {
  //   //   exit(EXIT_FAILURE);
  //   // }
  //   // int x;
  //   // for (x = sysconf(_SC_OPEN_MAX); x >= 0; x--)
  //   // {
  //   //   close(x);
  //   // }
  // }
  

  return 0;
}