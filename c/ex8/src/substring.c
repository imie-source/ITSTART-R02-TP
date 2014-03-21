#include <string.h>
#include "../include/substring.h"
#include "../include/strndup.h"

/**
 * Renvoie une sous-cha�ne d'une cha�ne de caract�res
 *
 * @param string str Cha�ne de caract�res originelle
 * @param int begin Indice de d�part
 * @param int len Longueur de la sous-cha�ne
 * @return string sous-cha�ne de caract�res
 */
char* substring(const char* str, int begin, int len) {
  // Les conditions "hors-jeu" 
  if (str == NULL || // la cha�ne est nulle
	  strlen(str) == 0 || // la cha�ne est vide
	  strlen(str) < begin || // le d�but est plus loin que la fin de cha�ne
	  strlen(str) < (begin+len) // on demande plus de caract�res que disponibles
	  ) {
	  // Dans ces conditions, on renvoie NULL
    return NULL;
  }
  // Sinon on renvoie la portion de la cha�ne � partir de
  // l'indice begin et d'une longueur len
  return strndup(str + begin, len);
} 