#include <stdio.h>
#include <string.h>
#include "../include/dothejob.h"
#include "../include/resultat.h"

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
	 * @var \resultat pRes Structure de r�sultat de l'op�ration
	 */
	struct resultat *pRes;
 
	while(stricmp(saisie, "fin")) {
		printf("Veuillez saisir une operation, finir par 'fin'\n");
		gets(saisie);
		if (stricmp(saisie, "fin")) {
			pRes = doTheJob(saisie);
			if ((*pRes).erreur) {
				printf("!!!ERREUR!!! : %s\n", (*pRes).message);
			} else {
				printf("resultat : %lf\n", (*pRes).resultat);
			}
			free(pRes);
		}	
	}
	 
	return 0;
}