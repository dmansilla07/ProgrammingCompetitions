#include<bits/stdc++.h>

using namespace std;

int main() {
  int tea, x, ans = 0;
  scanf("%d",&tea);
  for(int i=0; i<5; ++i) {
    scanf("%d",&x);
    if (x == tea) ++ans;
  }
  printf("%d\n",ans);
}
