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
  int n, k, p, q;
  while (scanf("%d%d%d%d",&n,&k,&p,&q) == 4) {
    printf("%.5f\n",(double)(comb(n,k)/comb(p,q)));
  }
}
