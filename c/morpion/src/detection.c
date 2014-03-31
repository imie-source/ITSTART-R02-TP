#include <stdio.h>
#include "../include/detection.h"

int detecteAlignementHV(char p[3][3], int pos, int o , char c1, char c2) {
	int i;
	int j1 = 0;
	int j2 = 0;
	// On calcul le nombre de symboles c1 et c2 sur une colonne ou une ligne
	if (1 == o) { // vertical
		for(i = 0; i < 3; i++) {
			if (c1 == p[i][pos]) {
				j1++;
			} else if (c2 == p[i][pos]) {
				j2++;
			}
		}
	} else { // horizontal
		for(i = 0; i < 3; i++) {
			if (c1 == p[pos][i]) {
				j1++;
			} else if (c2 == p[pos][i]) {
				j2++;
			}
		}
	}
	// 3 symboles pour le joueur 1
	if (3 == j1) {
		// On renvoie 1
		return 1;
	}	
	// 3 symboles pour le joueur 2
	if (3 == j2) {
		// On renvoie 2
		return 2;
	}	
	// Pas 3 symboles, on renvoie 0
	return 0;
}

int detecteAlignementD(char p[3][3], char c1, char c2) {
	// Si une diagonale est remplie avec le même symbole
	if ((p[0][0] == p[1][1] && p[1][1] == p[2][2]) ||
	    (p[0][2] == p[1][1] && p[1][1] == p[2][0])) {
		// S'il s'agit du joueur 1
		if (c1 == p[1][1]) {
			return 1;
		} else if (c2 == p[1][1]) {
			// s'il s'agit du joueur 2
			return 2;
		}	
	}
	return 0;
}

int detecteAlignement(char p[3][3], char c1, char c2) {
	int j = 0;
	int i;
	for(i = 0; i < 3; i++) {
		// pour chaque colonne
		j = detecteAlignementHV(p, i, 1, c1, c2);
		if (j != 0) {
			return j;
		}
		// pour chaque ligne
		j = detecteAlignementHV(p, i, 0, c1, c2);
		if (j != 0) {
			return j;
		}
	}	
	// Sinon, on teste les diagonales
	return detecteAlignementD(p, c1, c2);
}