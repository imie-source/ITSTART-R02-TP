#include <stdio.h>
#include <string.h>

int main(int nbArg, char *tArg[]) {
	//printf("nbArg : %i\n", nbArg);
	if (nbArg >= 2) {
		// On a au moins un argument pass�
		int i;
		printf("Bonjour ");
		for(i = 1; i < nbArg; i++) {
			// Pour chaque argument pass� au programme
			if (i < nbArg-1) {
				// je ne suis pas encore arriv� au dernier
				// argument
				printf("%s et ", tArg[i]);
			} else {
				// je suis arriv� au dernier argument
				printf("%s", tArg[i]);
			}
		}
		printf(" !\n");
	} else {
		// il n'y a pas d'argument pass�
		// on demande un pr�nom
		char prenom[31]; // variable de type tableau de caract�res contenant 31 �lements pour 30 caract�re
		printf("Veuillez saisir votre pr\x82nom : ");
		gets(prenom);
		printf("Bonjour %s !\n", prenom);
	}
	
	return 0;
}

