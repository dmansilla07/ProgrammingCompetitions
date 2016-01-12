#include<bits/stdc++.h>

using namespace std;

const int kMaxN = 128;

const int dx[] = {1,0,-1,0};
const int dy[] = {0,1,0,-1};

int N, M, A[kMaxN][kMaxN];
string s;
int memo[kMaxN][kMaxN][kMaxN];

bool valid(int x, int y) {
  return (x >= 0 && y >= 0 && x < N && y < M);
}

int longestRun(int x, int y, int height) {
  int ans = 0, nx, ny;
  if (memo[x][y][height] != -1)
    return memo[x][y][height];
  for(int i=0; i<4; ++i) {
    nx = x + dx[i], ny = y + dy[i];
    if (valid(nx,ny) && A[nx][ny] < height) {
      ans = max(ans, 1 + longestRun(nx,ny,A[nx][ny]));
    }
  }
  return memo[x][y][height] = ans;
}


void init() {
  for(int i=0; i<=N; ++i)
    for(int j=0; j<=M; ++j)
      for(int r=0; r<kMaxN; ++r)
	memo[i][j][r] = -1;
}

int main() {
  int T;
  scanf("%d",&T);
  while (T--) {
    cin>>s>>N>>M;
    for(int i=0; i<N; ++i) {
      for(int j=0; j<M; ++j) {
        cin>>A[i][j];
      }
    }
    init();
    int ans = 0;
    for(int i=0; i<N; ++i)
      for(int j=0; j<M; ++j)
	ans = max(ans,1+longestRun(i,j,A[i][j]));
    cout<<s<<": "<<ans<<"\n";
  }
}
