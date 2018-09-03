#include<iostream>
using namespace std;

int HCF(int a, int b) {
	int t;
	while(b) {
		t = b;
		b = a%b;
		a = t;
	}
	return a;
}

int main() {
	int a, b, hcf, lcm;
	a=15, b=10;

	hcf = HCF(a, b);

	lcm = (a*b)/hcf;
	cout << "Hcf : " << hcf << endl;
	cout << "Lcm : " << lcm << endl;
	return 0;
}

