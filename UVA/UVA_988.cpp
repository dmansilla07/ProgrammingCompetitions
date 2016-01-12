#include<bits/stdc++.h>

using namespace std;

const int kMaxN = 100005;

int N, k, x;
vector<int>adj[kMaxN];
int memo[kMaxN];

int numEvents(int event) {
  if (adj[event].size() == 0)return 1;
  if (memo[event] != -1) return memo[event];
  int ans = 0;
  for(int i=0; i<adj[event].size(); ++i) {
    ans += numEvents(adj[event][i]);
  }
  return memo[event] = ans;
}

int main() {
  bool first = false;
  while (scanf("%d",&N) == 1) {
    if (first == true) puts("");
    first = true;
    for(int i=0; i<N; ++i) {
      scanf("%d",&k);
      adj[i].clear();
      memo[i] = -1;
      
      for(int j=0; j<k; ++j) {
        scanf("%d",&x);
	adj[i].push_back(x);
      }
    }
    cout<<numEvents(0)<<"\n";
    
  }
}
