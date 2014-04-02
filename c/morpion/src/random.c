#include <stdlib.h>
#include "../include/random.h"

/** 
 * Renvoie un nombre pseudo-al�atoire compris entre bInf et bSup inclus
 *
 * Penser � utiliser la fonction srand(time(NULL)) pour
 * obtenir un comportement plus al�atoire
 *
 * @param int bInf Borne inf�rieure
 * @param int bSup Borne sup�rieure
 * @return int Nombre pseudo-al�atoire compris entre bInf et bSup inclus
 */
int random(int bInf, int bSup) {
	return (bInf + (rand () % (bSup-bInf+1))); 
}