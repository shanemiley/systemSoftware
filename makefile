CC=gcc
objects = main.o  backup.o permission.o
headers = backup.h permission.h

myprog : $(objects)
	$(CC) -o mainProg $(objects) -lm

main.o : main.c $(headers)
	$(CC) -c main.c

backup.o : backup.c
	$(CC) -c backup.c
permission.o : permission.c
	$(CC) -c permission.c


clean:
	rm mainProg $(objects)