#include<iostream>
using namespace std;

void pattern1(int n) {
	/*
		*****
		****
		***
		**
		*
	*/
	for(int i=0; i<n; i++) {
		for(int j=i; j<n; j++)
			cout << "*";
		cout << endl;
	}
}

void pattern2(int n) {
	/*
		*
		**
		***
		****
		*****
	*/
	for(int i=0; i<n; i++) {
		for(int j=i; j>=0; j--)
			cout << "*";
		cout << endl;
	}
}

void pattern3(int n) {
	/*
		    *
		   **
		  ***
		 ****
		*****
	*/
	for(int i=0; i<n; i++) {
		for(int j=1; j<n-i; j++)
			cout << " ";
		for(int j=i; j>=0; j--)
			cout << "*";
		cout << endl;
	}
}

void pattern4(int n) {
	/*
		    *
		   * *
		  * * *
		 * * * *
		* * * * *
	*/
	for(int i=0; i<n; i++) {
		for(int j=1; j<n-i; j++)
			cout << " ";
		for(int j=i; j>=0; j--)
			cout << "* ";
		cout << endl;
	}
}

void pattern5(int n) {
	/*
		    1
		   12
		  123
		 1234
		12345
	*/
	for(int i=0; i<n; i++) {
		for(int j=1; j<n-i; j++)
			cout << " ";
		for(int j=0; j<=i; j++)
			cout << j+1;
		cout << endl;
	}
}

void pattern6(int n) {
	/*
		* * * * *
		 * * * *
		  * * *
		   * *
		    *
	*/
	for(int i=0; i<n; i++) {
		for(int j=i; j>0; j--)
			cout << " ";
		for(int j=0; j<n-i; j++)
			cout << "* ";
		cout << endl;
	}
}

int main()
{
	int n;
//	cin >> n;
//	pattern1(5);
//	pattern2(5);
//	pattern3(5);
//	pattern4(5);
//	pattern5(5);
	pattern6(5);
	

 return 0;
}

