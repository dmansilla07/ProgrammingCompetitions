#include<bits/stdc++.h>

using namespace std;

const int kMaxN = 5;

int a[kMaxN], b[kMaxN];

int main() {
  for(int i=0; i<3; ++i) {
    scanf("%d",&a[i]);
    b[i] = a[i];
  }
  sort(a, a+3);
  for(int i=0; i<3; ++i)
    printf("%d\n",a[i]);
  puts("");
  for(int i=0; i<3; ++i)
    printf("%d\n",b[i]);
  
}
