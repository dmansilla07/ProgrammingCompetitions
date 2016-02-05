#include<bits/stdc++.h>

using namespace std;

const int kMaxN = 1024;
const int kInf = (1<<30);

bool bellmanFord(vector<pair<int,int> >adj[], int V, int dis[]) {
  for(int i=0; i<V; ++i)
    dis[i] = kInf;
  dis[0] = 0;
  for(int i=0; i<V-1; ++i) {
    for(int j=0; j<V; ++j) {
      for(int r=0; r<adj[j].size(); ++r) {
        int v = adj[j][r].first, e = adj[j][r].second;
	dis[v] = min(dis[v], dis[j] + e);
      }
    }
  }
  for(int i=0; i<V; ++i) {
    for(int j=0; j<adj[i].size(); ++j) {
      int v = adj[i][j].first , e = adj[i][j].second;
      if (dis[v] > dis[i] + e) {
	return true;
      }
    }
  }
  return false;
}

vector<pair<int,int> >adj[kMaxN];
int dis[kMaxN];

int main() {
  int T, n, m, x, y, z;
  scanf("%d",&T);
  while (T--) {
    scanf("%d%d",&n, &m);
    for(int i=0; i<n; ++i)
      adj[i].clear();
    for(int i=0; i<m; ++i) {
      scanf("%d%d%d",&x,&y,&z);
      adj[x].push_back(make_pair(y,z));
    }
    bool ans = bellmanFord(adj,n,dis);
    if (ans) puts("possible");
    else puts("not possible");
  }
}
