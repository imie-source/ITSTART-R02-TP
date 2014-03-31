#ifndef _AFFICHAGE_H
#define _AFFICHAGE_H

/**
 * Affiche les totaux de chaque joueur
 * 
 * @param string p1 Prénom du joueur 1
 * @param string p2 Prénom du joueur 2
 * @param int t1 Total du joueur 1
 * @param int t2 Total du joueur 2
 */ 
void afficherTotaux(char *p1, char *p2, int t1, int t2);

/**
 * Affiche les résultats de chaque joueur à chaque partie
 * 
 * @param int n Numéro de la partie
 * @param string p1 Prénom du joueur 1
 * @param string p2 Prénom du joueur 2
 * @param int g Gagnant 
 * @param int t1 Total du joueur 1
 * @param int t2 Total du joueur 2
 */ 
void afficherResultatsPartiels(int n, char *p1, char *p2, int g, int t1, int t2);

/**
 * Affiche les résultats finaux
 * 
 * @param string p1 Prénom du joueur 1
 * @param string p2 Prénom du joueur 2
 * @param int t1 Total du joueur 1
 * @param int t2 Total du joueur 2
 */ 
void afficherResultatsFinaux(char *p1, char *p2, int t1, int t2);

#endif