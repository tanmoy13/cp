#include <bits/stdc++.h>

using namespace std;

int p[5];

int main() {
  for (int i = 0; i < 3; i++) scanf("%d", p + i);
  sort(p, p + 3);
  int a = p[0], b = p[1], c = p[2];
  if (a == 2 && b == 4 && c == 4) {
    puts("YES");
    return 0;
  }
  if (a > 3) {
    puts("NO");
    return 0;
  }
  int ada = 1 + (a == b) + (a == c);
  if (ada >= a) {
    puts("YES");
  } else {
    puts("NO");
  }
  return 0;
}
