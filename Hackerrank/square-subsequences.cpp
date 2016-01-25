#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int kMaxN = 205;
const int kMod = 1000000007;
const int kMaxAlph = 30;

string s;
int memo[kMaxN][kMaxN];
int lastx[kMaxN][kMaxAlph], lasty[kMaxN][kMaxAlph];
int n1, n2;

inline int charToInt(char c) {
  return c-'A';
}

int numSquareSubseq() {
  memset(memo,0,sizeof(memo));
  for(int i=0; i<n1; ++i) {
    if (s[n1] == s[i]) {
      memo[i][n1] = 1;
    }
    if (i > 0)
      memo[i][n1] = (memo[i][n1] + memo[i-1][n1])%kMod;
  }
  for(int i=n1+1; i<n2; ++i) {
    memo[0][i] = memo[0][i-1];
    for(int j=1; j<n1; ++j) {
      memo[j][i] = (1LL*memo[j-1][i] + 1LL*memo[j][i-1] + 1LL*kMod - 1LL*memo[j-1][i-1])%kMod;
      if (s[i] == s[j])
	memo[j][i] = (1LL*memo[j][i] + 1LL*memo[j-1][i-1])%kMod;
    }
  }
  return memo[n1-1][n2-1];
}

int main() {
  int T;
  scanf("%d",&T);
  while (T--) {
    cin>>s;
    n2 = s.size();
    int ans = 0;
    for(n1 = 1; n1 < n2; ++n1) {
      memset(memo,-1,sizeof(memo));
      
      ans = (1LL*ans + 1LL*numSquareSubseq())%kMod;
     
    }
    printf("%d\n",ans);
  }
}
