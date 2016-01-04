#include<bits/stdc++.h>

using namespace std;

const int kMaxN = 100005;

int B, S, l, r;
int R[kMaxN],L[kMaxN];

int main() {
  while (scanf("%d%d",&S,&B) == 2) {
    if (B == 0 && S == 0) break;
    for(int i=0; i<S; ++i) 
      L[i] = i-1;
    for(int i=S-1; i>=0; --i) {
      R[i] = i+1;
    }
    for(int i=0; i<B; ++i) {
      scanf("%d%d",&l,&r);
      --l;--r;
      L[R[r]] = L[l];
      R[L[l]] = R[r];
      if (L[l] == -1)cout<<"* ";
      else cout<<L[l]+1<<" ";
      if (R[r] >= S)cout<<"*"<<"\n";
      else cout<<R[r]+1<<"\n";
      
    }
    puts("-");
    
  }
}
