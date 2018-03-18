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

int main()
{
    
char *src = "/home/shane/Desktop/SSAssignment/var/www/html/intranet";
  char *dest = "/home/shane/Desktop/SSAssignment/var/www/html/live";
   logger("Pushing to live....\n");
    
    char buf[BUFSIZ];
    snprintf(buf, sizeof(buf), "rsync -avu %s %s -v > rsynclog.txt", src, dest);
    system(buf);

    logger("Push complete\n");
}
