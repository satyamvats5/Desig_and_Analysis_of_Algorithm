/*
 * Using Divide and Conquer to search an element in an array
 * Author: Satyam Kumar <satyamkumar4@acm.org>
 * Repo: Design_And_Analysis_of_Algorithm [MIT LICENSE]
 */

#include <stdio.h>
#include <stdlib.h>

int binarySearch(int A[], int n, int key) {
	int max = n, min = 0, mid;
	do {
		mid = (max + min) / 2;
		if (A[mid] == key) {
			return mid;
		} else if(A[mid] > key) {
			max = mid - 1;
		} else {
			min = mid + 1;
		}
	} while (min <= max);
	
	return -1;
}	

int main(int argc, char ** argv)
{
	if(argc < 2) {
		fprintf(stderr, "Usage %s [n] [n integers] [key]\n", argv[0]);
		return EXIT_FAILURE;
	}
	
	int n = atoi(argv[1]);
	if(argc  != (n+3)) {
		fprintf(stderr, "Fatal Error: Invalid number of integers supplied\n");
		return EXIT_FAILURE;
	}
	
	int a[n], key, i;
	for(i = 0; i < n; i++) 
		a[i] = atoi(argv[i+2]);
	key = atoi(argv[i+2]);
	
	printf("Entered key is : %d\n", key);
	printf("Key found at pos : %d\n", (binarySearch(a, n, key) + 1));
	return EXIT_SUCCESS;

}
