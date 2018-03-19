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
#include "push_live.h"
#include "logger.h"
#include "backupanytime.h"

void backupanytime()
{


char *srcToBackup = "/home/shane/Desktop/SSAssignment/var/www/html/";
  char *destOfBackup = "/home/shane/Desktop/SSAssignment/liveBackup";

  char *srcIntra = "/home/shane/Desktop/SSAssignment/var/www/html/intranet";
  char *destLive = "/home/shane/Desktop/SSAssignment/var/www/html/live";

    lock(srcToBackup);

    char buf[BUFSIZ];

    logger("backing up......................\n");
    snprintf(buf, sizeof(buf), "cp --recursive %s %s", srcToBackup, destOfBackup);
    system(buf);
    logger("backup done\n");

    unlock(srcToBackup);
    pushLive(srcIntra,destLive);

}
