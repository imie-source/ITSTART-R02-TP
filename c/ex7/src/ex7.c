#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#include "../include/resultat.h"
#include "../include/affichernotes.h"
#include "../include/verification.h"

/**
 * Première fonction appelée par le programme
 *
 * Effectue la saisie des notes, puis le calcul de la moyenne,
 * du min, du max et de l'écart-type de l'ensemble des notes
 *
 * @author Serge COUDÉ
 * @return int Code de fin
 */
int main() {

// Définition des variables globales
/**
 * @var array saisie Tableau de caractères pour la saisie de note
 */ 
char saisie[6];
/**
 * @var float moy Moyenne des notes
 */
float moy;
/**
 * @var float som Somme des notes
 */
float som = 0;
/**
 * @var int nbn Nombre des notes
 */
int nbn = 0;
/**
 * @var float ety Ecart-type de l'ensemble des notes
 */
float ety;
/**
 * @var float note Note 
 */
float note;
/**
 * @var float carsom Somme des carrés des notes
 */
float carsom = 0; 

/**
 * @var pointer pTmp Pointeur "temporaire" pour la réallocation de mémoire
 */
struct resultat *pTmp;

/**
 * @var array prenom Chaîne de caractères qui contiendra le prénom
 */
char prenom[20];

/**
 * @var resultat* pResultats Tableau des résultats
 */
struct resultat *pResultats;

/**
 * @var int iMin Indice du résultat minimum
 */
int iMin;

/**
 * @var int iMax Indice du résultat maximum
 */
int iMax;

// L'algorithme

printf("Veuillez saisir les prenoms et les notes\n\t<prenom> <note>\nfinir par le mot 'fin fin'\n");
while( strcmp(prenom, "fin") ) {
	scanf("%s %s", &prenom, &saisie);
	note = verificationSaisie(saisie);
	if (note >= 0) {
		
		if (nbn == 0) {
			/* On n'a pas encore alloué de mémoire, on utilise
			   donc malloc
			  */
			pResultats = malloc(1*sizeof(struct resultat));
			if (NULL == pResultats) {
				// On indique qu'il n'y plus de mémoire
				printf("Plus de m%cmoire disponible...", 130);
				// et on termine le programme avec un code erreur
				return -1;
			}
		} else {
			// J'alloue un élément supplémentaire dans le tableau des résultats
			pTmp = realloc(pResultats, (nbn+1)*sizeof(struct resultat));
			// Si l'allocation s'est bien passée
			if (NULL != pTmp) {
				// On fait pointer pNotes vers la nouvelle plage de mémoire
				pResultats = pTmp;
			} else {
				// On indique qu'il n'y plus de mémoire
				printf("Plus de m%cmoire disponible...", 130);
				// et on termine la boucle de saisie
				break;
			}	
		}
		// Maintenant, j'ai la mémoire disponible pour stocker les informations (note et prénom)
		pResultats[nbn].noteEleve = note;
		pResultats[nbn].prenomEleve = malloc((strlen(prenom)+1)*sizeof(char));
		strcpy(pResultats[nbn].prenomEleve, prenom);
		nbn++; 
		
		if (nbn == 1) {
			iMin = nbn-1;
			iMax = nbn-1;
		}
		som += note;
		carsom += (note*note);
		if (note < pResultats[iMin].noteEleve) {
			iMin = nbn-1;
		}
		if ( note > pResultats[iMax].noteEleve ) {
			iMax = nbn-1;
		}
	} else {
		if ( strcmp(saisie, "fin") != 0) {
			printf("Veuillez saisir une note valide\n");
		}	
	}
}
if (nbn != 0) {
	afficherNotes(nbn, pResultats);
	moy = som / nbn; // Calcul de la moyenne
	ety = sqrt( ( carsom / nbn ) - ( ( som * som ) /  ( nbn * nbn ) ) ); // Calcul de l'écart-type
	printf("La moyenne est : %2.2f\n", moy); 
	printf("La note la plus basse (%s) : %2.2f\n", pResultats[iMin].prenomEleve, pResultats[iMin].noteEleve);
	printf("La note la plus haute (%s) : %2.2f\n", pResultats[iMax].prenomEleve, pResultats[iMax].noteEleve);
	printf("l'%ccart-type : %2.2f\n", 130, ety);
} else {
	printf("Vous n'avez pas saisi de notes...\n");
}
// Libération de la mémoire allouée dynamiquement
for(nbn--; nbn >= 0; nbn--) {
	free(pResultats[nbn].prenomEleve);
}
free(pResultats);
return 0;
}