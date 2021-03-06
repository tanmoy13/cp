#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

int a[N];

int main() {
  int n;
  scanf("%d", &n);
  for(int i = 0; i < n; i++) {
    scanf("%d", a + i);
    a[i] += i;
  }
  sort(a, a + n);
  for(int i = 0; i < n; i++) {
    a[i] -= i;
    if(i && a[i - 1] > a[i]) {
      puts(":(");
      return 0;
    }
  }
  for(int i = 0; i < n; i++) {
    printf("%d ", a[i]);
  }
  return 0;
}
