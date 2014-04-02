#ifndef _IA_H
#define _IA_H

#include "coupjouable.h"

struct coupJouable * detectePresqueGagneHV(char p[3][3], int pos, int o, char c1, char c2);

struct coupJouable * detectePresqueGagneD(char p[3][3], char c1, char c2);

struct coupJouable * iaGagne (char p[3][3], char c1, char c2);

char * trouveCaseVide(char p[3][3]);

char * coupJoueParOrdinateur(char p[3][3], char c1, char c2);

#endif