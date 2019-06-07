#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for (int i = 0; i < (int)N; i++)

int main () {
  int H, W, h, w;
  scanf("%d %d %d %d", &H, &W, &h, &w);

  if(H % h == 0 && W % w == 0) {
    printf("No\n");
    return 0;
  }

  printf("Yes\n");
  int x = - 10*(h*w - 1)*(H/h)*(W/w) - 1;
  int y = 10*(H/h)*(W/w);
  rep(i,H){
    rep(j,W) {
      if(j != 0) printf(" ");
      printf("%d", i % h == h - 1 && j % w == w - 1 ? x : y);
    }
    printf("\n");
  }

  return 0;
}
