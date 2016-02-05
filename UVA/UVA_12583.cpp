#include<bits/stdc++.h>

using namespace std;

const int kMaxN = 50;

string s;
int cnt[kMaxN];

inline int let(char c){
  return c - 'A';
}

int main() {
  int T, n, k;
  scanf("%d",&T);
  int caso = 0;
  while (T--) {
    scanf("%d%d",&n,&k);
    cin>>s;
    memset(cnt, 0, sizeof(cnt));
    int ans = 0;
    for(int i=0; i<n; ++i) {
      int x = i - k;
      if (cnt[let(s[i])] > 0)++ans;
      cnt[let(s[i])]++;
      if (x >= 0)cnt[let(s[x])]--;
    }
    printf("Case %d: %d\n",++caso,ans);
  }
}
