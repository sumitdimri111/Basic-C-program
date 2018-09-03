#include<iostream>
using namespace std;

int main()
{
	long long int n=9123442602329;
	int freq[10]={0};
	cout << "Number is : " << n << endl;
	while(n)
	{
		freq[n%10]++;
		n /= 10;
	}
	
	for(int i=0; i<10; i++)
	if(freq[i] != 0)
	cout << i << " ---> " << freq[i] << endl;
	


 return 0;
}

