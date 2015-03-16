#ifdef __cplusplus
extern "C" { 
#endif  

#include "f2c.h" 

#define integer int
int sgeqrf_(integer *m, integer *n, real *a, integer *lda, real *tau, real *work, integer *lwork, integer *info);
#undef integer
#ifdef __cplusplus
}
#endif