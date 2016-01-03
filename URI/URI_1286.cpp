#include<bits/stdc++.h>
 
using namespace std;
 
int N,P,dp[64][64];
pair<int,int>a[32];
 
int f(int pos,int pizza){
    if(pizza<0)return -9999999;
    if(pos==N){
        if(pizza>=0)return 0;
        else return -9999999;
    }
    if(dp[pos][pizza]!=-1)return dp[pos][pizza];
    return dp[pos][pizza]=max(f(pos+1,pizza),a[pos].first+f(pos+1,pizza-a[pos].second));
}
 
int x,y;
 
int main(){
    while(scanf("%d",&N)==1&&N!=0){
        scanf("%d",&P);
        memset(dp,-1,sizeof(dp));
        for(int i=0;i<N;i++){
            scanf("%d%d",&a[i].first,&a[i].second);
            //a[i]=make_pair(x,y);
        }
        printf("%d min.\n",f(0,P));
 
    }
}
