#include <stdio.h>
#include <unistd.h>
#include <syslog.h>
#include "logger.h"

void logger(char * message){

    openlog("DT228Yr4",LOG_PID|LOG_CONS,LOG_USER);
    syslog(LOG_INFO,"%s",message);
    closelog();
    
}