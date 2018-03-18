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

void backup(char *src, char *dest)
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
            lock(src);

            char buf[BUFSIZ];

            printf("%s\n", src);
            printf("%s\n", dest);
            snprintf(buf, sizeof(buf), "cp --recursive %s %s", src, dest);
            system(buf);
            printf("done\n");
            unlock(src);
        }
        sleep(1);
    }
}
