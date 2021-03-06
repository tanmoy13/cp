#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;

int last[N];
vector<int> p;

vector<int> factors(int n) {
  vector<int> ret;
  while (n > 1) {
    int p = last[n];
    ret.push_back(p);
    while (n % p == 0) n /= p;
  }
  return ret;
}

long long count(long long n) {
  long long ans = n;
  for (int mask = 1; mask < (1 << p.size()); mask++) {
    long long now = 1;
    for (int i = 0; i < p.size(); i++) if (mask & (1 << i)) now *= p[i];
    if (__builtin_popcount(mask) % 2) {
      ans -= n / now;
    } else {
      ans += n / now;
    }
  }
  return ans;
}

int main() {
  for (int i = 2; i < N; i++) {
    if (last[i] == 0) {
      for (long long j = i; j < N; j += i) {
        last[j] = i;
      }
    }
  }
  
  int t;
  scanf("%d", &t);
  while (t--) {
    int x, p, k;
    scanf("%d %d %d", &x, &p, &k);
    ::p = factors(p);
    long long l = x + 1, r = 1e9;
    long long rem = count(x);
    while (l < r) {
      long long mid = (l + r) >> 1;
      if (count(mid) - rem >= k) {
        r = mid;
      } else {
        l = mid + 1;
      }
    }
    printf("%lld\n", l);
  }
  
  return 0;
}
