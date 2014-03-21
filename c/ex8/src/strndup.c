#include <stdlib.h>
#include <string.h>
#include "../include/strndup.h"
 
/**
 * Copie une portion de chaîne de caractères
 * 
 * @param string s Chaîne de caractères originelle
 * @param int n Longueur de la portion
 * @return string Portion de la chaîne copiée
 */
char* strndup(const char*  s, int n) {
	//longueur de la chaîne de caractères
    int slen = strlen(s);
	// adresse mémoire de la future portion de chaîne
    char* copy;
	// Au cas où on demande une portion trop importante
    if (slen < n) {
		// On réduit la portion au nombre de caractères maximum
        n = slen;
    }
	// On alloue la quantité de mémoire nécessaire
	// en pensant au +1 pour le caractère de fin de chaînes
    copy = malloc((n+1)*sizeof(char));
	// Si l'allocation s'est bien passée
    if (NULL != copy){
		// On duplique la portion de chaîne
        memcpy(copy, s, n);
		// Et on ajoute en dernière position le caractère
		// de fin de chaîne
        copy[n] = '\0';
    }
	// Dans tous les cas, on renvoie l'adresse de 
	// la mémoire allouée ou 0 si problème d'allocation
    return copy;
}