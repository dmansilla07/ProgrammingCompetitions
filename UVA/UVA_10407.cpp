#include<bits/stdc++.h>

using namespace std;

const int kMaxN = 1024;

int a[kMaxN];

int main() {
  while(scanf("%d",&a[0]) == 1) {
    if (a[0] == 0) break;
    int x, n = 1, mini = INT_MAX;
    while (scanf("%d",&x) == 1) {
      if ( x == 0) break;
      a[n++] = x;
    }
    for(int i=0; i<n; ++i)
      mini = min(mini, a[i]);
    x = -mini;
    int ans = 0;
    for(int i=0; i<n; ++i) {
      a[i] += x;
      if (a[i] != 0) {
	ans = __gcd(ans,a[i]);
      }
    }
    cout<<ans<<"\n";
    
  }
}
