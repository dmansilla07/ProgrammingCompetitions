#include<bits/stdc++.h>

using namespace std;

const int kMaxN = 64;

vector<vector<int> >ways[kMaxN];
vector<int>temp;

void back(int target, int last, int sum) {
  if (target < sum) return;
  if (target == sum) {
    ways[target].push_back(temp);
    return;
  }
  temp.push_back(last);
  if (last != target)back(target, last+1, sum + last);
  temp.pop_back();
  if (sum + last < target) back(target, last+1, sum);
}

int memo[kMaxN];

int grundy(int num) {
  if (ways[num].size() == 0)return 0;
  if (memo[num] != -1)
    return memo[num];
  set<int>s;
  
  for(int i=0; i<ways[num].size(); ++i) {
    int loc_ans = 0;
    for(int j=0; j<ways[num][i].size(); ++j) {
      loc_ans = (loc_ans xor grundy(ways[num][i][j]));
    }
    s.insert(loc_ans);
  }
  int mini = 0;
  while (s.find(mini) != s.end()) ++mini;
  return memo[num] = mini;
  
}

int N, x;

int main() {
  int T;
  scanf("%d",&T);
  memset(memo, -1, sizeof(memo));
  for(int i=2; i<=50; ++i) {
    back(i, 1, 0);
  }
  while (T--) {
    scanf("%d",&N);
    int ans = 0;
    for(int i=0; i<N; ++i) {
      scanf("%d",&x);
      ans = (ans xor grundy(x));
    }
    if (ans == 0)puts("BOB");
    else puts("ALICE");
  }
}
