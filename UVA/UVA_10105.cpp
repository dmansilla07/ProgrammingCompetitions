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

int n, k, coef[kMaxN];

int main() {
  memset(memo, -1LL, sizeof(memo));
  while (scanf("%d%d",&n, &k) == 2) {
    ll ans = 1;
    for(int i=0; i<k; ++i) {
      scanf("%d",&coef[i]);
    }
    int ax = n;
    for(int i=0; i<k; ++i) {
      if (ax < 0) {
	ax = 0; break;
      }
      ans = ans * (comb(ax, coef[i]));
      ax -= coef[i];
    }
    cout<<ans<<"\n";
  }
}
