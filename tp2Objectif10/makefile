all : exe

exe : liste.o main.o esL.o
	gcc main.o liste.o esL.o pile.obj es.obj -o exe


plusmain.o : plusmain.c
	gcc -c plusmain.c -o plusmain.o

main.o : main.c
	gcc -c main.c -o main.o

liste.o : liste.c
	gcc -c liste.c -o liste.o

esL.o : esL.c
	gcc -c esL.c -o esL.o

clean: 
	rm -rf *.o *.exe