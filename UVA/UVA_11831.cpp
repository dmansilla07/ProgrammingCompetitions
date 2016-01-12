#include<bits/stdc++.h>

using namespace std;

const int kMaxN = 128;

int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};

char A[kMaxN][kMaxN];
bool vis[kMaxN][kMaxN];
string s;

int isLetter(char c) {
  if (c == 'S') return 0;
  if (c == 'L') return 1;
  if (c == 'N') return 2;
  if (c == 'O') return 3;
  return -1;
}

bool valid(int x, int y, int N, int M) {
  if (x >= 0 && y >= 0 && x < N && y < M) {
    return (A[x][y] != '#');
  }
  return false;
}

int main() {
  int N, M, S, stx, sty, ori;
  while (scanf("%d%d%d",&N,&M,&S) == 3) {
    if (N == 0 && M == 0 && S == 0)break;
    for(int i=0; i<N; ++i)
      for(int j=0; j<M; ++j) {
	cin>>A[i][j];
	int is_let = isLetter(A[i][j]);
	if (is_let != -1){
	  stx = i, sty = j;
	  ori = is_let;
	}
      }
    int ans = 0;
    cin>>s;
    memset(vis,0,sizeof(vis));
    for(int i=0; i<S; ++i) {
      if (s[i] == 'F') {
        int nx = stx + dx[ori], ny = sty + dy[ori];
	if (valid(nx,ny,N,M) == true) {
          stx = nx, sty = ny;
	  if (A[nx][ny] == '*') {
	    if (vis[nx][ny] == false) ++ans;
	    vis[nx][ny] = true;
	  }
	}
      } else {
	if (s[i] == 'D') ori = (ori + 3)%4;
	else ori = (ori+1)%4;
      }
    }
    cout<<ans<<"\n";
  }
}
