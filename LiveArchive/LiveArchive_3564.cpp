#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int kMaxN = 100000;
const int kMaxD = 50;

int powmod(int base, int exp, int mod) {
  ll ret = 1LL;
  while (exp > 0) {
    if (exp%2 == 1) ret = (1LL*ret*base)%mod;
    base = (1LL*base*base)%mod;
    exp/=2;
  }
  return ret;
}

void gcdext( int &g , int &x , int &y , int a , int b ){
	if( b == 0 )
		g = a , x = 1 , y = 0;
	else gcdext( g , y , x , b , a%b ) , y = y - ( a/b )*x;
}

int getModInv(int num, int mod) {
  int g, x, y;
  gcdext(g,x,y,mod,num);
  if (y < 0)y+=mod;
  return y%mod;
}

int memo[kMaxD];
pair<int,int> adj[kMaxN];

bool menor(int m1, int s1, int n1, int t1, int m2, int s2, int n2, int t2) {
  if (m1 + n1 < m2 + n2) return true;
  if (m1 + n1 > m2 + n2) return false;
  if (s1 < s2) return true;
  if (s1 > s2) return false;
  if (m1 <= m2) {
    if (t1 < s1) return true;
    return false;
  } else {
    if (t1 > s1) return true;
    return false;
  }
  return false;
}

int numberSize(int num) {
  int ret = 0;
  while (num > 0){
    ret++;
    num/=10;
  }
  return ret;
}

int recoNum(int m, int s, int n, int t) {
  int ret = 0;
  for(int i=0; i<m; ++i)
    ret = ret*10 + s;
  for(int i=0; i<n; ++i)
    ret = ret*10 + t;
  return ret;
}

bool menorNumero(int m,int s, int n, int t, int num) {
  if (m + n < numberSize(num))return true;
  if (m + n > numberSize(num))return false;
  return recoNum(m,s,n,t) <= num;
}

int main() {
  int N;
  while (scanf("%d",&N) == 1) {
    if (N == 0) break;
    if (N == 1) {
      puts("1: 1 1 1 0");
      continue;
    }
    for(int i=0; i<N;++i)
      adj[i] = make_pair(-1,-1);
    int m, s, n, t;
    int am = -1, as, an, at;

    int acum = 1, acum2;
    for(int i=1; i<=N/2; ++i) {
      for(int j=1; j<=9; ++j) {
        int act = (acum*j)%N;
	if (adj[act].first == -1 || menor(i,j,0,0,adj[act].first,adj[act].second,0,0))adj[act] = (make_pair(i,j));
      }
      acum = (acum*10 + 1)%N;
    }
    acum = 1, acum2 = 10;
    for(n = 1; n <= kMaxD; ++n) {
      	for(t = 0; t <= 9; ++t) {
          int x = (acum*t)%N;
	  int to_find = (N - x)%N;
	  int tof = to_find;
	  
	  if (tof == 0) {
	    
	    if (acum2 != 0) 
	      to_find = ((1LL*acum2*N/(__gcd(acum2,N)))/acum2)%N;
            else
	      to_find = 0;
	       
	  } else {
	    if (to_find%(__gcd(acum2,N)) == 0) {
              to_find = getModInv(acum2,N);
	      
	      int tt = to_find;
              if (tof != 0) tt = (to_find*(tof/__gcd(acum2,N)));
              
	      to_find = tt%N;
	      
	    } else continue;
        }
	  int mult = N/__gcd(acum2,N);
	  bool fir = true;
	  bool sec = false;
          while (to_find >= 0 && to_find < N) {
	  m = adj[to_find].first, s = adj[to_find].second;
	  if (m != -1 && menorNumero(m,s,n,t,N) == false && t != s) {
	    if (am == -1 || menor(m,s,n,t,am,as,an,at)) {
	      am = m;
	      as = s;
	      an = n;
	      at = t;
	    }	      
	  }
	  if (fir) to_find -= mult;
          if (to_find < 0)fir =false, sec = true;
	  if (sec) to_find += mult;
	  }
      }
      acum = (acum*10 + 1)%N, acum2=(acum2*10)%N;
    }
    printf("%d: %d %d %d %d\n",N,am,as,an,at);
  }
}
