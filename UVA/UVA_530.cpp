#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

ll comb(int n, int k) {
  if (k > n - k) k = n-k;
  ll ret = 1LL;
  for(int i=0; i<k; ++i)
    ret = ret*(n-i)/(1+i);
  return ret;
}

int main() {
  int n, k;
  while (scanf("%d%d",&n,&k) == 2) {
    if (n == 0 && k == 0) break;
    cout<<comb(n,k)<<"\n";
  }
}
