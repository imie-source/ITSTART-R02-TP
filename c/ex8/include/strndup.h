#ifndef _STRNDUP_H
#define _STRNDUP_H

/**
 * Copie une portion de chaîne de caractères
 * 
 * @param string s Chaîne de caractères originelle
 * @param int n Longueur de la portion
 * @return string Portion de la chaîne copiée
 */
char* strndup(const char*  s, int n);

#endif