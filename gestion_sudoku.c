#include <stdlib.h>
#include "gestion_sudoku.h"
#include "constantes.h"
#include "lire_ecrire.h"
#include "afficher.h"

int impossible(SUDOKU S){
  int i, j, compt;
  int possible;
  
  for(i=0; i < 9; i++){
    for(j=0; j < 9; j++){
      if(S.sdk[i][j].val == 32){
	possible = 0;
	for(compt=0; compt < 9; compt++){
	  if(est_valide(S,compt+49,i,j,j,i)) possible+=1;
	}
	if(!possible) return 1;
      }
    }
  }
  return 0;
}

int est_valide_ligne(SUDOKU S, int valeur, int i, int c){  // i: indice de ligne, valeur: valeur testée, c: case colonne testée 
   	int j;
    for(j=0; j < 9; j++){
    	if(j != c) {
    		if( S.sdk[i][j].val == valeur){
    			return 0;
    		}   	
    	}       
    }
   return 1;
}

int est_valide_colonne(SUDOKU S, int valeur, int j, int l){  // j: indice de colonne, valeur: valeur testée, l: case ligne testée 
	int i;
    for(i=0; i < 9; i++){
    	if(i != l) {
       		if(S.sdk[i][j].val  == valeur){
            	return 0;
       		}
    	}
    }	 
    return 1;
}

int est_valide_region(SUDOKU S, int valeur, int i, int j, int c, int l){
    int ir = i-(i%3);
    int jr = j-(j%3);  
    for (i=ir; i < ir+3; i++){
        for (j=jr; j < jr+3; j++){
        	if((i != l) && (j != c)){
            	if (S.sdk[i][j].val == valeur){
                	return 0;
            	}
            }
        }
    }
    return 1;
}

int est_valide(SUDOKU S, int valeur, int i, int j, int c, int l){
	if( (est_valide_ligne(S,valeur,i,c)) && (est_valide_colonne(S,valeur,j,l)) && (est_valide_region(S,valeur,i,j,c,l)) ) return 1;
	else return 0; 
}



SUDOKU sudoku_modifier_case(SUDOKU S, int i, int j){ //
	if(S.sdk[i][j].est_travail == 1){		
		int l,stop;
		l=1;
		stop=1;
		while(stop){
			if(S.sdk[i][j].val+l == 58){
				S.sdk[i][j].val = 32;
				stop=0;
			}
			else if(S.sdk[i][j].val == 32) S.sdk[i][j].val = 48;

			else if(est_valide(S,S.sdk[i][j].val+l,i,j,j,i)){     
				S.sdk[i][j].val = S.sdk[i][j].val+l;
				stop=0;
			}

			else l++;
		}
	}
	return S;
}  




// edit des valeurs possibles

SUDOKU edit_ligne(SUDOKU S, int i, int j, int c, int l){         
	for(j=0;j<9;j++){
		for(int a=49;a<58;a++){
			if(est_valide(S,a,i,j,c,l)) S.sdk[i][j].valpos[a-48] = 1;
			else S.sdk[i][j].valpos[a-48] = 0;
		}
	}
	return S;
}


SUDOKU edit_colonne(SUDOKU S, int i, int j, int c, int l){
	for(i=0;i<9;i++){
		for(int a=49;a<58;a++){
			if(est_valide(S,a,i,j,c,l)) S.sdk[i][j].valpos[a-48] = 1;
			else S.sdk[i][j].valpos[a-48] = 0;
		}
	}
	return S;
}


SUDOKU edit_region(SUDOKU S, int i, int j, int c, int l){
	int ir = i-(i%3);
    int jr = j-(j%3);  
    for(i=ir; i < ir+3; i++){
    	for (j=jr; j < jr+3; j++){	
			for(int a=49;a<58;a++){
				if(est_valide(S,a,i,j,c,l) && a<58) S.sdk[i][j].valpos[a-48] = 1;
				else if (!(est_valide(S,a,i,j,c,l)) && a<58) S.sdk[i][j].valpos[a-48] = 0;
				else;
			}	
		}
	}
	return S;
}


SUDOKU edit_valeur_possibles(SUDOKU S, int i, int j, int c, int l){
  S = edit_ligne(S, i, j, c, l);
	S = edit_colonne(S, i, j, c, l);
	S = edit_region(S, i, j, c, l);

	return S;
}

POINT indices_case_a_modifier(POINT P){ // retourne un point ayant pour coordonnées les indices de la case à modifier  
	POINT A;
	int abs = (P.x)/TAILLE_CASE ;
	int ord = ((630)/TAILLE_CASE - (P.y)/TAILLE_CASE)  ;	

	A.y = abs ;
	A.x = ord - 1 ;
	return A;

}


SUDOKU retour_sur_trace(SUDOKU S, int avance, int* remonte){


  SUDOKU retient = S;
  
  if(avance == 81 || *remonte == 1){
      *remonte = 1;
      return S;
    }

  
  if(impossible(S)) return retient;
  
  int j = avance%9;
  int i = avance/9;

  if(S.sdk[i][j].est_travail == 0) return retour_sur_trace(S,avance+1, remonte);


  
  
  sudoku_afficher_trouve(S);

  int compt;
  char saute;

  for(compt=0; compt<10;compt++){
    S = sudoku_modifier_case(S,i,j);
    if(S.sdk[i][j].val==32) S = sudoku_modifier_case(S,i,j);

    if(!impossible(S)){
  	S = retour_sur_trace(S, avance+1, remonte);
      }
    
  }

  if(impossible(S)){
      S = retour_sur_trace(S, avance, remonte);
  }

  
  return S;
}
