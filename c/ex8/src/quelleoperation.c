#include "../include/quelleoperation.h"
#include <stdlib.h>

struct info *quelleOperation(char *chaine) {
	int i = 0;
	while(chaine[i] != '+' &&
	      chaine[i] != '-' &&
		  chaine[i] != 'x' &&
		  chaine[i] != '/' &&
		  chaine[i] != '^' &&
		  chaine[i] != '!' &&
		  chaine[i] != '\0') {
		i++;
	}
	struct info *pInfo = malloc(sizeof(struct info));
	(*pInfo).operateur = chaine[i];
	(*pInfo).position = i;
	return pInfo;
}