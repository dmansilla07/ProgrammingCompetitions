#include<bits/stdc++.h>

using namespace std;

const int kMaxN = 2000000000;
const int kMaxP = 100000;

vector<int> divisors;

void getDivisors(int n) {
  divisors.clear();
  for(int i=1; 1LL*i*i<=n; ++i) {
    if (n%i == 0) {
      divisors.push_back(i);
      if (n/i != i) divisors.push_back(n/i);
    }
  }
  sort(divisors.begin(), divisors.end());
}

long long lcm(long long a, long long b) {
  return (a*b)/__gcd(a,b);
}

int main() {
  int N;
  while (scanf("%d",&N) == 1) {
    if (N == 0) break;
    getDivisors(N);
    int ans = 0;
    for(int i=0; i<divisors.size(); ++i) {
      for(int j=i; j<divisors.size(); ++j) {
        if (lcm(divisors[i], divisors[j]) == N)
	  ++ans;
      }
    }
    printf("%d %d\n",N,ans);
  }
}
