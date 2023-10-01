#include <stdio.h>
#include <omp.h>


void swap(int* a, int* b)
{
	int t = *a;
	*a = *b;
	*b = t;
}


int partition(int arr[], int low, int high)
{
	   
	int pivot = arr[high];
	int i = (low - 1);

	for (int j = low; j <= high - 1; j++) {
		if (arr[j] < pivot) {
			    i++;
			    swap(&arr[i], &arr[j]);
		}
				        }
	swap(&arr[i + 1], &arr[high]);
	return (i + 1);
}

void quickSort(int arr[], int low, int high)
{
	/*if (low < high) {
		int pi = partition(arr, low, high);
	
		#pragma omp parallel
		{
			#pragma omp single nowait
			{
				#pragma omp task
				quickSort(arr, low, pi - 1);
			}
				
			#pragma omp task
			quickSort(arr, pi + 1, high);
			
		}
	}*/
	
	if(low < high){
		int pi = partition(arr, low, high);
	 	if (high - low > 1000) {
			#pragma omp parallel
		 	{
				#pragma omp single nowait
				{
					#pragma omp task
					quickSort(arr, low, pi - 1);
				}

				#pragma omp task
				quickSort(arr, pi + 1, high);
								                
		 	}
	 	} else {
			quickSort(arr, low, pi - 1);
			quickSort(arr, pi + 1, high);
		}
	}
}


int main()
{
	
	int arr[] = {56, 23, 89, 12, 45, 67, 34, 90, 1, 77,
		         3,  55, 88, 19, 78, 2,  46, 66, 99, 31,
			65, 8,  21, 54, 9,  42, 87, 11, 76, 28,
			33, 69, 91, 14, 51, 72, 7,  30, 64, 36,
			59, 41, 84, 15, 70, 4,  61, 86, 25, 37,									                    
			80, 16, 53, 38, 71, 10, 57, 44, 68, 22,
			6,  85, 32, 75, 17, 58, 24,47,73,5,
			49, 82, 27, 74, 35, 62, 18, 60, 48, 81,
			29, 50, 83, 20, 63, 26, 52, 40,43,35,
			94, 92, 96, 98, 93, 97, 79, 100, 91, 1};
	int N = sizeof(arr) / sizeof(arr[0]);
	double tstart,tstop,tcalc;

	//omp_set_dynamic(0);
	//omp_set_num_threads(4);


	tstart = omp_get_wtime();
	quickSort(arr , 0, N  - 1);
	tstop = omp_get_wtime();
	tcalc = tstop - tstart;												                 
	printf("Time taken %f\n",tcalc);

	printf("Sorted array: \n");												                 
	for (int i = 0; i < N; i++)										
		printf("%d ", arr[i]);
	printf("\n");											                 	
	return 0;
}
