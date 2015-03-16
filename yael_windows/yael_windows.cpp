#include <assert.h>
#include <stdio.h>
#include <Windows.h>
#include <yael/vector.h>
#include <yael/kmeans.h>
#include <yael/machinedeps.h>
#include <yael/gmm.h>

void t_kmeans()
{
	int k = 50;                           /* number of cluster to create */
	int d = 20;                           /* dimensionality of the vectors */
	int n = 1000;                         /* number of vectors */
	int nt = 2;                           /* number of threads to use */
	int niter = 0;                        /* number of iterations (0 for convergence)*/
	int redo = 1;                         /* number of redo */

	float * v = fvec_new_rand (d * n);    /* random set of vectors */

	/* variables are allocated externaly */
	float * centroids = fvec_new (d * k); /* output: centroids */
	float * dis = fvec_new (n);           /* point-to-cluster distance */
	int * assign = ivec_new (n);          /* quantization index of each point */
	int * nassign = ivec_new (k);         /* output: number of vectors assigned to each centroid */

	double t1 = GetTickCount();
	kmeans (d, n, k, niter, v, 1, 1, redo, centroids, dis, assign, nassign);
	double t2 = GetTickCount();

	printf ("kmeans performed in %.3f ms\n", (t2 - t1));

	ivec_print (nassign, k);
	return;
}

void t_gmm()
{
#define FMT_FVEC  0
#define FMT_TEXT  1

	int i;
	int k = 10;  // number of cluster
	int d = 10;  // each sample dimension
	int n = 50;  // samples
	int niter = 10;
	int nredo = 1;
	int nt = count_cpu();
	int seed = 0;
	int ret;
	int fmt_in = FMT_TEXT;
	int fmt_out = FMT_TEXT;
	int compute_w = 0; /* Version with balanced.
					   Use int compute_w = 1; if you want w to be computed */

	const char * fi_name = "data.dat";
	const char * fo_name = NULL;

	/* read the input vectors */

	/* read the vectors from the input file */
	float * v = fvec_new (n * d);
	if (fmt_in == FMT_FVEC)
		ret = fvecs_read (fi_name, d, n, v);
	else if (fmt_in == FMT_TEXT)
		ret = fvecs_read_txt (fi_name, d, n, v);
	else exit (1);
	assert (ret == n);

	
	gmm_t * g = gmm_learn(d, n, k, niter, v, nt, seed, nredo, compute_w);
	gmm_delete(g);	

	return;
}
int main (int argc, char ** argv)
{
	//t_kmeans();
	t_gmm();
	return 0;
}
