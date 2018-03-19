// Orphan Example
// The child process is adopted by init process, when parent process dies.
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <syslog.h>
#include <sys/stat.h>
#include <string.h>
#include <time.h>
#include <mqueue.h>

#include "backup.h"
#include "permission.h"
#include "logger.h"
#include "modified.h"
#include "audit.h"
#include "push_live.h"
#include "messagequeue.h"
#include "backupanytime.h"

void backupmessagequeue(){
  logger("inside bakup mess q");
 mqd_t mq;
  struct mq_attr queue_attributes;
  char buffer[1024 + 1];
  int terminate = 0;

  queue_attributes.mq_flags =0;
  queue_attributes.mq_maxmsg = 10;
  queue_attributes.mq_msgsize = 1024;
  queue_attributes.mq_curmsgs = 0;

  mq = mq_open("/backup_queue",O_CREAT | O_RDONLY, 0644, &queue_attributes);
  logger("here");
  do{

    ssize_t bytes_read;
    bytes_read = mq_receive(mq, buffer, 1024, NULL);
    
    
    buffer[bytes_read] = '\0';
    if(! strncmp(buffer, "backup", strlen("backup")))
		{

			logger("backup and push was called");
      backupanytime();
      
      
			
		} 
    //buffer[bytes_read] = 'overwrite';
    
  }while(1);
}
int main()
{


  logger("The backup and log program has begun");
  char *srcToBackup = "/home/shane/Desktop/SSAssignment/var/www/html/";
  char *destOfBackup = "/home/shane/Desktop/SSAssignment/liveBackup";

  char *src = "/home/shane/Desktop/SSAssignment/var/www/html/intranet";
  char *dest = "/home/shane/Desktop/SSAssignment/var/www/html/live";

  int mqfork = fork();
  if (mqfork == 0)
  {
    umask(0);
    messagequeue();
    sleep(2);
  }

  int auditfork = fork();
  if (auditfork == 0)
  {
    umask(0);
    if((audit())== 0){
      logger("audit executed successfully \n");
    } else {
      logger("audit failed\n");
    }

  int modifiedfork = fork();
  if (modifiedfork == 0)
  {
    umask(0);

    logger("mod fork \n");
    modified();
    }
  int backupanytimefork = fork();
  if (backupanytimefork == 0)
  {
    umask(0);
    logger("back mess fork \n");
    backupmessagequeue();
  }


    // logger("child process created\n");
    // if (setsid() < 0)
    // {
    //   logger("setsid fail\n");
    //   exit(EXIT_FAILURE);
    // }
    // logger("calling backup in child\n");
    // backup(srcToBackup, destOfBackup, src, dest);
    // umask(0);
    // if (chdir("/") < 0)
    // {
    //   exit(EXIT_FAILURE);
    // }
    // int x;
    // for (x = sysconf(_SC_OPEN_MAX); x >= 0; x--)
    // {
    //   close(x);
    // }
  }

  return 0;
}