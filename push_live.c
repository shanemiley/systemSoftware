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

//void pushLive(char *src, char *dest)
int main()
{
    char *src = "/home/shane/Desktop/SSAssignment/var/www/html/intranet";
    char *dest = "/home/shane/Desktop/SSAssignment/var/www/html/live";

    printf("Backing Up....\n");
    // system("rsync -avu %s %s", src, dest);
    char buf[BUFSIZ];
    snprintf(buf, sizeof(buf), "rsync -avu %s %s", src, dest);
    system(buf);

    printf("Back Up complete\n");
}
