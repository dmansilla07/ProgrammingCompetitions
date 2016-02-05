#include<bits/stdc++.h>

using namespace std;

const int kMaxN = 100005;
const int kInf = (1<<30);

bool vis[kMaxN];

bool bellmanFord(vector<int>adj[], int V, int dis[], int energy[]) {
  for(int i=0; i<V; ++i)
    dis[i] = -kInf;
  dis[0] = 100;
  for(int i=0; i<V-1; ++i) {
    for(int j=0; j<V; ++j) {
      for(int r=0; r<adj[j].size(); ++r) {
        int v = adj[j][r], e = energy[v];
	if (vis[v] && dis[j] + e >= 0)dis[v] = max(dis[v], dis[j] + e);
      }
    }
  }
  for(int i=0; i<V; ++i) {
    for(int j=0; j<adj[i].size(); ++j) {
      int v = adj[i][j], e = energy[v];
      if (vis[v] && dis[i] + e > 0 && dis[v] < dis[i] + e) {
	return true;
      }
    }
  }
  return false;
}


void connected(int u, vector<int>adj[]) {
  if (vis[u])return;
  vis[u] = 1;
  for(int i=0; i<adj[u].size(); ++i) {
    int v = adj[u][i];
    connected(v,adj);
  }
    
}

int energy[kMaxN], dis[kMaxN];
vector<int>adj[kMaxN], radj[kMaxN];

int main() {
  int V, x, k;
  while (scanf("%d",&V) == 1) {
    if (V == -1) break;
    for(int i=0; i<V; ++i)
      radj[i].clear(), adj[i].clear();
    for(int i=0; i<V; ++i) {
      scanf("%d",&energy[i]);
      scanf("%d",&k);
      for(int j=0; j<k; ++j) {
        scanf("%d",&x);
	x--;
	adj[i].push_back(x);
	radj[x].push_back(i);
      }
    }
    memset(vis,0,sizeof(vis));
    connected(V-1, radj);
    bool cycle = bellmanFord(adj,V,dis,energy);
    if (cycle && vis[V-1]) {
      puts("winnable");
    }
    else {
      if (dis[V-1] > 0) puts("winnable");
      else puts("hopeless");
    }
  }
}
