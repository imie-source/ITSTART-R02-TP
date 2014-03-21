#include "../include/trouveoperandes.h"
#include <stdlib.h>
#include <string.h>
#include "../include/substring.h"

/**
 * Trouve les operandes de l'opération et renvoie chacune d'elles dans une structure operandes
 *
 * @param string chaine Chaîne de caractères de l'opération
 * @param \info pInfo Structure info contenant la position de l'opérateur
 * @return \operandes
 */
struct operandes *trouveOperandes(char *chaine, struct info *pInfo) {
	struct operandes *pOperandes = malloc(sizeof(struct operandes));
	char *pOpeGauche = substring(chaine, 0, (*pInfo).position);
	(*pOperandes).gauche = atoi(pOpeGauche);
	free(pOpeGauche);
	char *pOpeDroite = substring(chaine, (*pInfo).position+1, strlen(chaine)-(*pInfo).position-1);
	(*pOperandes).droite = atoi(pOpeDroite);
	free(pOpeDroite);
	return pOperandes;
}