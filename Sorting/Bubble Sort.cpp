#include<iostream>
using namespace std;

int main()
{
	cout << "\t***** Bubble Sort ******\n";
	int a[] = {5, 2, 10, 22, 12, 23, 102, 11, 1, 44, 59};
	int n = sizeof(a)/sizeof(a[0]);
	
	cout << "\nGiven Array : ";
	for(int i=0; i<n; i++)
		cout << a[i] << " ";
		cout << endl;
		
	for(int i=0; i<n-1; i++) {
		for(int j=i+1; j<n; j++)
			if(a[j] > a[j-1]) {
				int temp = a[i];
				a[i] = a[j];
			 	a[j] = temp;
			}
	}

	cout << "\nSorted Array : ";
	for(int i=0; i<n; i++)
		cout << a[i] << " ";

 return 0;
}

