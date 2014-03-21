#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "../include/quelleoperation.h"
#include "../include/substring.h"
#include "../include/trouveoperandes.h"
#include "../include/calculeoperation.h"

/**
 * Premi�re fonction appel�e par le programme
 *
 * @param int nbArgs Nombre d'arguments
 * @param array tabArgs Tableau des arguments
 * @return int Code de fin de programme
 */
int main(int nbArgs, char **tabArgs) {
	
	/**
	 * @var array saisie Tableau de caract�res contenant la saisie de l'utilisateur
	 */
	char saisie[200] = "";
	
	/**
	 * @var double res R�sultat de l'op�ration
	 */
	double res = 0;
 
	while(stricmp(saisie, "fin")) {
		printf("Veuillez saisir une operation, finir par 'fin'\n");
		gets(saisie);
		if (stricmp(saisie, "fin")) {
			struct info *pInfo = quelleOperation(saisie);
			printf("operation : %c\n", (*pInfo).operateur);
			printf("position : %d\n", (*pInfo).position);
			printf("%s\n", saisie);
			struct operandes *pOperandes = trouveOperandes(saisie, pInfo);
			printf("opeG : %d\n", (*pOperandes).gauche);
			printf("opeD : %d\n", (*pOperandes).droite);
			res = calculeOperation((*pInfo).operateur,
								   (*pOperandes).gauche,
								   (*pOperandes).droite);
			printf("resultat : %lf\n", res);					   
			free(pInfo);
			free(pOperandes);
			
		}	
	}
	 
	return 0;
}