#include<stdio.h>
void swap(int &a, int &b) {
    int t = a;
    	a = b;
    	b = t;
}

int partition (int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = low;
    for (int j=low; j<high; j++)
    	if (arr[j] <= pivot)
        	swap(arr[j], arr[i++]);
    swap(arr[i], arr[high]);
	return i;
}

void quickSort(int arr[], int low, int high)
{
    if (low < high) {
		int pi = partition(arr, low, high);
		quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void printArray(int arr[], int size)
{
   for (int i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main()
{
	printf("\t***** Quick Sort ******\n");
	int a[] = {85, 5, 2, 10, 22, -1, 12, 23, 102, 11, 1, 44, 59};
	int n = sizeof(a)/sizeof(a[0]);
	
	printf("\nGiven Array :\n");
	for(int i=0; i<n; i++)
		printf("%d ",a[i]);
		printf("\n");
	
	quickSort(a, 0, n-1);
    
	printf("Sorted array:\n");
    printArray(a, n);
    return 0;
}
