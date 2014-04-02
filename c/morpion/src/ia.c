#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/ia.h"
#include "../include/random.h"

struct coupJouable * detectePresqueGagneHV(char p[3][3], int pos, int o, char c1, char c2) {
	int i;
	int j1 = 0;
	int j2 = 0;
	int t;
	struct coupJouable *cj = malloc(sizeof(struct coupJouable));
	int pv;
	if (NULL == cj) {
		return cj;
	}	
	if (1 == o) { // vertical
		for(i = 0; i < 3; i++) {
			if (p[i][pos] == c1) {
				j1++;
			} else {
				if (p[i][pos] == c2) {
					j2++;
				} else {
					pv = i;
				}
			}
		}
	} else { // horizontal
		for(i = 0; i < 3; i++) {
			if (p[pos][i] == c1) {
				j1++;
			} else {
				if (p[pos][i] == c2) {
					j2++;
				} else {
					pv = i;	
				}
			}
		}
	}
	t = j1 + j2;
	if (2 == t) {
		if (2 == j1) {
			(*cj).jpg = 1;
			if (1 == o) { // vertical
				sprintf((*cj).coup, "%d%d", pv+1, pos+1);
			} else { // Horizontal
				sprintf((*cj).coup, "%d%d", pos+1, pv+1);
			}
			return cj;
		}
		if (2 == j2) {
			(*cj).jpg = 2;
			if (1 == o) { // vertical
				sprintf((*cj).coup, "%d%d", pv+1, pos+1);
			} else { // Horizontal
				sprintf((*cj).coup, "%d%d", pos+1, pv+1);
			}
			return cj;
		}
	}
	(*cj).jpg = 0;
	return cj;
}

struct coupJouable * detectePresqueGagneD(char p[3][3], char c1, char c2) {
	char c = ' ';
	struct coupJouable *cj = malloc(sizeof(struct coupJouable));
	if (NULL == cj) {
		return cj;
	}	
	if ((p[0][0] == p[1][1] && p[2][2] == ' ' && (c = p[0][0]) && (strcpy((*cj).coup, "33"))) ||
		(p[0][0] == p[2][2] && p[1][1] == ' ' && (c = p[0][0]) && (strcpy((*cj).coup, "22"))) ||
		(p[1][1] == p[2][2] && p[0][0] == ' ' && (c = p[1][1]) && (strcpy((*cj).coup, "11"))) ||
		(p[2][0] == p[0][2] && p[1][1] == ' ' && (c = p[2][0]) && (strcpy((*cj).coup, "22"))) ||
		(p[2][0] == p[1][1] && p[0][2] == ' ' && (c = p[2][0]) && (strcpy((*cj).coup, "13"))) ||
		(p[1][1] == p[0][2] && p[2][0] == ' ' && (c = p[1][1]) && (strcpy((*cj).coup, "31")))) {
		if (c == c1) {
			(*cj).jpg = 1;
		} else { 
			(*cj).jpg = 2;
		}
		return cj;
	}
	(*cj).jpg = 0;
	return cj;
}

struct coupJouable * iaGagne (char p[3][3], char c1, char c2) {
	struct coupJouable *cj = malloc(sizeof(struct coupJouable));
	if (NULL == cj) {
		return cj;
	}	
	int i; 
	for(i = 0; i < 3; i++) {
		cj = detectePresqueGagneHV(p, i, 1, c1, c2);
		if ((*cj).jpg != 0) {
			return cj;
		}
		cj = detectePresqueGagneHV(p, i, 0, c1, c2);
		if ((*cj).jpg != 0) {
			return cj;
		}
		return detectePresqueGagneD(p, c1, c2);
	}	
}

char * trouveCaseVide(char p[3][3]) {
	int l;
	int c;
	char tabCasesVides[9][3];
	int nbCasesVides = 0;
	int rang;
	char *caseVide = calloc(3, sizeof(char));
	if (p[1][1] == ' ') {
		return "22";
	}
	for(l = 0; l < 3; l++) {
		for (c = 0; c < 3; c++) {
			if (p[l][c] == ' ') {
				sprintf(tabCasesVides[nbCasesVides], "%d%d", l+1, c+1);
				nbCasesVides++;
			}
		}
	}
	rang = random(0, nbCasesVides-1);
	strcpy(caseVide, tabCasesVides[rang]);
	return caseVide;
}

char * coupJoueParOrdinateur(char p[3][3], char c1, char c2) {
	struct coupJouable *cj;
	cj = iaGagne(p, c1, c2);
	if (2 == (*cj).jpg || 1 == (*cj).jpg) {
		return (*cj).coup;
	}
	return trouveCaseVide(p);
}