#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for (int i = 0; i < (int)N; i++)

int n;
int a[100];

int main () {
  scanf("%d", &n);
  rep(i,n) scanf("%d", &a[i]);

  int c = 0;

  rep(i,n) for(int j = n - 1; j > i; j--) {
    if(a[j] < a[j-1]) {
      swap(a[j], a[j-1]);
      c++;
    }
  }

  rep(i,n) {
    if(i > 0) printf(" ");
    printf("%d", a[i]);
  }
  printf("\n");
  printf("%d\n", c);

  return 0;
}
