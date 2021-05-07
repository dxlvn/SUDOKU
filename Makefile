CFLAGS = -g -Wall -c
CFLAGSGR = ${CFLAGS} `sdl-config --cflags`
LFLAGS = -luvsqgraphics `sdl-config --libs` -lm -lSDL_ttf

run: sudoku
	./sudoku exemple1.sudoku

# Edition de lien du programme principal
sudoku: sudoku.o afficher.o gestion_sudoku.o lire_ecrire.o  gestion_undo.o
	gcc -o $@ $^ ${LFLAGS}

# Compilation du programme principal
sudoku.o: sudoku.c lire_ecrire.h gestion_sudoku.h constantes.h 
	gcc ${CFLAGSGR} $*.c

# Compilation des différents.o
afficher.o: afficher.c afficher.h gestion_sudoku.h constantes.h 
	gcc ${CFLAGSGR} $*.c

gestion_sudoku.o: gestion_sudoku.c gestion_sudoku.h 
	gcc ${CFLAGSGR} $*.c

lire_ecrire.o: lire_ecrire.c lire_ecrire.h gestion_sudoku.h
	gcc ${CFLAGSGR} $*.c

gestion_undo.o: gestion_undo.c gestion_undo.h gestion_sudoku.h
	gcc ${CFLAGSGR} $*.c


# Le clean
clean:
	rm -f *.o
	rm -f sudoku


# Pour faire un zip
# Mettre son nom à la place de SUDOKU
LENOM=DOUBI_Dylan
zip:
	rm -rf ${LENOM}
	rm -rf ${LENOM}.zip
	mkdir ${LENOM}
	cp Makefile ${LENOM}
	cp *.h *.c ${LENOM}
	cp A_LIRE.txt ${LENOM}
	zip -r ${LENOM}.zip ${LENOM}
	rm -rf ${LENOM}