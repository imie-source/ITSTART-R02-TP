#ifndef _DETECTION_H
#define _DETECTION_H

/**
 * Détecte un alignement horizontal ou vertical
 * 
 * @param array p Tableau du plateau
 * @param int pos Rang de la colonne ou de la ligne
 * @param int o orientation 1 : verticale, 2 horizontale
 * @param char c1 Symbole du joueur 1
 * @param char c2 Symbole du joueur 2
 * @return int 0: pas d'alignement, 1: joueur 1, 2: joueur 2
 */ 
int detecteAlignementHV(char p[3][3], int pos, int o , char c1, char c2);

/**
 * Détecte un alignement diagonal
 * 
 * @param array p Tableau du plateau
 * @param char c1 Symbole du joueur 1
 * @param char c2 Symbole du joueur 2
 * @return int 0: pas d'alignement, 1: joueur 1, 2: joueur 2
 */ 
int detecteAlignementD(char p[3][3], char c1, char c2);

/**
 * Détecte un alignement horizontal ou vertical ou diagonal
 * 
 * @param array p Tableau du plateau
 * @param char c1 Symbole du joueur 1
 * @param char c2 Symbole du joueur 2
 * @return int 0: pas d'alignement, 1: joueur 1, 2: joueur 2
 */ 
int detecteAlignement(char p[3][3], char c1, char c2);

#endif