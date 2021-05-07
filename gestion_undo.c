#include "gestion_undo.h"
#include <stdlib.h>
#include "gestion_sudoku.h"
#include "constantes.h"
#include <uvsqgraphics.h>


UNDO *creer_undo(){
    UNDO *lundo = malloc(sizeof(*lundo));
    ELEMENT *element = malloc(sizeof(*element));

    if (lundo == NULL || element == NULL) exit(EXIT_FAILURE); 
 
    element->i = 0;    
    element->j = 0;    
    element->valeur = 0; 
    element->suivant = NULL;
    lundo->premier = element;

    return lundo;
}


void inserer_undo(UNDO *lundo, char valeur, int i, int j){
	ELEMENT *eres = malloc(sizeof(*eres));
	if(lundo == NULL || eres == NULL) exit(EXIT_FAILURE); 
	eres->valeur = valeur;
	eres->i = i;
	eres->j = j;
	eres->suivant = lundo->premier;
	lundo->premier = eres;
}


void supprimer_undo(UNDO *lundo){

	if(lundo == NULL) exit(EXIT_FAILURE);

	if(lundo->premier != NULL){

	ELEMENT *sup = lundo->premier;
	lundo->premier = lundo->premier->suivant; 
	free(sup);
	}
}


SUDOKU faire_undo(SUDOKU S, UNDO *lundo){
	if(lundo->premier != NULL){

		S.sdk[lundo->premier->i][lundo->premier->j].val = lundo->premier->valeur;
		supprimer_undo(lundo);

	S = edit_valeur_possibles(S,lundo->premier->i,lundo->premier->j,lundo->premier->j,lundo->premier->i);
		
		}
	return S;
}

