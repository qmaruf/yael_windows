#ifdef __cplusplus
extern "C" { 
#endif  

#include "f2c.h" 
#define integer int
int dsygv_(integer *itype, char *jobz, char *uplo, integer *n, doublereal *a, integer *lda, doublereal *b, integer *ldb, doublereal *w, doublereal *work, integer *lwork, integer *info);
#undef integer
#ifdef __cplusplus
}
#endif