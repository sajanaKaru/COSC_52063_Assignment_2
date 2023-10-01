#include <stdio.h>
#include <time.h>

#define ROWS 8
#define COLS 8   

void matrixVectorMultiply(double matrix[ROWS][COLS], double vector[COLS], double result[ROWS]) {
	for (int i = 0; i < ROWS;i++) {
		result[i] = 0.0;
		for (int j = 0; j < COLS; j++) {
			result[i] += matrix[i][j] * vector[j];							        }
	}
}

int main() {
	
	double matrix[ROWS][COLS] = {
		{1,  2,  3,  4,  5,  6,  7,  8},
		{9, 10, 11, 12, 13, 14, 15, 16},
		{17, 18, 19, 20, 21, 22, 23, 24},
		{25, 26, 27, 28, 29, 30, 31, 32},
		{33, 34, 35, 36, 37, 38, 39, 40},
		{41, 42, 43, 44, 45, 46, 47, 48},
		{49, 50, 51, 52, 53, 54, 55, 56},
		{57, 58, 59, 60, 61, 62, 63, 64}
			    };
	        
	double vector[COLS] = {1, 2, 3, 4, 5, 6, 7, 8};
	double result[ROWS];
	
	printf("Matrix:\n");
	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLS; j++) {
			printf("%.2f ", matrix[i][j]);
		}
		printf("\n");
	}
	 printf("---------------------\n");

	printf("Vector:\n");
	for (int i = 0; i < COLS; i++) {
		printf("%.2f\n", vector[i]);
	}
	 printf("---------------------\n");
	clock_t start,end;
	start = clock();
	matrixVectorMultiply(matrix, vector, result);
	end = clock();

	double due =((double)(end- start))/CLOCKS_PER_SEC;
	printf("Time taken %f\n",due*1000);
	printf("---------------------\n");

	printf("Result:\n");
	for (int i = 0; i < ROWS; i++) {
		printf("%.2f\n", result[i]);
	}

	return 0;
}

