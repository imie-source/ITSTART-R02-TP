#include <stdio.h> // printf et scanf
#include <stdlib.h> // malloc
#include <string.h>

int main(int nbArgs, char **tabArgs) {
	// Définition des variables
	
	/*h
	 * @var int lng Longueur de la chaîne
	 */
	int lng;
	
	/*
	 * @var char* pChaine Pointeur vers la chaîne de caractères qui sera allouée
	 */
	char *pChaine;
	
	/*
	 * @var char* pTmp Pointeur temporaire pour modifier pChaine
	 */
	char *pTmp;
	
	/*
	 * @var array tabChar Tableau contenant les caractères de génération
	 */
	char tabChar[36] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
	
	/*
	 * @var int i indice de déplacement dans les deux tableaux
	 */
	int i;
	
	printf("Longueur de la chaîne à générer : ");
	scanf("%d", &lng);
	pChaine = malloc((lng+1)* sizeof(char));
	if (NULL == pChaine) {
		printf("il n'y a plus de mémoire disponible...\n");
		return -1;
	}
	// Je fais pointer pTmp vers la case mémoire pointée par pChaine
	// je parcours l'ensemble de la chaîne allouée
	for(i = 0, pTmp = pChaine; i < lng; i++, pTmp++) {
		//pChaine[i] = tabChar[i % 36];
		*pTmp = tabChar[i % 36];
	}
	//pChaine[i] = '\0';
	*pTmp = '\0';
	printf("%s\n", pChaine);
	free(pChaine);
	return 0;
}
