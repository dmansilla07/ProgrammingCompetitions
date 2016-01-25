#include<bits/stdc++.h>

using namespace std;

const int kMaxN = 100305;

int parent[kMaxN];
int cnt[kMaxN];

int find(int x) {
  if (x == parent[x]) return x;
  return parent[x] = find(parent[x]);
}

void Union(int x, int y) {
  parent[find(x)] = find(y);
}

void init(int N) {
  for(int i=0; i<=N; ++i)
    parent[i] = i, cnt[i] = 0;
}

int main() {
  int N, l, a, b;
  scanf("%d%d",&N,&l);
  init(N);
  for(int i=0; i<l; ++i) {
    scanf("%d%d",&a,&b);
    //cout<<a<<" "<<b<<endl;
    Union(a,b);
  }
  
  for(int i=0; i<N; ++i) {
    ++cnt[find(i)];
  }
  long long ans = 0LL, left = 0LL;
  for(int i=0; i<N; ++i) {
    left += cnt[i];
  }
  for(int i=0; i<N; ++i) {
    left-=cnt[i];
    ans += cnt[i]*left;
  }
  cout<<ans<<endl;
}
