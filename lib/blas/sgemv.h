#ifdef __cplusplus
extern "C" { 
#endif  

#include "f2c.h" 

#define integer int
#define real float
int sgemv_(char *trans, integer *m, integer *n, real *alpha, real *a, integer *lda, real *x, integer *incx, real *beta, real *y, integer *incy);
#undef integer
#undef real
#ifdef __cplusplus
}
#endif