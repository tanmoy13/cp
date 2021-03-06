#include <bits/stdc++.h>

using namespace std;

#define LL long long
#define DB double
#define sf scanf
#define pf printf
#define nl printf("\n")
#define FOR(i,a,b) for(i = a; i <= b; ++i)
#define FORD(i,a,b) for(i = a; i >= b; --i)
#define FORS(i,n) for(i = 0; i < n; ++i)
#define FORM(i,n) for(i = n - 1; i >= 0; --i)
#define reset(i,n) memset(i, n, sizeof(i))
#define open freopen("input.txt","r",stdin); freopen("output.txt","w",stdout)
#define close fclose(stdin); fclose(stdout)
#define mp make_pair

const LL mod = 1e9 + 7;

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a*b / gcd(a, b); }

LL a, b, c, d;

int main(void)
{
	int i, n; sf("%d", &n);
	FOR(i,1,n) {
		int x; sf("%d", &x);
		if(i%2) {
			if(x < 0) a += x;
			else b += x;
		} else {
			if(x < 0) c += x;
			else d += x;
		}
	}
	cout << max(d - a, b - c) << endl;
	
	return 0;
}
