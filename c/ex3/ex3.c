#include <stdio.h> // printf et scanf
#include <stdlib.h> // malloc

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
	 * @var array tabChar Tableau contenant les caractères de génération
	 */
	char tabChar[36] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
	
	printf("Longueur de la chaîne à générer : ");
	scanf("%d", &lng);
	pChaine = malloc((lng+1) * sizeof(char));
	if (NULL == pChaine) {
		printf("il n'y a plus de mémoire disponible...\n");
		return -1;
	}
	
	printf("%s\n", pChaine);
	free(pChaine);
	return 0;
}
