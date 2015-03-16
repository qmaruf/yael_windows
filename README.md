# yael_windows

Source is taken from [inria][1]. As this is not compatible with windows I have performed some tweaking and added necessary libraries (e.g: arpack, blas, lapack) to meet my goal. Now it can compile and execute two examples (kmeans and gmm) provided with the original source. Though it is not tested thoroughly (only tested it using visual studio 2010, solution platform win32), hopefully it will give a head start to run yael library in windows.

###Known bug
kmeans crashes if I ask it to return nearest neighbors greater than 1. 

[1]:https://gforge.inria.fr/frs/?group_id=2151
