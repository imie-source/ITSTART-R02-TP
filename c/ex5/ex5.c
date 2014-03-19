#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

/**
 * D�finition de la structure r�sultat qui contiendra
 * la note d'un �l�ve
 * le pr�nom de cet �l�ve
 */
struct resultat {
	float noteEleve;
	char* prenomEleve;
};

/**
 * V�rifie si la cha�ne pass�e en param�tre est une note ou pas
 *
 * Parcourt les caract�res de la cha�ne et v�rifie un par un
 * si le caract�res est un chiffre, un point ou une virgule
 *
 * @param char* chaine Cha�ne � v�rifier
 * @return float >= 0 si la cha�ne est bien une note, -1 sinon
 */
float verificationSaisie(char *chaine) {
	// D�finition des variables locales
	/**
	 * @var int lngChaine Longueur de la cha�ne de caract�res
	 */
	int lngChaine;
	/**
	 * @var int i index de parcours de la cha�ne
	 */
	int i;
	/**
	 * @var char c caract�re courant
	 */
	char c;
	
	// algo de la fonction verificationSaisie
	lngChaine = strlen(chaine);
	for(i = 0; i < lngChaine; i++) {
		c = chaine[i];
		if ( ( c < '0' ||  c > '9') &&
		     ( c != '.' ) &&
			 ( c != ',' ) ) {
			 return -1;
		}
		// Remplacement de la virgule par un point
		// pour la conversion en float via atof
		if (c == ',') {
			chaine[i] = '.';
		}
	}
	return atof(chaine);
}

/**
 * Affiche l'ensemble des notes, une par ligne
 *
 * @param int nbNotes Nombre de notes saisies
 * @param array tabRes Tableau des r�sultats
 */
void afficherNotes(int nbNotes, struct resultat tabRes[]) {
	/**
	 * @var int i index de parcours des notes
	 */
	int i;
	printf("Voici les notes saisies :\n");
	for(i = 0; i < nbNotes; i++) {
		printf("\tnote %d (%s): %2.2f\n", 
			   (i+1), 
			   tabRes[i].prenomEleve, 
			   tabRes[i].noteEleve); 
	}
}

/**
 * Premi�re fonction appel�e par le programme
 *
 * Effectue la saisie des notes, puis le calcul de la moyenne,
 * du min, du max et de l'�cart-type de l'ensemble des notes
 *
 * @author Serge COUD�
 * @return int Code de fin
 */
int main() {

// D�finition des variables globales
/**
 * @var array saisie Tableau de caract�res pour la saisie de note
 */ 
char saisie[6];
/**
 * @var float moy Moyenne des notes
 */
float moy;
/**
 * @var float som Somme des notes
 */
float som = 0;
/**
 * @var int nbn Nombre des notes
 */
int nbn = 0;
/**
 * @var float ety Ecart-type de l'ensemble des notes
 */
float ety;
/**
 * @var float note Note 
 */
float note;
/**
 * @var float carsom Somme des carr�s des notes
 */
float carsom = 0; 

/**
 * @var pointer pTmp Pointeur "temporaire" pour la r�allocation de m�moire
 */
struct resultat *pTmp;

/**
 * @var array prenom Cha�ne de caract�res qui contiendra le pr�nom
 */
char prenom[20];

/**
 * @var resultat* pResultats Tableau des r�sultats
 */
struct resultat *pResultats;

/**
 * @var int iMin Indice du r�sultat minimum
 */
int iMin;

/**
 * @var int iMax Indice du r�sultat maximum
 */
int iMax;

// L'algorithme

printf("Veuillez saisir les prenoms et les notes\n\t<prenom> <note>\nfinir par le mot 'fin fin'\n");
while( strcmp(prenom, "fin") ) {
	scanf("%s %s", &prenom, &saisie);
	note = verificationSaisie(saisie);
	if (note >= 0) {
		
		if (nbn == 0) {
			/* On n'a pas encore allou� de m�moire, on utilise
			   donc malloc
			  */
			pResultats = malloc(1*sizeof(struct resultat));
			if (NULL == pResultats) {
				// On indique qu'il n'y plus de m�moire
				printf("Plus de m%cmoire disponible...", 130);
				// et on termine le programme avec un code erreur
				return -1;
			}
		} else {
			// J'alloue un �l�ment suppl�mentaire dans le tableau des r�sultats
			pTmp = realloc(pResultats, (nbn+1)*sizeof(struct resultat));
			// Si l'allocation s'est bien pass�e
			if (NULL != pTmp) {
				// On fait pointer pNotes vers la nouvelle plage de m�moire
				pResultats = pTmp;
			} else {
				// On indique qu'il n'y plus de m�moire
				printf("Plus de m%cmoire disponible...", 130);
				// et on termine la boucle de saisie
				break;
			}	
		}
		// Maintenant, j'ai la m�moire disponible pour stocker les informations (note et pr�nom)
		pResultats[nbn].noteEleve = note;
		pResultats[nbn].prenomEleve = malloc((strlen(prenom)+1)*sizeof(char));
		strcpy(pResultats[nbn].prenomEleve, prenom);
		nbn++; 
		
		if (nbn == 1) {
			iMin = nbn-1;
			iMax = nbn-1;
		}
		som += note;
		carsom += (note*note);
		if (note < pResultats[iMin].noteEleve) {
			iMin = nbn-1;
		}
		if ( note > pResultats[iMax].noteEleve ) {
			iMax = nbn-1;
		}
	} else {
		if ( strcmp(saisie, "fin") != 0) {
			printf("Veuillez saisir une note valide\n");
		}	
	}
}
if (nbn != 0) {
	afficherNotes(nbn, pResultats);
	moy = som / nbn; // Calcul de la moyenne
	ety = sqrt( ( carsom / nbn ) - ( ( som * som ) /  ( nbn * nbn ) ) ); // Calcul de l'�cart-type
	printf("La moyenne est : %2.2f\n", moy); 
	printf("La note la plus basse (%s) : %2.2f\n", pResultats[iMin].prenomEleve, pResultats[iMin].noteEleve);
	printf("La note la plus haute (%s) : %2.2f\n", pResultats[iMax].prenomEleve, pResultats[iMax].noteEleve);
	printf("l'%ccart-type : %2.2f\n", 130, ety);
} else {
	printf("Vous n'avez pas saisi de notes...\n");
}
// Lib�ration de la m�moire allou�e dynamiquement
for(nbn--; nbn >= 0; nbn--) {
	free(pResultats[nbn].prenomEleve);
}
free(pResultats);
return 0;
}