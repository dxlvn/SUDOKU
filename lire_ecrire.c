#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "gestion_sudoku.h"

SUDOKU lire_fichier (char *nom) {
	SUDOKU S;

	int l,c=0; // Indices de lignes et de colonnes l et c (0 -> 8) 
	FILE* fic = fopen(nom,"r");
	if (!fic) exit(0);
	for(l=0;l<9;l++){ 
		for(c=0;c<9;c++){
			S.sdk[l][c].est_travail = 0;
			S.sdk[l][c].val = fgetc(fic);
			if(S.sdk[l][c].val == '*'){
				S.sdk[l][c].est_travail = 1;
			 	S.sdk[l][c].val = fgetc(fic); 
			 }
			if(S.sdk[l][c].val == '\n'){
				 S.sdk[l][c].val = fgetc(fic);
				 if(S.sdk[l][c].val == '*'){
				 	S.sdk[l][c].est_travail = 1;
			 		S.sdk[l][c].val = fgetc(fic); 
				 }
				}
			if(S.sdk[l][c].val == '.'){ 
				S.sdk[l][c].val = 32;
				S.sdk[l][c].est_travail = 1;
				}
		    
		}
	}

	fclose(fic);
	return S;
} 

void ecrire_fichier(SUDOKU S) {
	int l,c=0;	 // Indices de lignes et de colonnes l et c (0 -> 8) 
	int cases_ecrites = 0;
	FILE* F = fopen("newfic.sudoku","w");
	if (!F) exit(0);
	for(l=0;l<9;l++){ 
		for(c=0;c<9;c++){
			if(S.sdk[l][c].est_travail == 0){
				fprintf(F,"%c",S.sdk[l][c].val);
			}
			else if( (S.sdk[l][c].est_travail == 1) && ((S.sdk[l][c].val == 0) || (S.sdk[l][c].val == 32) || (S.sdk[l][c].val == ' ') )){
				fprintf(F,".");
			}
			else{
				fprintf(F, "*%c",S.sdk[l][c].val);
			}
			cases_ecrites++;
			if(cases_ecrites==9){
				fprintf(F, "\n");
				cases_ecrites=0;
			}	
		}	
	}	
	fclose(F);
}

	
	