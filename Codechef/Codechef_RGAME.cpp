#include<bits/stdc++.h>

using namespace std;

const long long kMod = 1000000007;

int main() {
  int T, N;
  scanf("%d",&T);
  while (T--) {
    scanf("%d",&N);
    long long pot = 2LL, ans = 0;
    long long x, mult = 0;
    cin>>mult;
    mult = (mult*2LL)%kMod;
    for(int i=0; i<N; ++i) {
      cin>>x;
      ans = (ans*2LL)%kMod;
      ans = (ans + (x*mult))%kMod;
      mult = (mult + x*pot)%kMod;
      pot = (pot*2LL)%kMod;
    }
    cout<<ans<<"\n";
  }
}
