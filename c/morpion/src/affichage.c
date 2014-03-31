#include <stdio.h>
#include "../include/affichage.h"

void afficherTotaux(char *p1, char *p2, int t1, int t2) {
	printf("totaux -> %s:%d  et %s:%d\n", p1, t1, p2, t2);
}
	
void afficherResultatsPartiels(int n, char *p1, char *p2, int g, int t1, int t2) {
	if (1 == g) {
		printf("Partie %d -> le gagnant est %s\n", n+1, p1);
	} else if (2 == g) { 
		printf("Partie %d -> le gagnant est %s\n", n+1, p2);
	} else {
		printf("Partie %d -> partie nulle\n", n+1);
	}	
	afficherTotaux(p1, p2, t1, t2);
}	

void afficherResultatsFinaux(char *p1, char *p2, int t1, int t2) {
	afficherTotaux(p1, p2, t1, t2);
	if (t1 > t2) {
		printf("Le gagnant est %s !\n", p1);
	} else if (t2 > t1) {
		printf("Le gagnant est %s !\n", p2);
	} else {
		printf("Matche nul !\n");
	}
}	