#include<bits/stdc++.h>

using namespace std;

int N, M, x;
vector<int>cd_jack, cd_jill;

int main() {
  while (scanf("%d%d",&N, &M) == 2) {
    if (N == 0 && M == 0)break;
    cd_jack.clear();
    cd_jill.clear();
    for(int i=0; i<N; ++i) {
      scanf("%d",&x);
      cd_jack.push_back(x);
    }
    for(int i=0; i<M; ++i) {
      scanf("%d",&x);
      cd_jill.push_back(x);
    }
    int l = 0 , r = 0;
    int ans = 0;
    while (l < cd_jack.size() && r < cd_jill.size()) {
      if (cd_jack[l] == cd_jill[r]) {
        ++ans;
	++l;
	++r;
      } else {
        if (cd_jack[l] < cd_jill[r]) {
          ++l;
	} else {
          ++r;
	}
      }
    }
    cout<<ans<<"\n";
  }
}
