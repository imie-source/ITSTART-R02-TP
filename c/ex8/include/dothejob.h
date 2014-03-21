#ifndef _DOTHEJOB_H
#define _DOTHEJOB_H

#include "resultat.h"

/**
 * Effectue l'analyse et le calcul de l'opération
 *
 * @author Serge COUDÉ
 * @param string saisie Chaîne à analyser
 * @return \resultat Structure resultat de l'opération
 */
struct resultat *doTheJob(char *saisie);

#endif