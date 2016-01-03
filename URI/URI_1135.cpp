#include<bits/stdc++.h>
 
#define MAXN 100500
 
using namespace std;
 
int N,a,b;
vector<pair<int,int> >adj[MAXN];
int tin[5*MAXN],tout[5*MAXN];
int P[MAXN][50];
 
bool upper(int u,int v){
    return tin[u]<=tin[v]&&tout[u]>=tout[v];
}
 
int timer=0,l;
bool vis[MAXN];
 
void dfs(int u,int p){
    if(vis[u])return;
    vis[u]=1;
    tin[u]=timer++;
    P[u][0]=p;
    for(int i=1;i<=l;i++)P[u][i]=P[P[u][i-1]][i-1];
    for(int i=0;i<adj[u].size();i++){
        int to=adj[u][i].first;
        if(to!=p)dfs(to,u);
    }
    tout[u]=timer++;
}
 
int LCA(int u,int v){
    if(upper(u,v))return u;
    if(upper(v,u))return v;
    for(int i=l;i>=0;i--){
        if(!upper(P[u][i],v))u=P[u][i];
    }
    return P[u][0];
}
 
long long dis[MAXN];
 
void f(int u,int p,int arista){
    if(dis[u]!=-1LL&&u!=0)return;
    dis[u]=dis[p]+1LL*arista;
    for(int i=0;i<adj[u].size();i++){
        int to=adj[u][i].first;
        if(to!=p){
            f(to,u,adj[u][i].second);
        }
    }
}
 
vector<long long>res;
int Q;
 
int main(){
    while(scanf("%d",&N)==1&&N!=0){
        memset(vis,0,sizeof(vis));
        memset(dis,-1,sizeof(dis));
        res.clear();
        for(int i=0;i<N+5;i++)adj[i].clear();
        timer=0;
        for(int i=1;i<N;i++){
            scanf("%d%d",&a,&b);
            adj[i].push_back(make_pair(a,b));
            adj[a].push_back(make_pair(i,b));
        }
        while((1<<l)<=N)l++;
        dfs(0,0);
        dis[0]=0;
        f(0,0,0);
        res.clear();
        scanf("%d",&Q);
        for(int i=0;i<Q;i++){
            scanf("%d%d",&a,&b);
            res.push_back(1LL*dis[a]+dis[b]-2LL*dis[LCA(a,b)]);
        }
        for(int i=0;i<res.size();i++)
            printf("%lld%s",res[i],i==int(res.size()-1)?"\n":" ");
    }
 
}
