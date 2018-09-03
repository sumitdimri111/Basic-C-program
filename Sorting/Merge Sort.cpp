#include<iostream>
#include<fstream>
using namespace std;

int comparision=0;

void join(int a[], int l, int mid, int r) {
	int n1 = mid+1 - l;
	int n2 = r-mid;
	int left[n1], right[n2];

	for(int i=0; i<n1; i++)
		left[i] = a[l+i];
	for(int i=0; i<n2; i++)
		right[i] = a[mid+1 +i];
	
	int i=0, j=0, k=l;
	
	while(i < n1 && j < n2) {
		if(left[i] < right[j]) {
			a[k] = left[i++];
			comparision++;
		}
		else
			a[k] = right[j++];
		k++;
	}

	while(i < n1)
		a[k++] = left[i++];
	while(j < n2)
		a[k++] = right[j++];
}

void mergeSort(int a[], int l, int r)
{
	if(l < r)
	{
		int mid = l+(r-l)/2;
	
		mergeSort(a, 0, mid);
		mergeSort(a, mid+1, r);

		join(a, l, mid, r);
	}
}

int main()
{
	cout << "\t***** Merge Sort ******\n";
	int a[] = {85, 5, 2, 10, 22, -1, 12, 23, 102, 11, 1, 44, 59};
	int n = sizeof(a)/sizeof(a[0]);
	
	cout << "\nGiven Array : ";
	for(int i=0; i<n; i++)
		cout << a[i] << " ";
	cout << endl;
		
		mergeSort(a,0,n-1);

	cout << "\nSorted Array : ";
	for(int i=0; i<n; i++)
		cout << a[i] << " ";
	
	cout << "\nTotal Comparision : " << comparision << endl;
 return 0;
}

