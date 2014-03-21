#include "../include/calculeoperation.h"
#include "../include/factorielle.h"
#include <stdio.h>
#include <math.h>

/**
 * Renvoie le résultat de l'opération
 *
 * @author Serge COUDÉ
 *
 * @param char operateur Opérateur de l'opération
 * @param int ope1 Opérande 1
 * @param int ope2 Opérande 2
 * @return double Résultat de l'opération
 */
double calculeOperation(char operateur, int ope1, int ope2) {
	switch(operateur) {
		case '+':
			return ope1 + ope2;
			break;
		case '-':	
			return ope1 - ope2;
			break;
		case 'x':
			return ope1 * ope2;
			break;
		case '/':
			return ope1 / ope2;
			break;
		case '^':
			return pow(ope1, ope2);
			break;
		case '!':
			return factorielle(ope1);
			break;
		default:
			return 0;
			break;
	}
}