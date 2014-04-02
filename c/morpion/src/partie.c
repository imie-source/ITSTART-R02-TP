#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/plateau.h"
#include "../include/partie.h"
#include "../include/ia.h"

int coupNonAutorise(char p[3][3], int l, int c) {
	return l > 3 || l < 1 ||
		   c > 3 || c < 1 ||
		   (' ' != p[l-1][c-1]);
}

int jouerPartie(char p[3][3], int n, char *p1, char *p2, char c1, char c2, int co) {
	int nbCoups = 0;
	int aligne = 0;
	int j = (n % 2)+1;
	char saisie[3];
	int li;
	int ci;
	int coupIncorrect;
	initialiserPlateau(p);
	afficherPlateau(p);
	while (nbCoups < 9 && aligne == 0) {
		coupIncorrect = 1;
		// On vérifie que les coordonnées saisies sont correctes
		// et on "boucle" tant que ce n'est pas le cas
		while(coupIncorrect) {
			printf("%s, a vous de jouer (LC, ex 32) :", (1 == j) ? p1 : p2);
			if (1 == j || 0 == co) { 
				gets(saisie);
			} else {
				printf("\n");
				char *pCoup = coupJoueParOrdinateur(p, c1, c2);
				strcpy(saisie, pCoup);
				free(pCoup);
			}
			li = saisie[0]-'0';
			ci = saisie[1]-'0';
			coupIncorrect = coupNonAutorise(p, li, ci);
		}	
		// Le coup est correct, on met à jour le plateau
		p[li-1][ci-1] = (1 == j) ? c1 : c2;
		// Détection d'un alignement par un joueur 
		aligne = detecteAlignement(p, c1, c2);
		// On affiche le plateau
		afficherPlateau(p);
		nbCoups++;
		j++;
		if (3 == j) { // alternance joueur 1 / joueur 2
			j = 1;
		}
	}	
	return aligne;
}	