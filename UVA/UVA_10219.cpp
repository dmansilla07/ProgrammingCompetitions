#include<bits/stdc++.h>

using namespace std;

typedef long double ld;

ld comb(int n, int k) {
  if (k > n-k) k = n-k;
  ld ret = 1.0;
  for(int i=0; i<k; ++i)
    ret = ret*(1.0*n-1.0*i)/(1.0+1.0*i);
  return ret;
    
}

int main() {
  int n, k;
  while (scanf("%d%d",&n,&k) == 2) {
    ld ans = comb(n,k);
    cout<<(int)log10(ans) + 1<<"\n";
  }
}
