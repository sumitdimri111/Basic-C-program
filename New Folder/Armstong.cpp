#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;

int main()
{
	for(int n=1; n<=1000; n++)
	{
		int m=0, c=0, t=n; 
		while(t)
			c++, t /= 10;
		t=n;
		while(t)
		{
			int d=t%10;
			m += pow(d,c);
			t /=  10;
		}
		if(m==n)
			cout << setw(8) << n <<  " -> Armstrong!" << endl;
	}
	

 return 0;
}

