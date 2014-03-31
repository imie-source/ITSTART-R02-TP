#ifndef _AFFICHAGE_H
#define _AFFICHAGE_H

/**
 * Affiche les totaux de chaque joueur
 * 
 * @param string p1 Pr�nom du joueur 1
 * @param string p2 Pr�nom du joueur 2
 * @param int t1 Total du joueur 1
 * @param int t2 Total du joueur 2
 */ 
void afficherTotaux(char *p1, char *p2, int t1, int t2);

/**
 * Affiche les r�sultats de chaque joueur � chaque partie
 * 
 * @param int n Num�ro de la partie
 * @param string p1 Pr�nom du joueur 1
 * @param string p2 Pr�nom du joueur 2
 * @param int g Gagnant 
 * @param int t1 Total du joueur 1
 * @param int t2 Total du joueur 2
 */ 
void afficherResultatsPartiels(int n, char *p1, char *p2, int g, int t1, int t2);

/**
 * Affiche les r�sultats finaux
 * 
 * @param string p1 Pr�nom du joueur 1
 * @param string p2 Pr�nom du joueur 2
 * @param int t1 Total du joueur 1
 * @param int t2 Total du joueur 2
 */ 
void afficherResultatsFinaux(char *p1, char *p2, int t1, int t2);

#endif