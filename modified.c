

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/inotify.h>
#include <unistd.h>
#include "modified.h"

#define EVENT_SIZE (sizeof(struct inotify_event))
#define BUF_LEN (1024 * (EVENT_SIZE + 16))

void modified()
{

  FILE *fp;

  while (1)
  {
    int length, i = 0;
    int fd;
    int wd;
    char buffer[BUF_LEN];
    char *intra = "/home/shane/Desktop/SSAssignment/";

    fd = inotify_init();

    if (fd < 0)
    {
      perror("inotify_init");
    }

    wd = inotify_add_watch(fd, intra, IN_MODIFY | IN_CREATE | IN_DELETE);
    length = read(fd, buffer, BUF_LEN);

    if (length < 0)
    {
      perror("read");
    }
    while (i < length)
    {
      struct inotify_event *event = (struct inotify_event *)&buffer[i];
      if (event->len)
      {
        if (event->mask & IN_CREATE)
        {
          if (event->mask & IN_ISDIR)
          {
            printf("The directory %s was created.\n", event->name);
          }
          else
          {
            printf("The file %s was created.\n", event->name);
            fp = fopen("modifiedLogFile.txt", "w+");
            fprintf(fp, "The file %s was created.\n", event->name);
            fclose(fp);
          }
        }
        else if (event->mask & IN_DELETE)
        {
          if (event->mask & IN_ISDIR)
          {
            printf("The directory %s was deleted.\n", event->name);
          }
          else
          {
            printf("The file %s was deleted.\n", event->name);
            fp = fopen("modifiedLogFile.txt", "w+");
            fprintf(fp, "The file %s was deleted.\n", event->name);
            fclose(fp);
          }
        }
        else if (event->mask & IN_MODIFY)
        {
          if (event->mask & IN_ISDIR)
          {
            printf("The directory %s was modified.\n", event->name);
          }
          else
          {
            printf("The file %s was modified.\n", event->name);
            fp = fopen("modifiedLogFile.txt", "w+");
            fprintf(fp, "The file %s was modified.\n", event->name);
            fclose(fp);
          }
        }
      }
      i += EVENT_SIZE + event->len;
    }

    (void)inotify_rm_watch(fd, wd);
    (void)close(fd);
  }
  exit(0);
}
