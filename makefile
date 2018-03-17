CC=gcc
objects = main.o  backup.o permission.o modified.o logger.o audit.o
headers = backup.h permission.h logger.h modified.h audit.h

myprog : $(objects)
	$(CC) -o mainProg $(objects) -lm

main.o : main.c $(headers)
	$(CC) -c main.c

backup.o : backup.c
	$(CC) -c backup.c

permission.o : permission.c
	$(CC) -c permission.c

modified.o : modified.c
	$(CC) -c modified.c

logger.o : logger.c
	$(CC) -c logger.c

audit.o : audit.c
	$(CC) -c audit.c


clean:
	rm mainProg $(objects)