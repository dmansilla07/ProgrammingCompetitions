#include<bits/stdc++.h>

using namespace std;

const int kMaxN = 50;

string s;

int cnt[kMaxN];

char letterIdx(char c) {
  return c - 'A';
}

void travTree(int l, int r, char par) {
  bool found = false;
  char act;
  int last_i;
  for(int i=l+1; i<r; ++i) {
    if (found == false) {
      last_i = i;
      found = true;
      act = s[i];
    } else {
      if (act == s[i]) {
        found = false;
	cnt[letterIdx(par)]++;
	cnt[letterIdx(act)]++;
	travTree(last_i,i,act);
      }
    }
  }
}

int main() {
  int T;
  int caso = 0;
  scanf("%d",&T);
  while (T--) {
    cin>>s;
    memset(cnt,0,sizeof(cnt));
    int n = s.size();
    travTree(0, n-1, s[0]);
    printf("Case %d\n",++caso);
    for(char c = 'A'; c <= 'Z'; ++c) {
      if (cnt[letterIdx(c)] > 0)
	cout<<c<<" = "<<cnt[letterIdx(c)]<<"\n";
    }
  }
}
