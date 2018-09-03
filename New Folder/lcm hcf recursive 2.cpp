#include<iostream>
using namespace std;

int HCF(int a, int b)
{
	if(b == 0)
		return a;
	return HCF(b, a%b);
}

int main()
{
	int a, b, hcf, lcm;
	a=15, b=20;
	
	hcf = HCF(a, b);	
	
	lcm = (a*b)/hcf;
	
	cout << "Hcf : " << hcf << endl;
	cout << "Lcm : " << lcm << endl;

 return 0;
}

