tp2: heap.o matriz.o comparador.o bfs.o prog_din.o main.c
	gcc -g heap.o matriz.o comparador.o bfs.o prog_din.o main.c -o tp2


heap.o: heap.c heap.h
	gcc -c heap.c

matriz.o: matriz.c matriz.h
	gcc -c matriz.c

comparador.o: comparador.c comparador.h
	gcc -c comparador.c

bfs.o: heap.o matriz.o comparador.o bfs.h bfs.c
	gcc -c bfs.c

prog_din.o: matriz.o comparador.o prog_din.h prog_din.c
	gcc -c prog_din.c

clean:
	rm *.o 
	rm tp2
	rm saida.txt
