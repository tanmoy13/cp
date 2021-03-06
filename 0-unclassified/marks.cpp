#include <bits/stdc++.h>

typedef long long LL;
typedef double DB;

#define sf scanf
#define pf printf
#define mp make_pair
#define nl printf("\n")

#define FOR(i,a,b) for(i = a; i <= b; ++i)
#define FORD(i,a,b) for(i = a; i >= b; --i)
#define FORS(i,n) for(i = 0; i < n; ++i)
#define FORM(i,n) for(i = n - 1; i >= 0; --i)
#define reset(i,n) memset(i, n, sizeof(i))

using namespace std;

const LL mod = 1e9 + 7;
const LL INF = 4e18;
const int inf = 2e9;
const double eps = 1e-13;

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a/ gcd(a, b)*b; }

char s[105][105];
bool sip[105];

int main(void)
{
	int n, m, i, j;
	sf("%d %d", &n, &m);
	FORS(i, n) sf("%s", s[i]);
	FORS(j, m) {
		char best = '0';
		FORS(i, n) best = max(best, s[i][j]);
		FORS(i, n) if(s[i][j] == best) sip[i] = 1;
	}
	int ans = 0;
	FORS(i, n) ans += sip[i];
	cout << ans << endl;
	return 0;
}
