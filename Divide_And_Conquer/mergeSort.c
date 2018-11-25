/*
 * Using Divide and Conquer to sort and array by Merge Sort Technique.
 * Author: Satyam Kumar <satyamkumar4@acm.org>
 * Repo: Design_And_Analysis_of_Algorithm [MIT LICENSE]
 */

#include <stdio.h>
#include <stdlib.h>

void merge1(int A[], int l, int m, int mid) 
{
	int N1 = mid - l + 1;
	int N2 = m - mid;
	int L[N1], R[N2];

	for(int i = 0; i < N1; i++) {
		L[i] = A[l+i];		//Constructing left matrix
	}

	for(int i = 0; i < N2; i++) {
		R[i] = A[mid + 1 + i];	////Constructing right matrix
	}

	int i1 = 0, i2 = 0, i3 = l;

	while(i1 < N1 && i2 < N2) {  	// merging of two halves if both left and right matrix are present.
		if(L[i1] < R[i2] ) {
			A[i3] = L[i1];
			i1++; i3++;
		} else {
			A[i3] = R[i2];
			i3++; i2++;
		}
	}
	while(i1 < N1) {		//Merging when only left matrix is present.
		A[i3] = L[i1];
		i3++; i1++;
	}
	while(i2 < N2) {		//Merging when only right matrix is present.
		A[i3] = R[i2];
		i3++; i2++;
	}
	return ;
}

void merge(int ARR[],int l,int m) 
{
	if(l >= m) 	//Base critera
		return;
	else {
		int mid = l + (m - l) / 2;
		merge(ARR, l, mid);	//Recursion using left half 
		merge(ARR, mid + 1, m); //Recursion using right half
		merge1(ARR, l, m, mid);		//Merging both left and right halves
	}
}	

int main(int argc, const char * argv[])
{
	if(argc < 2) {
		fprintf(stderr, "Usage %s [n] [n - integers]\n", argv[0]);
		return EXIT_FAILURE;
	}
	int n = atoi(argv[1]);
	if(argc != (n + 2)) {
		fprintf(stderr, "Fatal error: Invalid number of integers supplied\n");
		return EXIT_FAILURE;
	}

	int A[n];
	for(int i = 0; i < n; i++)  {
		A[i] = atoi(argv[i + 2]);
	}
	
	printf("Original array is : ");
	for(int i = 0; i < n || !putchar('\n') ; i++) {
		printf("%d ",A[i]);
	}
	
	merge(A, 0, n - 1);

	printf("Sorted array is as follows : ");
	for(int i = 0; i < n || !putchar('\n'); i++) {
		printf("%d ",A[i]);
	}
	
	return 0;	
}
