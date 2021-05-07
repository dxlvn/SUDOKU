#include <stdio.h>
#include <uvsqgraphics.h>
#include "constantes.h"
#include "gestion_sudoku.h"

void initialiser_fenetre_graphique() {
	init_graphics(HAUTEUR,LARGEUR);
	affiche_auto_off();
}

void terminer_fenetre_graphique() {
	wait_escape();
}


void sudoku_afficher(SUDOKU S) {

//Pour déssiner les cases du sudoku et y afficher les valeurs 
	int i,j;
	for(i=0;i<9;i++){
		for(j=0;j<9;j++){
			POINT p1 = {j*TAILLE_CASE, (9-i)*TAILLE_CASE};
			POINT p2 = {(j+1)*TAILLE_CASE, (9-i-1)*TAILLE_CASE};
			POINT mil = {(j+0.5)*TAILLE_CASE,(8.5-i)*TAILLE_CASE};
			draw_fill_rectangle(p1,p2,argent);
			if(S.sdk[i][j].est_travail == 1) aff_pol_centre(&S.sdk[i][j].val, 35, mil , orangered); 
			else if(&S.sdk[i][j].val) aff_pol_centre(&S.sdk[i][j].val, 35, mil , bleumarine); 
		}

	}


//Pour tracer les traits de séparation des cases  

	for(i=0;i<9;i++){
		for(j=0;j<9;j++){
			POINT p1 = {(i+1)*TAILLE_CASE, (j+1)*TAILLE_CASE};
			POINT p2 = {0, (j+1)*TAILLE_CASE};
			POINT p4 = {(i+1)*TAILLE_CASE, 0};
			draw_line(p2,p1,noir);
			draw_line(p4,p1,noir);
		}
	}

//Pour la partie haute
	
	POINT p5 = {0, 9*TAILLE_CASE};
	POINT p6 = {9*TAILLE_CASE, 10*TAILLE_CASE};
	POINT p7 = {9*TAILLE_CASE, 9*TAILLE_CASE};
	draw_fill_rectangle(p5,p6,argent);
	draw_line(p5,p7,noir);

//Pour séparer les régions 3x3 avec des traits plus épais
	
	POINT p8 = {6*TAILLE_CASE+2, 0};
	POINT p9 = {3*TAILLE_CASE+2, 0};
	POINT pa = {0,0};
	POINT pb = {2-2, 3*TAILLE_CASE};
	POINT pc = {0, 6*TAILLE_CASE};
	POINT pd = {2, 9*TAILLE_CASE};
	POINT pe = {3*TAILLE_CASE, 9*TAILLE_CASE};
	POINT pf = {6*TAILLE_CASE, 9*TAILLE_CASE};
	POINT pg = {9*TAILLE_CASE, 9*TAILLE_CASE+2};
	POINT ph = {9*TAILLE_CASE-2, 6*TAILLE_CASE+2};
	POINT pi = {9*TAILLE_CASE-2, 3*TAILLE_CASE+2};
	POINT pj = {9*TAILLE_CASE-2, 2+1};

	draw_fill_rectangle(pa,pj,noir);
	draw_fill_rectangle(pb,pi,noir);
	draw_fill_rectangle(pc,ph,noir);
	draw_fill_rectangle(pd,pg,noir);
	draw_fill_rectangle(pe,p9,noir);
	draw_fill_rectangle(pf,p8,noir);
	draw_fill_rectangle(pd,pa,noir);
	draw_fill_rectangle(pg,pj,noir);
	draw_rectangle(pa,pg,noir);

	//Afficher le noom du fichier

	POINT np = {2.4*TAILLE_CASE, (9.5)*TAILLE_CASE};
	aff_pol_centre("exemple1.sudoku", 35, np, noir);
	
	affiche_all();
	return S;
}


void sudoku_afficher_trouve(SUDOKU S) { // Pour afficher les solutions

	int i,j;
	for(i=0;i<9;i++){
		for(j=0;j<9;j++){
			POINT p1 = {j*TAILLE_CASE, (9-i)*TAILLE_CASE};
			POINT p2 = {(j+1)*TAILLE_CASE, (9-i-1)*TAILLE_CASE};
			POINT mil = {(j+0.5)*TAILLE_CASE,(8.5-i)*TAILLE_CASE};
			draw_fill_rectangle(p1,p2,argent);
			if(S.sdk[i][j].est_travail == 1) aff_pol_centre(&S.sdk[i][j].val, 35, mil , limegreen ); 
			else if(&S.sdk[i][j].val) aff_pol_centre(&S.sdk[i][j].val, 35, mil , bleumarine); 
		}

	}

	//Pour tracer les traits de séparation des cases  

	for(i=0;i<9;i++){
		for(j=0;j<9;j++){
			POINT p1 = {(i+1)*TAILLE_CASE, (j+1)*TAILLE_CASE};
			POINT p2 = {0, (j+1)*TAILLE_CASE};
			POINT p4 = {(i+1)*TAILLE_CASE, 0};
			draw_line(p2,p1,noir);
			draw_line(p4,p1,noir);
		}
	}

//Pour la partie haute
	
	POINT p5 = {0, 9*TAILLE_CASE};
	POINT p6 = {9*TAILLE_CASE, 10*TAILLE_CASE};
	POINT p7 = {9*TAILLE_CASE, 9*TAILLE_CASE};
	draw_fill_rectangle(p5,p6,argent);
	draw_line(p5,p7,noir);

//Pour séparer les régions 3x3 avec des traits plus épais
	
	POINT p8 = {6*TAILLE_CASE+2, 0};
	POINT p9 = {3*TAILLE_CASE+2, 0};
	POINT pa = {0,0};
	POINT pb = {2-2, 3*TAILLE_CASE};
	POINT pc = {0, 6*TAILLE_CASE};
	POINT pd = {2, 9*TAILLE_CASE};
	POINT pe = {3*TAILLE_CASE, 9*TAILLE_CASE};
	POINT pf = {6*TAILLE_CASE, 9*TAILLE_CASE};
	POINT pg = {9*TAILLE_CASE, 9*TAILLE_CASE+2};
	POINT ph = {9*TAILLE_CASE-2, 6*TAILLE_CASE+2};
	POINT pi = {9*TAILLE_CASE-2, 3*TAILLE_CASE+2};
	POINT pj = {9*TAILLE_CASE-2, 2+1};

	draw_fill_rectangle(pa,pj,noir);
	draw_fill_rectangle(pb,pi,noir);
	draw_fill_rectangle(pc,ph,noir);
	draw_fill_rectangle(pd,pg,noir);
	draw_fill_rectangle(pe,p9,noir);
	draw_fill_rectangle(pf,p8,noir);
	draw_fill_rectangle(pd,pa,noir);
	draw_fill_rectangle(pg,pj,noir);
	draw_rectangle(pa,pg,noir);

	//Afficher le noom du fichier

	POINT np = {2.4*TAILLE_CASE, (9.5)*TAILLE_CASE};
	aff_pol_centre("exemple1.sudoku", 35, np, noir);
	
	affiche_all();
	return S;

}