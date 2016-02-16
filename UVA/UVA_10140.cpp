#include<bits/stdc++.h>

using namespace std;

const int kMaxN = 1200005;
const int kMaxPrime = (1<<16);
vector<int>primes;
vector<int>range_primes;

bool pri[kMaxN]; 

void sieve(int L, int U) {
  for(long long i=L; i<=U; ++i) {

    if (i == 1)pri[i-L] = false;
    else pri[i-L] = true;
  }
  
  for(int i=0; i<primes.size(); ++i) {
    for(long long j=(1LL*L/primes[i])*primes[i]; j<=U; j+=primes[i]) {
      if (j >= L && j != primes[i]) {
	
	pri[j-L] = false;
      }
    }
  }
  for(long long i=L; i<=U; ++i) {
    if (pri[i-L] == true)
      range_primes.push_back(i);
  }
}

bool isPrime(int num) {
  for(int i=2; i*i<=num; ++i)
    if (num%i == 0)
      return false;
  return true;
}

void makePrimes() {
  for(int i=2; i<=kMaxPrime; ++i) {
    if (isPrime(i) == true)
      primes.push_back(i);
  }
}

int main() {
  int L, U;
  makePrimes();
  while (scanf("%d%d",&L,&U) == 2) {
    range_primes.clear();
    sieve(L,U);
    int ans1 = -1, ans2 = INT_MAX;
    if (range_primes.size() <= 1) {
      puts("There are no adjacent primes.");
    } else {
      for(int i=1; i<range_primes.size(); ++i) {
        ans1 = max(ans1,range_primes[i] - range_primes[i-1]);
	ans2 = min(ans2,range_primes[i] - range_primes[i-1]);
      }
      int a,b = -1,c,d = -1;
      for(int i=1; i<range_primes.size(); ++i) {
        if (range_primes[i] - range_primes[i-1] == ans1 && d == -1 ) {
	  d = range_primes[i];
	  c = range_primes[i-1];
	}
	if (range_primes[i] - range_primes[i-1] == ans2 && b == -1) {
	  b = range_primes[i];
	  a = range_primes[i-1];
	}
      }
      printf("%d,%d are closest, %d,%d are most distant.\n",a,b,c,d);
    }
  }
}
