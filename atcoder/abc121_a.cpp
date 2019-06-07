#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for (int i = 0; i < (int)N; i++)

int main () {
  int H, W, h, w;
  cin >> H >> W >> h >> w;

  cout << (H*W - (h*W) - (H*w) + h*w) << endl;
  return 0;
}
