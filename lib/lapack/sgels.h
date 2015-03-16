#ifdef __cplusplus
extern "C" { 
#endif  

#include "f2c.h" 

#define integer int
int sgels_(char *trans, integer *m, integer *n, integer *nrhs, real *a, integer *lda, real *b, integer *ldb, real *work, integer *lwork, integer *info);
#undef integer

#ifdef __cplusplus
}
#endif