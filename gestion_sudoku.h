#ifndef __SUDOKU_H
#define __SUDOKU_H
#include <uvsqgraphics.h>


struct Case{
	char val;
	//int value;
	int est_travail;
	int valpos[10]; 
};
typedef struct Case CASE;


struct sudoku {
	 CASE sdk[9][9];
};
typedef struct sudoku SUDOKU;

#endif

int est_valide_ligne(SUDOKU S, int valeur, int i, int c);
int est_valide_colonne(SUDOKU S, int valeur, int j, int l);
int est_valide_region(SUDOKU S, int valeur, int i, int j, int c, int l);
int est_valide(SUDOKU S, int valeur, int i, int j, int c, int l);
void ecrire_gagner(SUDOKU S);	
SUDOKU sudoku_modifier_case(SUDOKU S, int i, int j);
POINT indices_case_a_modifier(POINT P);
SUDOKU edit_ligne(SUDOKU S, int i, int j, int c, int l);
SUDOKU edit_colonne(SUDOKU S, int i, int j, int c, int l);
SUDOKU edit_region(SUDOKU S, int i, int j, int c, int l);
SUDOKU edit_valeur_possibles(SUDOKU S, int i, int j, int c, int l);
int impossible(SUDOKU S);
SUDOKU retour_sur_trace(SUDOKU S, int avance,int *remonte);


//int continuer_sudoku(SUDOKU S);
