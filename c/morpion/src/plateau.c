#include <stdio.h>
#include "../include/plateau.h"

void initialiserPlateau(char p[3][3]) {
	int l, c;
	for(l = 0; l < 3; l++) {
		for(c = 0; c < 3; c++) {
			p[l][c] = ' ';
		}
	}	
}

void afficherPlateau(char p[3][3]) {
	int l, c;
	printf("  1 2 3\n");
	for(l = 0; l < 3; l++) {
		printf(" -------\n");
		printf("%d|", l+1);
		for(c = 0; c < 3; c++) {
			printf("%c|", p[l][c]);
		}
		printf("\n");
	}
	printf(" -------\n");
}

