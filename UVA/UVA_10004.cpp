#include<bits/stdc++.h>

using namespace std;

const int kMaxN = 256;

int n, m;
vector<int>adj[kMaxN];
int color[kMaxN];

bool isBicolorable() {
  queue<int>Q;
  Q.push(0);
  memset(color,-1,sizeof(color));
  color[0] = 0;
  while (!Q.empty()) {
    int v,q = Q.front();
    Q.pop();
    for(int i=0; i<adj[q].size(); ++i) {
      v = adj[q][i];
      if (color[v] == -1) {
        color[v] = (1-color[q]);
	Q.push(v);
      } else {
	if (color[v] == color[q])return false;
      }
    }
  }
  return true;
}

int a, b;

int main() {
  while (scanf("%d",&n) == 1) {
    if (n == 0) break;
    for(int i=0; i<n; ++i) {
      adj[i].clear();
    }
    scanf("%d",&m);
    for(int i=0; i<m; ++i) {
      scanf("%d%d",&a,&b);
      adj[a].push_back(b);
      adj[b].push_back(a);
    }
    if (isBicolorable() == true) {
      puts("BICOLORABLE.");
    } else {
      puts("NOT BICOLORABLE.");
    }
  }
}
