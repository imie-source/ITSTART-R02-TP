#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "../include/quelleoperation.h"
#include "../include/substring.h"

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
			char *pOpe1 = substring(saisie, 0, (*pInfo).position-1);
			printf("operande1 : %s\n", pOpe1); 
			int val = atoi(pOpe1);
			val += 2;
			printf("val : %d\n", val);
			free(pOpe1);
			free(pInfo);
			
		}	
	}
	 
	return 0;
}