#include<bits/stdc++.h>

using namespace std;

const int kMaxN = 15*100005;
const int kAlphSz = 2;
const int sz_int = 16;
const int kMaxNodes = kMaxN * kAlphSz;

int nextt[kMaxN][kAlphSz], num_nodes;
vector<int>indices[kMaxNodes];

void init() {
  num_nodes = 1;
}

void clear_tree(int node) {
  if (nextt[node][0] != 0) clear_tree(nextt[node][0]);
  if (nextt[node][1] != 0) clear_tree(nextt[node][1]);
  nextt[node][0] = 0;
  nextt[node][1] = 0;
}

void add(int num, int idx) {
  int p = 0;
  for(int i=15; i>=0; --i) {
    int bit = ((num>>i)&1);
    if (nextt[p][bit] == 0) nextt[p][bit] = num_nodes++;
    p = nextt[p][bit];
    indices[p].push_back(idx);
  }
}

bool isIn(int node, int l, int r) {
  vector<int>::iterator it = lower_bound(indices[node].begin(), indices[node].end(), l);
  if (it == indices[node].end())return false;
  return (*it <= r);
}

int best(int pos, int node, int num, int l, int r) {
  if(pos < 0)return 0;
  int bit = ((num>>pos)&1);
  
  if (nextt[node][!bit] > 0) {
    if (isIn(nextt[node][!bit],l,r)) {
      return (1<<pos) + best(pos-1,nextt[node][!bit],num,l,r);
    } 
  } 
  return best(pos-1,nextt[node][bit], num, l, r);
}

int N, Q;

int main() {
  int T, x, a, l, r;
  scanf("%d",&T);
  while (T--) {
    scanf("%d%d",&N,&Q);
    init();
    for(int i=0; i<N; ++i) {
      scanf("%d",&x);
      add(x, i+1);
    }
    for(int i=0; i<Q; ++i) {
      scanf("%d%d%d",&a,&l,&r);
      l;r;
      printf("%d\n", best(15,0,a,l,r));
      
    }
    for(int i=0; i<num_nodes; ++i) {
      indices[i].clear();
    }
    clear_tree(0);
  }
}
