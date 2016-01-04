#include<bits/stdc++.h>

using namespace std;

int f(int num, int mult) {
  int ret = 0, pot = 1;
  int mod = mult;
  while (num > 0) {
    if (num%2 == 1) {
      if (mod%2 == 0) ret += pot;
      ++mod;
    }
    pot *=2;
    num/=2;
  }
  return ret;
}

int main() {
  int n;
  while (scanf("%d",&n) == 1) {
    if (n == 0) break;
    cout<<f(n,0)<<" "<<f(n,1)<<"\n";
  }
}
