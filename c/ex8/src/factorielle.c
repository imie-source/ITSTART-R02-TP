#include "../include/factorielle.h"

/**
 * Renvoie la factorielle d'un nombre (recursive)
 * 
 * @author Serge COUD�
 * @param int n Nombre � factorielliser
 * @return unsigned long Factorielle du nombre
 */
unsigned long factorielle(int n) {
	if (n <= 1) {
		return 1;
	}
	return n * factorielle(n-1);
	/*
		notation "abr�g�e" :
		return n <= 1 ? 1 : n * factorielle(n-1);
	*/
}