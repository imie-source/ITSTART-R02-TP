#include <string.h>
#include "../include/substring.h"
#include "../include/strndup.h"

/**
 * Renvoie une sous-chaîne d'une chaîne de caractères
 *
 * @param string str Chaîne de caractères originelle
 * @param int begin Indice de départ
 * @param int len Longueur de la sous-chaîne
 * @return string sous-chaîne de caractères
 */
char* substring(const char* str, int begin, int len) {
  // Les conditions "hors-jeu" 
  if (str == NULL || // la chaîne est nulle
	  strlen(str) == 0 || // la chaîne est vide
	  strlen(str) < begin || // le début est plus loin que la fin de chaîne
	  strlen(str) < (begin+len) // on demande plus de caractères que disponibles
	  ) {
	  // Dans ces conditions, on renvoie NULL
    return NULL;
  }
  // Sinon on renvoie la portion de la chaîne à partir de
  // l'indice begin et d'une longueur len
  return strndup(str + begin, len);
} 