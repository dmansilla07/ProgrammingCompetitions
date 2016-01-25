#include<bits/stdc++.h>

using namespace std;

const int kMaxN = 100005;
const int kMaxH = 25;

int P, Q;
int parent[kMaxN][kMaxH];
vector<int>adj[kMaxN];
set<int>nodes;

void init(int node) {
  int v;
  for(int i=0; i<adj[node].size(); ++i) {
    v = adj[node][i];
    parent[v][0] = node;
    init(v);
  }
}

void generateParents() {
  int node, par;
  for(int i=1; i<20; ++i) {
    for(node = 0; node <kMaxN; ++node) {
      
      par = parent[node][i-1];
      if (par != -1) {
        parent[node][i] = parent[par][i-1];
      }
    }
  }
}

int getKParent(int node, int K) {
  int par = node;
  while (K > 0) {
    int idx = __builtin_ctz(K&-K);
    K-= (K&-K);
    par = parent[par][idx];
    if (par == -1) {
      break;
    }
  }
  return par;
}

void add(int node, int par) {
  parent[node][0] = par;
  for(int i=1; i<20; ++i) {
    par = parent[node][i-1];
    if (par != -1) 
      parent[node][i] = parent[par][i-1]; 
  }
}

void deletenode(int node) {
  for(int i=0; i<kMaxH; ++i)
    parent[node][i] = -1;
}

int main() {
  int T, x, y, type, K, root;
  scanf("%d",&T);
  while (T--) {
    scanf("%d",&P);
    for(int i=0; i<kMaxN; ++i)
      adj[i].clear();
    nodes.clear();
    for(int i=0; i<P; ++i) {
      scanf("%d%d",&x, &y);
      x--;y--;
      nodes.insert(x);
      nodes.insert(y);
      if (y >= 0) adj[y].push_back(x);
      else root = x;
    }
    memset(parent, -1, sizeof(parent));
    init(root);
    generateParents();
    
    scanf("%d",&Q);
    for(int i=0; i<Q; ++i) {
      scanf("%d",&type);
      if (type == 0) {
        scanf("%d%d",&y,&x);
	x--;y--;
	add(x,y);
      } else {
        if (type == 1) {
	  scanf("%d",&x);
          x--;
	  deletenode(x);
	} else {
          scanf("%d%d",&x,&K);
	  x--;
	  printf("%d\n",getKParent(x,K)+1);
	}
      }
    }
  }
} 
