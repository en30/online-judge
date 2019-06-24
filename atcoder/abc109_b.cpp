#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for (int i = 0; i < (int)N; i++)

int main () {
  int N;
  cin >> N;
  vector<string> W(N);
  set<string> s;
  rep(i,N) {
    cin >> W[i];
    s.insert(W[i]);
  }

  bool valid = (s.size() == N);
  for(int i = 0; i < N - 1 && valid; i++) {
    valid = (W[i][W[i].size()-1] == W[i+1][0]);
  }

  cout << (valid ? "Yes" : "No") << endl;
  return 0;
}
