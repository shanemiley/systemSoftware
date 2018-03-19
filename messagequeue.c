 #include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <string.h>
#include <syslog.h>
#include <sys/stat.h>
#include <time.h>
#include <mqueue.h>

#include "backup.h"
#include "permission.h"
#include "logger.h"
#include "modified.h"
#include "audit.h"
#include "push_live.h"
#include "messagequeue.h"

void messagequeue()
{
 mqd_t mq;
  struct mq_attr queue_attributes;
  char buffer[1024 + 1];
  int terminate = 0;

  queue_attributes.mq_flags =0;
  queue_attributes.mq_maxmsg = 10;
  queue_attributes.mq_msgsize = 1024;
  queue_attributes.mq_curmsgs = 0;

  mq = mq_open("/dt228_queue",O_CREAT | O_RDONLY, 0644, &queue_attributes);
  
  while(1){
   
    
    ssize_t bytes_read;
    

    bytes_read = mq_receive(mq, buffer, 1024, NULL);
    buffer[bytes_read] = '\0';
    
    if(! strncmp(buffer, "success", strlen("success")))
		{
			logger("inside the if");
            sleep(200);
			
		} else if(! strncmp(buffer, "fail", strlen("fail"))){
		logger("inside the else if-----------------");
             sleep(200);
		
		
    }

    
    
    
     //sleep(200);
    // mq_close(mq);
    //mq_unlink("dt228_queue");
  }
}