#include<bits/stdc++.h>

using namespace std;

string s;

int main() {
  while (cin>>s) {
    if (s == "0") break;
    long long ans = 1LL;
    for(int i=1; i<=s.size(); ++i)
      ans *=i;
    cout<<ans<<"\n";
  }
}
