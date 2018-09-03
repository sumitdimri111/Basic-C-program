#include <iostream>
#include <algorithm>
using namespace std;
#define mod 1000000007
typedef long long int ll;

int max(int f[], int n)
{
	int max=0;
	for(int i=0; i<n; i++)
		if(f[i] > max)
			max = f[i];
	return max;
}

void factorial(ll fact[], int n)
{        
    fact[0] = 1;
    for(int i=1; i<=n; i++)
        fact[i] = (i*fact[i-1]) % mod;
}

int main()
{
    int n, t=5;
    ll fact[100000]={0};
//    cin >> t;
    int f[t]={1,2,3,4,5};
//    for(int i=0; i<t; i++)
//        cin >> f[i];
    n = max(f, t);
    cout << n << endl;
    factorial(fact, n);
    for(int i=0; i<t; i++)
        cout << f[i] << " " << fact[f[i]] << endl;
    return 0;
}

