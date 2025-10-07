all : exe

exe : liste.o main.o
	gcc main.o liste.o -o exe


main.o : main.c
	gcc -c main.c -o main.o

helper.o : helper/helper.c
	

liste.o : liste.c
	gcc -c liste.c -o liste.o



clean:
	rm -rf *.o *.exe