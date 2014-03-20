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
  if (str == 0 || 
	  strlen(str) == 0 ||
	  strlen(str) < begin ||
	  strlen(str) < (begin+len)) {
    return 0;
  }
  return strndup(str + begin, len);
} 