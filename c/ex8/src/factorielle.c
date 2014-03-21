#include "../include/factorielle.h"

/**
 * Renvoie la factorielle d'un nombre (recursive)
 * 
 * @author Serge COUDÉ
 * @param int n Nombre à factorielliser
 * @return unsigned long Factorielle du nombre
 */
unsigned long factorielle(int n) {
	if (n <= 1) {
		return 1;
	}
	return n * factorielle(n-1);
	/*
		notation "abrégée" :
		return n <= 1 ? 1 : n * factorielle(n-1);
	*/
}