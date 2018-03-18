#include <stdio.h>
#include <unistd.h>
#include <syslog.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/inotify.h>
#include <unistd.h>

#include "logger.h"

void logger(char *message)
{
    FILE *fp;

    time_t ltime;       /* calendar time */
    ltime = time(NULL); /* get current cal time */
    // printf("%s",asctime( localtime(&ltime) ) );

    char *user = getenv("USER");

    openlog("DT228Yr4", LOG_PID | LOG_CONS, LOG_USER);
    syslog(LOG_INFO, "%s", message);
    closelog();

    fp = fopen("LogEverythingOnServer.txt", "a+");
    fprintf(fp, "message: %s user: %s time: %s ", message, user, asctime(localtime(&ltime)));
    fclose(fp);
}