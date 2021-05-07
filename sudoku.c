#include <stdlib.h>
#include <uvsqgraphics.h>
#include "constantes.h"
#include "afficher.h"
#include "gestion_sudoku.h"
#include "lire_ecrire.h"
#include "gestion_undo.h"


SUDOKU jouer(SUDOKU S){
	POINT B,P;
	int i,j;

  	char touche; 
  	int fleche;  
  	int faire;
	int remonte = 0;

  	UNDO * lundo;                 
  	lundo = creer_undo();

	while(1){
    faire = wait_key_arrow_clic(&touche, &fleche, &P);

	if(faire == EST_CLIC){
	
		B = indices_case_a_modifier(P);
		i = B.x;		
		j = B.y;

		if(i>=0 && S.sdk[i][j].est_travail == 1) inserer_undo(lundo, S.sdk[i][j].val,i,j); 

		S = sudoku_modifier_case(S,i,j);
		sudoku_afficher(S);
		}

	else if(faire == EST_TOUCHE){

		if(touche == 'S') ecrire_fichier(S);
		else if(touche == 'U'){
			S = faire_undo(S, lundo);
			sudoku_afficher(S);
		}   
		else if(touche == 'V'){
		  S = retour_sur_trace(S,0,&remonte);
			sudoku_afficher_trouve(S);
		}   
		else;
	}
	else;		
	}
	return S;
}


int main (int argc, char *argv[]){
    SUDOKU S;
    S = lire_fichier(argv[1]);
    initialiser_fenetre_graphique();
    sudoku_afficher(S);
    S = jouer(S);
    terminer_fenetre_graphique();
    exit(0);
}
