#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <mqueue.h>
 #include <string.h>
#include "audit.h"
//#include "messagequeue.h"

int audit()
{
    mqd_t mq;
    char buffer[1024];
    mq = mq_open("/dt228_queue",O_WRONLY);

    char buf[BUFSIZ];

    snprintf(buf, sizeof(buf), "auditctl -w /var/www/html -p rwxa");

   system(buf);
   
       
       memset(buffer,0,1024);
      snprintf(buffer, 1024,"success");
       
       mq_send(mq,buffer,1024,0);
       mq_close(mq);
    return 0;
   

   
}