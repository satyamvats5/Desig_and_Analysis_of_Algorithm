/*
 * Using Quick sort to sort an array in ascending order.
 * Author: Satyam Kumar <satyamkumar4@acm.org>
 * Repo: Design_And_Analysis_of_Algorithm [MIT LICENSE]
 */

#include <stdio.h>
#include <stdlib.h>

void interchange(int *a, int * b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}


void quick_sort(int A[], int m, int n)
{
	if(m < n) {
	int i = m, j = n, key = A[m],s  = 1;
	while(s) {
		for(i = m; i < n; i++) {
			if(A[i] > key) break;
		}
	
		for( j = n; j > m; j--) {
			if(A[j] <= key) break;
		}
	
		if(i < j) interchange(&A[i], &A[j]);
		else break;
	}
	interchange(&A[j], &A[m]);
	quick_sort(A, m, j-1);
	quick_sort(A, j+1, n);
	} else return;
}


int main(int argc, char ** argv)
{
	if(argc < 2) {
		fprintf(strderr,"Usage: %s n [n-elemnts]\n", argv[0]);
		return EXIT_FAILURE;
	}

	int n = atoi(argv[1]);
	if(argc != (n + 2)) {
		printf(stderr, "Fatal Error: Invalid number of intefers supplied\n");
		return EXIT_FAILURE;
	}

	int arr[n];
	for(int i = 0; i < n; i++) {
		arr[i] = atoi(argv[i+2]);
	}

	quick_sort(arr,0,s-1);

	printf("After sorting array is : ");
	for(int i = 0; i < s; i++) {
		printf("%d\t",arr[i]);
	}
	printf("\n");
	return EXIT_SUCCESS;
}
