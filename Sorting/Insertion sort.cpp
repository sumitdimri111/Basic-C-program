#include<iostream>
using namespace std;

int main()
{
	cout << "\t***** Insertin Sort ******\n";
	int a[] = {85, 5, 2, 10, 22, -1, 12, 23, 102, 11, 1, 44, 59};
	int n = sizeof(a)/sizeof(a[0]);
	
	cout << "\nGiven Array : ";
	for(int i=0; i<n; i++)
		cout << a[i] << " ";
		cout << endl;
		
	for(int i=1; i<n; i++) {
		int key = a[i], j=i-1;
		while(j>=0 && key < a[j])
			a[j+1] = a[j--];
		a[j+1] = key;
	}

	cout << "\nSorted Array : ";
	for(int i=0; i<n; i++)
		cout << a[i] << " ";

 return 0;
}

