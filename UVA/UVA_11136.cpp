#include<bits/stdc++.h>

using namespace std;

const int kMaxB = 1000005;
const int kMaxN = 5005;

int n, k, x;
set<int>bills;
int ct_bills[kMaxB];

int main() {
  while (scanf("%d",&n) == 1 && n != 0) {
    long long ans = 0LL;
    bills.clear();
    memset(ct_bills,0,sizeof(ct_bills));
    for(int i=0; i<n; ++i) {
      scanf("%d",&k);
      for(int j=0; j<k; ++j) {
        scanf("%d",&x);
	ct_bills[x]++;
	bills.insert(x);
      }
      set<int>::iterator first_it = bills.begin();
      set<int>::iterator last_it = bills.end();
      --last_it;
      int minim_value = *first_it;
      int maxim_value = *last_it;
      
      ct_bills[minim_value]--;
      ct_bills[maxim_value]--;
      
      ans = ans + (maxim_value - minim_value);
      if (ct_bills[maxim_value] == 0) bills.erase(maxim_value);
      if (ct_bills[minim_value] == 0) bills.erase(minim_value);
    }
    cout<<ans<<"\n";
  }
}
