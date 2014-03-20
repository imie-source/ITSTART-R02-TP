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
  if (str == 0 || 
	  strlen(str) == 0 ||
	  strlen(str) < begin ||
	  strlen(str) < (begin+len)) {
    return 0;
  }
  return strndup(str + begin, len);
} 