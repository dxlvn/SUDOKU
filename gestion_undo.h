#include "gestion_sudoku.h"

struct element{
	int i;
	int j;
    char valeur;
    struct element *suivant;
};
typedef struct element ELEMENT;



struct undo{
    ELEMENT *premier;
};
typedef struct undo UNDO;


UNDO* creer_undo();
void inserer_undo(UNDO *lundo, char valeur, int i, int j);
void supprimer_undo(UNDO *lundo);
SUDOKU faire_undo(SUDOKU S, UNDO *lundo);

