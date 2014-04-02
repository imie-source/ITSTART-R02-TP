#ifndef _COUP_JOUABLE_H
#define _COUP_JOUABLE_H

/**
 * Structure permettant de stocker le joueur potentiellement
 * gagnant et le coup à jouer pour qu'il gagne
 */
struct coupJouable {
	/**
	 * @var int jpg Joueur potentiellement gagnant
	 */
	int jpg;
	
	/**
	 * @var array coup Coordonnées du coup vainqueur
	 */
	char coup[3];

};	
#endif