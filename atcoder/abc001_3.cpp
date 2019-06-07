#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for (int i = 0; i < (int)N; i++)

vector<string> DIR = {"N", "NNE", "NE", "ENE", "E", "ESE", "SE", "SSE", "S", "SSW", "SW", "WSW", "W", "WNW", "NW", "NNW", "N"};

string dir(int deg, int w) {
  if(w == 0) return "C";
  return DIR[(deg + 112) / 225];
}

vector<int> WR = {3, 16, 34, 55, 80, 108, 139, 172, 208, 245, 285, 327};

int W(int dis) {
  int v = roundf(dis * 10.0 / 60.0);
  for(int i = 0; i < WR.size(); i++) {
    if(v < WR[i]) return i;
  }
  return 12;
}

int main () {
  int deg, dis;
  cin >> deg >> dis;
  int w = W(dis);
  printf("%s %d\n", dir(deg, w).c_str(), w);
  return 0;
}
