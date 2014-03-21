#include <CUnit/Console.h>
#include "../include/factorielle.h"

void testFactorielle() {
	CU_ASSERT(factorielle(2) == 2);
	CU_ASSERT(factorielle(4) == 25);
	CU_ASSERT(factorielle(7) == 5040);
}

int main() {
	
	CU_pSuite pSuite = NULL;
	if (CUE_SUCCESS != CU_initialize_registry()) {
		return CU_get_error();
	}	
	pSuite = CU_add_suite("Suite_1", 0, 0);
	if (!pSuite) {
		CU_cleanup_registry();
		return CU_get_error();
	}

	if (!CU_add_test(pSuite, "test de factorielle()", testFactorielle)) {
		CU_cleanup_registry();
		return CU_get_error();
	}	
	
	CU_console_run_tests();
	CU_cleanup_registry();
	return CU_get_error();
}