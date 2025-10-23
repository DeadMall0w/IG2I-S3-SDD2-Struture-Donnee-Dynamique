all : exe

exe : liste.o main.o es.o
	gcc main.o liste.o es.o -o exe


main.o : main.c
	gcc -c main.c -o main.o

liste.o : liste.c
	gcc -c liste.c -o liste.o

es.o : es.c
	gcc -c es.c -o es.o

clean: 
	rm -rf *.o *.exe