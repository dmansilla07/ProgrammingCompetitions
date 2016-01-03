#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <algorithm>
#include<sstream>
#include <string>
#include<numeric>
#include<stack>
#include<iomanip>
#include<climits>
#include<cassert>
#define FOR(i,x,y) for (int i = x; i < y; i++)
#define all(v) (v).begin(), (v).end()
#define oo (1<<30)
#define eps (1e-9)
#define MAXN 64
 
using namespace std;
 
int t,N,a[MAXN],b[MAXN],K,R;
int dp[MAXN][120];
 
int f(int pos,int cap){
    if(cap<0)return -oo;
    if(pos==N)return 0;
    if(dp[pos][cap]!=-1)return dp[pos][cap];
    return dp[pos][cap]=max(f(pos+1,cap),a[pos]+f(pos+1,cap-b[pos]));
}
 
int main ()
{
    scanf("%d",&t);
    while(t--){
        scanf("%d",&N);
        memset(dp,-1,sizeof(dp));
        FOR(i,0,N)
            scanf("%d%d",&a[i],&b[i]);
        scanf("%d%d",&K,&R);
        if(f(0,K)>=R)puts("Missao completada com sucesso");
        else puts("Falha na missao");
    }
    return 0;
}
