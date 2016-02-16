#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int kMaxN = 1000005;

int p[kMaxN + 25];
int maxi[kMaxN+25];

ll pow_mod(ll base, int exp, ll mod) {
  ll ret = 1LL;
  while (exp > 0) {
    if (exp%2 == 1) ret = (ret*base)%mod;
    base = (base*base)%mod;
    exp /= 2;
  }
  return ret;
}

void sieve() {
  for(int i=2; i*i <= kMaxN; ++i) {
    if (p[i] == 0) {
      for(int j=i*i; j<=kMaxN; j+=i) {
	p[j] = i;
      }
    }
  }
}

void process(int n) {
  if (n == 1) return;
  vector<int>facts;
  int ax = n;
  while (p[n] > 0) {
    facts.push_back(p[n]);
    n/= p[n];
  }
  if (n > 1)
    facts.push_back(n);
  sort(facts.begin(), facts.end());
  int act = facts[0], ct = 1;
  for(int i=1; i<=facts.size(); ++i) {
    if (i < facts.size() && facts[i] == facts[i-1]) {
      ct ++;
    } else {
      maxi[act] = max(maxi[act], ct);
      ct = 1;
      act = facts[i];
    }
  }
}

ll ans(vector<int>&primes) {
  int x = maxi[5], quita;
  ll ret = 1LL;
  for(int i=0; i<primes.size(); ++i) {
    if (primes[i] == 2 || primes[i] == 5)
      quita = x;
    else
      quita = 0;
    ret = (ret*pow_mod(primes[i], maxi[primes[i]] - quita, 10))%10;
  }
  return ret;
}

int main() {
  int N, k = 0;
  sieve();
  memset(maxi,0,sizeof(maxi));
  vector<int> primes;
  vector<pair<int,int> >Cases, Answers;
  while (scanf("%d",&N) == 1) {
      if (N == 0) break;
      Cases.push_back(make_pair(N,k++));
  }
  
  sort(Cases.begin(), Cases.end());
  
  int pt = 0, cur_ans = 0, ansi;
  for(int i=1; i<=kMaxN && pt < k; ++i) {
    if (i > 1 && p[i] == 0) {
      primes.push_back(i);
    }
    process(i);
    if(Cases[pt].first == i)ansi = ans(primes);
    while(Cases[pt].first == i) {
      Answers.push_back(make_pair(Cases[pt].second, ansi));
      ++pt;
    }
  }
  sort(Answers.begin(), Answers.end());
  for(int i=0; i<Answers.size(); ++i) {
    printf("%d\n",Answers[i].second);
  }
}
 
