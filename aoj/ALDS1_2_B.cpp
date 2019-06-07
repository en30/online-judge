#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for (int i = 0; i < (int)N; i++)

int main () {
  int n;
  int a[100];
  int c = 0;

  scanf("%d", &n);
  rep(i,n) scanf("%d", &a[i]);

  rep(i,n) {
    int k = i;
    for(int j = i; j < n; j++){
      if(a[j] < a[k]) k = j;
    }
    if(i != k) {
      swap(a[k], a[i]);
      c++;
    }
  }

  rep(i,n) {
    if(i > 0) printf(" ");
    printf("%d", a[i]);
  }
  printf("\n%d\n", c);

  return 0;
}
