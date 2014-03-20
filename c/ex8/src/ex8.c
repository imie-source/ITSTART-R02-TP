#include <stdio.h>
#include <string.h>

#include "../include/quelleoperation.h"

/**
 * Première fonction appelée par le programme
 *
 * @param int nbArgs Nombre d'arguments
 * @param array tabArgs Tableau des arguments
 * @return int Code de fin de programme
 */
int main(int nbArgs, char **tabArgs) {
	
	/**
	 * @var array saisie Tableau de caractères contenant la saisie de l'utilisateur
	 */
	char saisie[200] = "";
 
	while(stricmp(saisie, "fin")) {
		printf("Veuillez saisir une operation, finir par 'fin'\n");
		gets(saisie);
		if (stricmp(saisie, "fin")) {
			struct info *pInfo = quelleOperation(saisie);
			printf("operation : %c\n", (*pInfo).operateur);
			printf("position : %d\n", (*pInfo).position);
			printf("%s\n", saisie);
			free(pInfo);
		}	
	}
	 
	return 0;
}