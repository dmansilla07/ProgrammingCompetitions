#include<bits/stdc++.h>

using namespace std;

const int kMaxPrime = 100000;

vector<int>primes;

bool isPrime(int n) {
  for(int i=2; i*i<=n; ++i) {
    if (n%i == 0)
      return false;
  }
  return true;
}

void makePrimes() {
  for(int i=2; i<=kMaxPrime; ++i)
    if (isPrime(i) == true)
      primes.push_back(i);
}

set<int>facts;

void fact(int n) {
  for(int i=0; i<primes.size(); ++i) {
    while (n%primes[i] == 0) {
      n/=primes[i];
      facts.insert(primes[i]);
    }
  }
  if (n > 1)
    facts.insert(n);
}

int extract(int fct, int exp, int m) {
  while (m%fct == 0 && exp > 0) {
    m/=fct;
    exp--;
  }
  return m;
}

bool dividess(int n, int m) {
  facts.clear();
  fact(m);
  int ax = n;
  for(set<int>::iterator it = facts.begin(); it != facts.end(); ++it) {
    int tot_exp = 0;
    int fct = *it;
    n = ax;
    while (n > 0) {
      tot_exp += n/fct;
      n/= fct;
    }
    m = extract(fct,tot_exp,m);
    if (m%fct == 0) return false;
  }
  return true;
}

int main() {
  int n, m;
  makePrimes();
  while (scanf("%d%d",&n,&m) == 2) {
    if (dividess(n,m) == true) {
      printf("%d divides %d!\n",m,n);
    } else {
      printf("%d does not divide %d!\n",m,n);
    }
    
  }
}
