#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 5;

char a[N], b[N];

string get(int n) {
  string str;
  for (int i = 0; i < n; i++) str += '0';
  return str;
}

int main() {
  scanf("%s %s", a, b);
  int n = strlen(a);
  sort(a, a + n);
  sort(b, b + n);
  reverse(b, b + n);
  int take_a = (n % 2? n / 2 + 1 : n / 2);
  int take_b = (n % 2? n / 2 : n / 2);
  vector<char> A, B;
  for (int i = 0; i < take_a; i++) A.push_back(a[i]);
  for (int i = 0; i < take_b; i++) B.push_back(b[i]);
  int al = 0, ar = (int) A.size() - 1, bl = 0, br = (int) B.size() - 1;
  int l = 0, r = n - 1;
  string ans = get(n);
  for (int i = 0; i < n; i++) {
    if (i % 2 == 0) {
      if (bl > br) {
        ans[l++] = A[al++];
        continue;
      }
      if (A[al] < B[bl]) {
        ans[l++] = A[al++];
      } else {
        ans[r--] = A[ar--];
      }
    } else {
      if (B[bl] > A[al]) {
        ans[l++] = B[bl++];
      } else {
        ans[r--] = B[br--];
      }
    }
  }
  cout << ans << endl;
  return 0;
}
