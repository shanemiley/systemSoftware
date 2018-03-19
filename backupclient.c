#include <stdio.h>
#include <stdlib.h>
#include <mqueue.h>
#include <string.h>
 int main(int argc,char**argv){
    mqd_t mq;
    char buffer[1024];
    mq = mq_open("/backup_queue",O_WRONLY);

    printf("enter command \n");

    fflush(stdout);
    memset(buffer,0,1024);
    fgets(buffer,1024,stdin);
    mq_send(mq,buffer,1024,0);
    mq_close(mq);
    
   
 }



