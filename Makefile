PROJECT = lab1
TARGET = lab1

SRC_FILES = \
  Makefile \
  README \
  lab1.c

OBJ_FILES = \
  lab1.o \

CC = gcc
CFLAGS = -g -Wall -std=c99 -D_BSD_SOURCE 

$(TARGET):  	$(OBJ_FILES)
		$(CC) $(OBJ_FILES) -o $@

clean:
		rm -f $(TARGET) *.o *~

lab1.o:		lab1.c

