#include<iostream>
using namespace std;

int HCF(int a, int b)
{
	if(a == 0 || b == 0)
		return 0;
	if(a == b)
		return a;
	if(a > b)
		return HCF(a-b, b);
	return HCF(a, b-a);
}

int main()
{
	int a, b, hcf, lcm;
	a=15, b=0;
	
	hcf = HCF(a, b);	
	
//	lcm = (a*b)/hcf;
	
	cout << "Hcf : " << hcf << endl;
	cout << "Lcm : " << lcm << endl;

 return 0;
}

