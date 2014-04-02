#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/partie.h"
#include "../include/affichage.h"

int main(int nbArgs, char **tabArgs) {

	char prenom1[20];
	char prenom2[20]; 
	int nbParties;
	int np;
	int total1 = 0;
	int total2 = 0;
	char plateau[3][3];
	char s1 = 'X';
	char s2 = 'O';
	int resultat;

	// Début de l'algorithme principal
	if (nbArgs >= 3) {
		strcpy(prenom1,tabArgs[1]);
		strcpy(prenom2,tabArgs[2]);
		if (nbArgs == 4) {
			nbParties = atoi(tabArgs[3]);
		}
	}
	if (nbArgs < 3) {
		printf("Saisir le prenom du premier joueur (%c) : ", s1);
		gets(prenom1);
		//printf("Saisir le prenom du second joueur (%c) : ", s2);
		//gets(prenom2);
		strcpy(prenom2, "Ordinateur");
	}
	if (nbArgs <= 3) {
		printf("Saisir le nombre de parties à jouer : ");
		char saisie[20];
		gets(saisie);
		nbParties = atoi(saisie);
	}
	for(np = 0; np < nbParties; np++) {
		resultat = jouerPartie(plateau, np, prenom1, prenom2, s1, s2);
		switch(resultat) {
			case 1:
				total1 += 3;
				break;
			case 2:
				total2 += 3;
				break;
			default:
				total1 += 1;
				total2 += 1;
		}		
		if (np < nbParties-1) {
			afficherResultatsPartiels(np, prenom1, prenom2, resultat, total1, total2);
		}	
	}
	afficherResultatsFinaux(prenom1, prenom2, total1, total2);
	return 0;
}