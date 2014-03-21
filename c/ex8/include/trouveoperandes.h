#ifndef _TROUVEOPERANDES_H
#define _TROUVEOPERANDES_H

#include "operandes.h"
#include "info.h"

/**
 * Trouve les opérandes d'une opération et renvoie une structure operandes
 *
 * @param string chaine Chaîne de caractères à analyser
 * @param \info pInfo Structure info contenant la position du caractère d'opération
 * @return \operandes Opérandes gauche et droite
 */
struct operandes *trouveOperandes(char *chaine, struct info *pInfo);

#endif