#include<bits/stdc++.h>

using namespace std;

const int kMaxN = 128;

int dx[] = {1,1,-1,-1};
int dy[] = {-1,1,-1,1};

int R,C,M,N,W;
char A[kMaxN][kMaxN];
bool vis[kMaxN][kMaxN];

bool valid(int x, int y) {
  return (x >= 0 && y >= 0 && x < R && y < C && A[x][y] != '*');
}

void dfs(int x, int y) {
  int nx, ny, mltx, mlty;
  set<pair<int,int> >k;
  vis[x][y] = true;
  for(int i=0; i<8; ++i) {
    if (i<4) mltx = N, mlty = M;
    else mltx = M, mlty = N;
    nx = x + dx[i%4]*mltx, ny = y +dy[i%4]*mlty;
    if (valid(nx,ny) == true ) {
      if (vis[nx][ny] == false)dfs(nx,ny);
      k.insert(make_pair(nx,ny));
    }
  }
  
  if ((k.size())%2 == 0) {
    A[x][y] = '+';
  } else {
    A[x][y] = '-';
  }
}

int main() {
  int a,b,T;
  scanf("%d",&T);
  int caso = 0;
  while (T--) {
    scanf("%d%d%d%d",&R,&C,&M,&N);
    scanf("%d",&W);
    memset(A,'.',sizeof(A));
    for(int i=0; i<W; ++i) {
      scanf("%d%d",&a,&b);
      A[a][b] = '*';
    }
    memset(vis,0,sizeof(vis));
    dfs(0,0);
    int cte = 0, cto = 0;
    for(int i=0; i<R; ++i) {
      for(int j=0; j<C; ++j) {
        if (A[i][j] == '+') ++cte;
	else if (A[i][j] == '-') ++cto;
      }
    }
    printf("Case %d: %d %d\n",++caso,cte,cto);
  }
}
