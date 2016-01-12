#include<bits/stdc++.h>

using namespace std;

const int kMaxN = 128;
const int kInf = (1<<28);

int dis[kMaxN][kMaxN];


void init(int N) {
  for(int i=0; i<N; ++i)
    for(int j=0; j<N; ++j) {
      if (i != j) dis[i][j] = kInf;
      else dis[i][j] = 0;
    }
}

int main() {
  int T, N, R, st, en;
  int caso = 0, a, b;
  scanf("%d",&T);
  while (T--) {
    scanf("%d%d",&N,&R);
    init(N);
    for(int i=0; i<R; ++i) {
      scanf("%d%d",&a,&b);
      dis[a][b] = dis[b][a] = 1;
    }
    for(int k=0; k<N; ++k)
      for(int i=0; i<N; ++i)
	for(int j=0; j<N; ++j)
	  dis[i][j] = min(dis[i][j],dis[i][k] + dis[k][j]);
    int ans = 0;
    scanf("%d%d",&st,&en);
    for(int i=0; i<N; ++i) {
      ans = max(ans, dis[st][i] + dis[i][en]);
    }
    printf("Case %d: %d\n",++caso,ans);
  }
}
