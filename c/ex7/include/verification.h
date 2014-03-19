#ifndef _VERIFICATION_H
#define _VERIFICATION_H

/**
 * V�rifie si la cha�ne pass�e en param�tre est une note ou pas
 *
 * Parcourt les caract�res de la cha�ne et v�rifie un par un
 * si le caract�res est un chiffre, un point ou une virgule
 *
 * @param char* chaine Cha�ne � v�rifier
 * @return float >= 0 si la cha�ne est bien une note, -1 sinon
 */
float verificationSaisie(char *chaine);

#endif