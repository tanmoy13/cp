#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

vector<int> edge[N];
vector<int> leaf;

// 1 error, 0 oke
bool dfs(int now, int bef) {
  //printf("%d %d\n", now, bef);
  int child = 0;
  for (auto it : edge[now]) {
    if (it == bef) continue;
    child++;
    if (dfs(it, now)) return 1;
  }
  if (child > 1) return 1;
  if (child == 0) {
    leaf.push_back(now);
  } 
  return 0;
}

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i < n; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    edge[u].push_back(v);
    edge[v].push_back(u);
  }
  int root = -1, best = -1;
  for (int i = 1; i <= n; i++) {
    if ((int) edge[i].size() > best) {
      best = edge[i].size();
      root = i;
    }
  }
  //printf("root %d\n", root);
  bool ret = 0;
  for (auto it : edge[root]) {
    bool err = dfs(it, root);
    if (err) {
      ret = 1;
    }
  }
  if (ret) {
    puts("No");
    return 0;
  }
  puts("Yes");
  printf("%d\n", leaf.size());
  for (auto it : leaf) {
    printf("%d %d\n", root, it);
  }

  return 0;
}
