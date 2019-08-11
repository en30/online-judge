#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for (int i = 0; i < (int)N; i++)
#define all(a) (a).begin(), (a).end()

int N, X, Y;
vector<int> a;

int fx(int x, int y, int i);
int fy(int x, int y, int i);

unordered_map<int, unordered_map<int, unordered_map<int, int>>> mx, my;

int fx(int x, int y, int i) {
  if(i == N) return abs(x-y);

  if(mx[x][y].find(i) != mx[x][y].end()) return mx[x][y][i];

  int k = i;
  int m = -1;
  for(int j = i; j < N; j++) {
    int v = fy(a[j], y, j+1);
    if(v > m) {
      k = j;
      m = v;
    }
  }

  mx[x][y][i] = m;
  return m;
}

int fy(int x, int y, int i) {
  if(i == N) return abs(x-y);

  if(my[x][y].find(i) != my[x][y].end()) return my[x][y][i];

  int k = i;
  int m = 1e9 + 1;
  for(int j = i; j < N; j++) {
    int v = fx(x, a[j], j+1);
    if(v < m) {
      k = j;
      m = v;
    }
  }

  my[x][y][i] = m;
  return m;
}

int main () {
  cin >> N >> X >> Y;
  a.resize(N);

  rep(i,N) cin >> a[i];

  cout << fx(X, Y, 0) << endl;

  return 0;
}
