#ifndef _DOTHEJOB_H
#define _DOTHEJOB_H

#include "resultat.h"

/**
 * Effectue l'analyse et le calcul de l'op�ration
 *
 * @author Serge COUD�
 * @param string saisie Cha�ne � analyser
 * @return \resultat Structure resultat de l'op�ration
 */
struct resultat *doTheJob(char *saisie);

#endif