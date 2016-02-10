cluster-main:	cluster-main.o
	g++	cluster-main.o	-o	cluster-main	-lGL	-lGLU	-lglut

cluster-main.o:	cluster-main.c
	g++	-c	cluster-main.c

clean:
	rm	*.o