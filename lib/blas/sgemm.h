#ifdef __cplusplus
extern "C" { 
#endif  

#include "f2c.h" 

#define integer int
#define real float
int sgemm_(char *transa, char *transb, integer *m, integer *n, integer *k, real *alpha, real *a, integer *lda, real *b, integer *ldb, real *beta, real *c__, integer *ldc);
#undef integer
#undef real

#ifdef __cplusplus
}
#endif