#include <stdlib.h>
#include "../include/quelleoperation.h"
#include "../include/trouveoperandes.h"
#include "../include/calculeoperation.h"
#include "../include/dothejob.h"

/**
 * Effectue l'analyse et le calcul de l'op�ration
 *
 * @author Serge COUD�
 * @param string saisie Cha�ne � analyser
 * @return \resultat Structure resultat de l'op�ration
 */
struct resultat * doTheJob(char *saisie) {
	struct resultat *pResultat = malloc(sizeof(struct resultat));
	(*pResultat).erreur = 0;
	struct info *pInfo = quelleOperation(saisie);
	// printf("operation : %c\n", (*pInfo).operateur);
	// printf("position : %d\n", (*pInfo).position);
	// printf("%s\n", saisie);
	struct operandes *pOperandes = trouveOperandes(saisie, pInfo);
	// printf("opeG : %d\n", (*pOperandes).gauche);
	// printf("opeD : %d\n", (*pOperandes).droite);
	if ('/' == (*pInfo).operateur) {
		if (0 == (*pOperandes).droite) {
			// gestion de la division par z�ro
			(*pResultat).message = "Division par zero";
			(*pResultat).erreur = 1;
		}
	} else {
		(*pResultat).resultat = calculeOperation((*pInfo).operateur,
												 (*pOperandes).gauche,
												(*pOperandes).droite);
	}
	free(pInfo);
	free(pOperandes);
	return pResultat;
}