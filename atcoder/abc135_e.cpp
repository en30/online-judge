#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for (int i = 0; i < (int)N; i++)
#define all(a) (a).begin(), (a).end()

int K, X, Y;

struct V {
  int x, y;

  V(int _x, int _y) {
    x = _x, y = _y;
  }
};

void finish(int x, int y, vector<V> & res) {
  assert(x >= 0 && y >= 0 && x <= y && x + y <= 2*K);
  if(x == 0 && y == 0) return;
  if(x + y == K) {
    res.emplace_back(x, y);
    return;
  }
  if((x + y) % 2) {
    int dx, dy;
    if(x + y >= K) {
      dx = x, dy = K - x;
    } else {
      dx = -(K-1)/2, dy = -(K+1)/2;
    }
    res.emplace_back(dx, dy);
    x -= dx, y -= dy;
  }
  int u = (x+y)/2, v = (x-y)/2;
  res.emplace_back(K+v, -v);
  res.emplace_back(-K+u, u);
}

auto flip(int &X, int &Y) {
  bool flipX = false, flipY = false, flipXY = false;
  if(X < 0) {
    X = -X;
    flipX = true;
  }
  if(Y < 0) {
    Y = -Y;
    flipY = true;
  }
  if(X > Y) {
    swap(X, Y);
    flipXY = true;
  }
  assert(X >= 0 && Y >= 0 && X <= Y);
  auto reverse = [=](V &v) {
    if(flipXY) swap(v.x, v.y);
    if(flipY) v.y = -v.y;
    if(flipX) v.x = -v.x;

  };
  return reverse;
}

int main () {
  cin >> K >> X >> Y;

  if(K % 2 == 0 && (X + Y) % 2) {
    cout << -1 << endl;
    return 0;
  }

  auto reverseFlip = flip(X, Y);
  vector<V> moves;
  while(X > K) {
    X -= K;
    moves.emplace_back(K, 0);
  }
  while(Y > 2*K) {
    Y -= K;
    moves.emplace_back(0, K);
  }
  if(X + Y > 2*K) {
    moves.emplace_back(X, K-X);
    Y -= K - X;
    X = 0;
  }
  finish(X, Y, moves);

  cout << moves.size() << endl;

  int x = 0, y = 0;
  for(V &v: moves) {
    reverseFlip(v);
    x += v.x, y += v.y;
    printf("%d %d\n", x, y);
  }

  return 0;
}
