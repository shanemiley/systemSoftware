#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include "audit.h"

void audit()
{
    char buf[BUFSIZ];

    snprintf(buf, sizeof(buf), "auditctl -w /var/www/html -p rwxa");
    system(buf);
}