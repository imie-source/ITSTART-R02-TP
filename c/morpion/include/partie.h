#ifndef _PARTIE_H
#define _PARTIE_H

/**
 * Vérifie si le coup est autorisé ou non
 * 
 * @param array p Tableau du plateau
 * @param int l N° de la ligne
 * @param int c N° de la colonne
 */ 
int coupNonAutorise(char p[3][3], int l, int c);

/**
 * Joue une partie
 * 
 * @param array p Tableau du plateau
 * @param int n Numéro de la partie
 * @param string p1 Prénom du joueur 1
 * @param string p2 Prénom du joueur 2
 * @param int t1 Total du joueur 1
 * @param int t2 Total du joueur 2
 * @param int co Contre Ordinateur ? 1 / 0
 */ 
int jouerPartie(char p[3][3], int n, char *p1, char *p2, char c1, char c2, int co);

#endif