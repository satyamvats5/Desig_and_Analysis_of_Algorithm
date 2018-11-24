/*
 * Putting N Queens in a chess board in safe positions
 * Author: Satyam Kumar <satyamkumar4@acm.org>
 * Repo: Design_And_Analysis_of_Algorithm [MIT LICENSE]
 */

#include <stdio.h>
#include <stdlib.h>

int isSafe(int n, int Board[n][n], int row, int col)
{
	// Chceking for same same row and samw column
	for (int i = 0; i < n; i++) {
		if (Board[row][i] || Board[i][col]) {
			return 0;
		}
	}
	
	// checking for upper left diagonal 
	for (int i = row, j = col; i >= 0 && j >= 0; --i, --j) {
		if (Board[i][j]) {
			return 0;
		}
	}

	// checking for upper right diagonal
	for (int i = row, j = col; i < n && j >= 0; i++, j--) {
		if (Board[i][j]) {
			return 0;
		}
	}
	return 1;
}


static int putQueen(int n, int A[n][n], int col) 
{
	if(col >= n )
		return 1;

	for(int i = 0; i < n; i++) {

		if(isSafe(n, A, i, col)) {
			// Test for other choices if all hold, it is correct choice else not
			A[i][col] = 1;
			if(putQueen(n, A, col+1)) {
				return 1;
			}
			
			A[i][col] = 0; // If the made choice does not hold revert it.
		}
	}
	return 0;
}

void NQueens(int n)
{
	int A[n][n];
	for(int i = 0, j = 0; j < n || (j = 0, ++i) < n; j++) 
		A[i][j] = 0;

	if(n > 3 && putQueen(n, A, 0)) {
		for(int i = 0, j =0; j < n || (j = !putchar('\n'), ++i) < n; j++) {
			printf("%d\t", A[i][j]);
		}
		return;
	}
	printf("No solution found :(\n");
}



int main(int argc, char ** argv)
{
	if(argc != 2) {
		fprintf(stderr, "Usage: %s [n] \n", argv[0]);
		return EXIT_FAILURE;
	}
	int n = atoi(argv[1]);
	NQueens(n);
	return EXIT_SUCCESS;
}
