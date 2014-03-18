#include <stdio.h> // printf et scanf
#include <stdlib.h> // malloc
#include <string.h>

int main(int nbArgs, char **tabArgs) {
	// D�finition des variables
	
	/*h
	 * @var int lng Longueur de la cha�ne
	 */
	int lng;
	
	/*
	 * @var char* pChaine Pointeur vers la cha�ne de caract�res qui sera allou�e
	 */
	char *pChaine;
	
	/*
	 * @var char* pTmp Pointeur temporaire pour modifier pChaine
	 */
	char *pTmp;
	
	/*
	 * @var array tabChar Tableau contenant les caract�res de g�n�ration
	 */
	char tabChar[36] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
	
	/*
	 * @var int i indice de d�placement dans les deux tableaux
	 */
	int i;
	
	printf("Longueur de la cha�ne � g�n�rer : ");
	scanf("%d", &lng);
	pChaine = malloc((lng+1)* sizeof(char));
	if (NULL == pChaine) {
		printf("il n'y a plus de m�moire disponible...\n");
		return -1;
	}
	// Je fais pointer pTmp vers la case m�moire point�e par pChaine
	// je parcours l'ensemble de la cha�ne allou�e
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
