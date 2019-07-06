#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for (int i = 0; i < (int)N; i++)

bool ok(int N) {
  for(int i = 0; i <= 100/4; i++) {
    for(int j = 0; j <= 100/7; j++) {
      if(4*i+7*j == N) return true;
    }
  }
  return false;
}

int main () {
  int N;
  cin >> N;

  cout << (ok(N) ? "Yes" : "No") << endl;
  return 0;
}
