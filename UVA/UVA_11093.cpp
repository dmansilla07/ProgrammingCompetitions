#include<bits/stdc++.h>

using namespace std;

const int kMaxN = 100005;

int N;
int q[2*kMaxN], p[2*kMaxN];

int main() {
  int T;
  scanf("%d",&T);
  int caso = 0;
  while (T--) {
    scanf("%d",&N);
    for(int i=0; i<N; ++i) { 
      scanf("%d",&p[i]);
      p[i+N] = p[i];
    }
    for(int i=0; i<N; ++i) {
      scanf("%d",&q[i]);
      q[i+N] = q[i];
    }
    int ans = -1;
    int l = 0, r = 0;
    long long act = 0;
    while (l < N) {
      if (r == l + N) {
         ans = l%N;
	 break;
      }
      if (act + p[r] >= q[r]) {
        act = act + p[r] - q[r];
	++r;
      } else {
	++r;
	act = 0;
        l = r;
	continue;
      }
    }
    if (ans == -1) {
      printf("Case %d: Not possible\n",++caso);
    } else {
      printf("Case %d: Possible from station %d\n",++caso,ans+1);
    }
  }
}
