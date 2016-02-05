#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int kMaxN = 128;

ll memo[kMaxN][kMaxN];

ll comb(int n, int k) {
  if (n == k || k == 0) return 1LL;
  if (memo[n][k] != -1LL) return memo[n][k];
  return memo[n][k] = comb(n-1,k-1) + comb(n-1,k);
}

int main() {
  int N, M;
  memset(memo, -1, sizeof(memo));
  while (scanf("%d%d",&N,&M) == 2) {
    if (N == 0 && M == 0) break;
    printf("%d things taken %d at a time is %lld exactly.\n",N,M,comb(N,M));
  }
}
