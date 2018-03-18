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

  logger("The backup and log program has begun");
  char *srcToBackup = "/home/shane/Desktop/SSAssignment/var/www/html/";
  char *destOfBackup = "/home/shane/Desktop/SSAssignment/liveBackup";

  int pid = fork();

  if (pid > 0)
  {
    printf("Parent process 1\n");
    // printf("before audit\n");
    //  audit();
    // printf("after audit\n");
    // printf("before back\n");
    // backup(srcToBackup, destOfBackup);
    // printf("after back\n");
    sleep(2);
    exit(EXIT_SUCCESS);
  }
  else if (pid == 0)
  {
    printf("child process 1\n");
    if (setsid() < 0)
    {
      exit(EXIT_FAILURE);
    }

    //umask(0);
    // if (chdir("/") < 0)
    // {
    //   exit(EXIT_FAILURE);
    // }
    // int x;
    // for (x = sysconf(_SC_OPEN_MAX); x >= 0; x--)
    // {
    //   close(x);
    // }
   
  }
  int pid2 = fork();

  if (pid2 > 0)
  {
    printf("Parent process 2\n");
    // printf("before audit\n");
    //  audit();
    // printf("after audit\n");
    // printf("before back\n");
    // backup(srcToBackup, destOfBackup);
    // printf("after back\n");
    sleep(2);
    exit(EXIT_SUCCESS);
  }
  else if (pid2 == 0)
  {
    printf("child process 2\n");
    if (setsid() < 0)
    {
      exit(EXIT_FAILURE);
    }

    umask(0);
    if (chdir("/") < 0)
    {
      exit(EXIT_FAILURE);
    }
    int x;
    for (x = sysconf(_SC_OPEN_MAX); x >= 0; x--)
    {
      close(x);
    }
   
  }
  // printf("before mod\n");
  // modified();

  return 0;
}