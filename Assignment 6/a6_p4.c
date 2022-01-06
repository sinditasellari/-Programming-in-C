/* 
   CH-230-A
   a6 p4.c
   Sindi Tasellari
   stasellari@jacobs-university.de
*/

#include <stdio.h>
/* Computing the scalar product */
#define SCALAR_PRODUCT(vec1,vec2,s,size)\
{\
	int i;\
	for (i=0; i<size; i++)\
    {\
		s += (vec1[i]*vec2[i]);\
	}\
}
/* Computing the intermediate values */
#define INTERMEDIATE(vec1,vec2,vec,size)\
{\
	int j;\
	for (j=0; j<size; j++)\
    {\
		 vec[j] = (vec1[j]*vec2[j]);\
	}\
}

int main () {
	int n; /* The dimension of the two vectors */
	scanf("%d", &n); 
    int idx, scal_p = 0;
	int v1[n], v2[n], vector[n];

	/* Vector 1 */
	for (idx=0; idx<n; idx++)
    {
		scanf("%d", &v1[idx]);
	}
	/* Vector 2 */
	for (idx=0; idx<n; idx++)
    {
		scanf("%d", &v2[idx]);
	}

	/* Use conditional compilation */
	/* Intermediate values will not be printed if INTERMEDIATE is not defined */
	#ifdef INTERMEDIATE
	INTERMEDIATE(v1,v2,vector,n);
	printf("The intermediate product values are:\n");
	for (idx=0; idx<n; idx++)
    {
		printf("%d\n", vector[idx]);
	}
	#endif
		
	SCALAR_PRODUCT(v1,v2,scal_p,n);
	printf("The scalar product is: %d\n", scal_p);
	
	return 0;
}