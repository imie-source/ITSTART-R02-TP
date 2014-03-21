#include <stdlib.h>
#include <stdio.h>
#include "../include/resultat.h"
#include "../include/dothejob.h"

void test(char *ope, double res, int erreur) {
	struct resultat *pRes = NULL;
	pRes = doTheJob(ope);
	if ((!erreur && !(*pRes).erreur && 
	     res == (*pRes).resultat) || 
		(erreur && (*pRes).erreur)) {
		printf("Test %s OK\n", ope);
	} else {
		printf("Test %s KO (%lf / %lf)\n", ope, (*pRes).resultat, res);
	}
	free(pRes);
}	

int main() {
	test("15 + 2", 17, 0);
	test("5!", 120, 0);
	test("3       x     10", 30, 0);
	test("100   - 3", 97, 0);
	test("20/2", 10, 0);
	test("2^8", 256, 0);
	test("20/0", 0, 1);
	return 0;
}