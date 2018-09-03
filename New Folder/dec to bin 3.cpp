#include<iostream>
using namespace std;

int main()
{
	int n;
	long long int bin=1;

	cout << "Enter decimal number : ";
	cin >> n;

	while(n>1)
	{
		bin = bin*10 + n%2;
		n /= 2;
	}
	cout << "Binary number : " << bin << endl;

	main();
 return 0;
}

