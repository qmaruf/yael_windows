#ifdef __cplusplus
extern "C" { 
#endif  

#include "f2c.h" 
#define integer int
int dsyev_(char *jobz, char *uplo, integer *n, doublereal *a, integer *lda, doublereal *w, doublereal *work, integer *lwork, integer *info);
#undef integer
#ifdef __cplusplus
}
#endif