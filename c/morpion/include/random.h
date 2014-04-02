#ifndef _RANDOM_H
#define _RANDOM_H

/** 
 * Renvoie un nombre pseudo-aléatoire compris entre bInf et bSup inclus
 *
 * Penser à utiliser la fonction srand(time(NULL)) pour
 * obtenir un comportement plus aléatoire
 *
 * @param int bInf Borne inférieure
 * @param int bSup Borne supérieure
 * @return int Nombre pseudo-aléatoire compris entre bInf et bSup inclus
 */
int random(int bInf, int bSup);

#endif