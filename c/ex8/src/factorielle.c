#include "../include/factorielle.h"

/**
 * Renvoie la factorielle d'un nombre
 * 
 * @author Serge COUD�
 * @param int n Nombre � factorielliser
 * @return unsigned long Factorielle du nombre
 */
unsigned long long factorielle(int n) {
	unsigned long long res = 1;
	for(; n > 1; n--) {
		res *= n;
	}
	return res;
}