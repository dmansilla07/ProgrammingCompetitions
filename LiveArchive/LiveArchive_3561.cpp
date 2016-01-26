#include<bits/stdc++.h>
 
using namespace std;

const int kMaxI = 25;
const int kMaxN =4400;
const long long kInf = (1LL<<45);

map<int,int>city_number;
int NI, NP, T;
int pl[kMaxN], price[kMaxN];
vector<int>adj[kMaxN];
int memo[kMaxN];
vector<int>anss;
long long dis[kMaxN][kMaxI];
pair<int,int> parent[kMaxN][kMaxI];
int choice[kMaxN][kMaxI];
int kk;

void initDis() {
  for(int i=0; i<kMaxN; ++i)
    for(int j=0; j<15; ++j)
      dis[i][j] = kInf,
      choice[i][j] = -1,
      parent[i][j] = make_pair(-1,-1);
}

void dijkstra(long long &ans) {
  priority_queue<pair<int,pair<int,int> > >Q;
  Q.push(make_pair(0,make_pair(pl[0],0)));
  initDis();
  dis[city_number[pl[0]]][0] = 0;
  int city, pos;
  while (!Q.empty()) {
    pair<long long,pair<int,int> >q = Q.top();
    Q.pop();
    pair<int,int> nod = q.second;
    city = nod.first, pos = nod.second;
    for(int i=0; i<NI; ++i) {
      int pt = 0;
      if (adj[i][0] == city) {
     
	for(int j=1; j<adj[i].size(); ++j) {
          if (adj[i][j] == pl[pos + pt +1]) ++pt;
	  if (dis[city_number[adj[i][j]]][pos+pt] > dis[city_number[city]][pos] + price[i]) {
            
	    dis[city_number[adj[i][j]]][pos+pt] = dis[city_number[city]][pos] + 1LL*price[i];
	    Q.push(make_pair(-dis[city_number[adj[i][j]]][pos+pt],make_pair(adj[i][j],pos+pt)));
	    parent[city_number[adj[i][j]]][pos+pt] = make_pair(city_number[city],pos);
	    choice[city_number[adj[i][j]]][pos+pt] = i+1;
	  }
        }
      }
    }
  }
  ans = kInf;
  for(int i=0; i<kMaxN; ++i) {
    if (ans > dis[i][NP-1]) {
      ans = dis[i][NP-1];
      city = i, pos = NP-1;
    }
  }
  while (parent[city][pos].first != -1) {
    anss.push_back(choice[city][pos]);
    pair<int,int> par = parent[city][pos];
    city = par.first;
    pos = par.second;
  }
}
 
int k,x;

void addCity(int x) {
  if (city_number.find(x) == city_number.end()) {
    city_number[x] = kk++;
  }
}
 
int main() {
  int caso = 1;
  while (scanf("%d",&NI) == 1) {
    if (NI == 0) break;
    city_number.clear();
    kk = 0;
    for(int i=0; i<NI; ++i) {
      adj[i].clear();
      scanf("%d",&price[i]);
      scanf("%d",&k);
      for(int j=0; j<k; ++j) {
        scanf("%d",&x);
	addCity(x);
        adj[i].push_back(x);
      }
    }
    scanf("%d",&T);
    for(int i=0; i<T; ++i) {
      scanf("%d", &NP);
      anss.clear();
      for(int j=0; j<NP; ++j) {
        scanf("%d",&pl[j]);
	addCity(pl[j]);
      }
      long long ans;
      dijkstra(ans);
      memset(memo, -1, sizeof(memo));
      printf("Case %d, Trip %d: Cost = %lld\n",caso,i+1,ans);
      
      printf("  Tickets used:");
      for(int j=int(anss.size())-1; j >= 0; --j)
        printf(" %d",anss[j]);
      puts("");
    }
    ++caso;
  }
}
