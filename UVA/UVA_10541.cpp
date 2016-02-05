#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int kMaxN = 256;

string suma(const string &a, const string &b)  
{  
    int LA = a.size(), LB = b.size(), L = max(LA, LB), carry = 0; 
    string x = string(L, '0');  
    while(L--) 
    { 
        LA--; LB--; 
        if(LA >= 0) carry += a[LA] - '0';  
        if(LB >= 0) carry += b[LB] - '0';      
        if(carry < 10) x[L] = '0' + carry, carry = 0; 
        else x[L] = '0' + carry - 10, carry = 1; 
    } 
    if(carry) x = '1' + x;  
    return x; 
}

int N, K, B[kMaxN];
string memo[kMaxN][kMaxN];

string numBlocks(int posS, int posB) {
  if (posS >= N) {
    if (posB == K) return "1";
    else return "0";
  }
  if (posS > N) return "0";
  if (memo[posS][posB] != "-1") return memo[posS][posB];
  string ans = "0";
  ans = suma(ans,numBlocks(posS+1, posB));
  if (posB < K) if(posS+B[posB] <=N) ans = suma(ans,numBlocks(posS+B[posB]+1, posB+1));
  return memo[posS][posB] = ans;
}

int main() {
  int T;
  scanf("%d",&T);
  while (T--) {
    scanf("%d%d",&N,&K);
    for(int i=0; i<K; ++i)
      scanf("%d",&B[i]);
    for(int i=0; i<kMaxN; ++i)
      for(int j=0; j<kMaxN; ++j)
	memo[i][j] = "-1";
    cout<<numBlocks(0,0)<<"\n";
  }
}
