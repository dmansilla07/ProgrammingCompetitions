#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int kMaxN = 300005;
const int kMaxVal = 500000;

int tree[kMaxVal+5];
int ans[kMaxN];
pair<pair<int,int>, int> rating[kMaxN];

void update(int idx, int val) {
  while (idx <= kMaxVal) {
    tree[idx] += val;
    idx += (idx  & -idx);
  }
}

int read(int idx) {
  int ret = 0;
  while (idx > 0) {
    ret += tree[idx];
    idx -= (idx & -idx);
  }
  return ret;
}

int main() {
  int N, a, b;
  scanf("%d",&N);
  for(int i=0; i<N; ++i) {
    scanf("%d%d",&a,&b);
    rating[i] = make_pair(make_pair(a,b),i);
  }
  int act = 0;
  pair<int,int> cur;
  sort(rating, rating + N);
  for(int i=0; i<N; ++i) {
    if (i == 0) {
      cur = rating[i].first;
      act = 1;
    }
    else {
      if (cur == rating[i].first) {
	++act;
	
      } else {
	act = 1;
	cur = rating[i].first;
      }
    }
    ans[rating[i].second] = read(rating[i].first.second) - (act-1);
    update(rating[i].first.second, 1);
  }
  for(int i=0; i<N; ++i)
    printf("%d\n",ans[i]);
}
