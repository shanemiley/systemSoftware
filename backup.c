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

void backup(char *srcToBackup, char *destOfBackup,char *srcIntra, char *destLive)
{

    time_t now;
    struct tm newyear;
    double seconds;
    time(&now); /* get current time; same as: now = time(NULL)  */
    newyear = *localtime(&now);
    newyear.tm_hour = 23;
    newyear.tm_min = 55;
    newyear.tm_sec = 0;

    while (1)
    {

        time(&now);
        seconds = difftime(now, mktime(&newyear));
        printf("\n%.f", seconds);
        if (seconds == 0)
        {
            lock(srcToBackup);

            char buf[BUFSIZ];

            logger("backing up....\n");
            snprintf(buf, sizeof(buf), "cp --recursive %s %s", srcToBackup, destOfBackup);
            system(buf);
            logger("backup done\n");

            unlock(srcToBackup);
            push_live(srcIntra,destLive);

        }
        sleep(1);
    }
}
