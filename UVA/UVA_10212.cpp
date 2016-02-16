#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int kMaxN = 20;

int a[kMaxN];

ll mod_pow(ll base, int exp, ll mod) {
  ll ret = 1LL;
  while (exp > 0) {
    if (exp%2 == 1)
      ret = (base*ret)%mod;
    base = (base*base)%mod;
    exp /= 2;
  }
  return ret;
}


int main() {
  int N, M;
  while (scanf("%d%d",&N,&M) == 2) {
    int exp2 = 0, exp5 = 0, x, ans = 1LL;
    for(int i=(N-M+1); i<=N; ++i) {
      x = i;
      while (x%2 == 0) {
	x /= 2;
	++exp2;
      }
      while (x%5 == 0) {
	x /= 5;
	++exp5;
      }
      ans = (ans*x)%10;
    }
    ans = (ans*mod_pow(2,exp2-min(exp2,exp5),10))%10;
    ans = (ans*mod_pow(5,exp5-min(exp2,exp5),10))%10;
    printf("%d\n",ans);
  }
}
