#include <stdio.h> // printf et scanf
#include <stdlib.h> // malloc

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
	 * @var array tabChar Tableau contenant les caract�res de g�n�ration
	 */
	char tabChar[36] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
	
	printf("Longueur de la cha�ne � g�n�rer : ");
	scanf("%d", &lng);
	pChaine = malloc((lng+1) * sizeof(char));
	if (NULL == pChaine) {
		printf("il n'y a plus de m�moire disponible...\n");
		return -1;
	}
	
	printf("%s\n", pChaine);
	free(pChaine);
	return 0;
}
