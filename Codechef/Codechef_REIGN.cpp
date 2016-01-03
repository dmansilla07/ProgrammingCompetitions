    #include<bits/stdc++.h>
     
    using namespace std;
     
    typedef long long ll;
     
    const int kMaxN = 100005;
    const ll kInf = (1LL<<59);
     
    int T, N, K;
    ll A[kMaxN], dpLeft[kMaxN], dpRight[kMaxN][2];
    bool visLeft[kMaxN], visRight[kMaxN][2];
     
    ll bestLeft(int pos) {
      if (pos < 0) return 0;
      if (visLeft[pos] == true)
        return dpLeft[pos];
      visLeft[pos] = true;
      ll ans = A[pos];
      ans = max(ans, bestLeft(pos-1) + A[pos]);
      return dpLeft[pos] = ans;
    }
     
    ll bestRight(int pos, bool emp) {
    	if (pos == N){
    	  if(emp)return 0LL;
    	  else return -kInf;
    	}
    	if (visRight[pos][emp] == true)
    		return dpRight[pos][emp];
    	visRight[pos][emp] = true;
    	ll ans = -kInf;
    	if (emp == false) ans = max(ans,bestRight(pos+1,emp));
    	else ans = max(ans, bestRight(N,1));
    	ans = max(ans, bestRight(pos+1,1) + A[pos]);
    	return dpRight[pos][emp] = ans;
    }
     
    int main() {
    	int T;
    	scanf("%d",&T);
    	while (T--) {
    		scanf("%d%d",&N,&K);
    		ll ans = -kInf;
    		memset(visRight, 0, sizeof(visRight));
    		memset(visLeft, 0, sizeof(visLeft));
    		for(int i=0; i<N; ++i)
    			cin>>A[i];
    		for(int i=0; i<N-K-1; ++i) {
          ans = max(ans, bestLeft(i) + bestRight(i+K+1,0) );
          //cout<<bestLeft(i)<<" "<<bestRight(i+K+1,0)<<endl;
    		}
    		cout<<ans<<"\n";
    	}
    } 
