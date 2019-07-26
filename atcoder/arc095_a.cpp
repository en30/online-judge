#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for (int i = 0; i < (int)N; i++)
#define all(a) (a).begin(), (a).end()

typedef pair<int, int> p;
int N;
vector<p> X;
vector<int> B;

int main () {
  cin >> N;
  X.resize(N);
  B.resize(N);
  rep(i,N) {
    cin >> X[i].first;
    X[i].second = i;
  }

  sort(all(X));

  rep(i,N) {
    auto m = X[N/2 - (i >= N/2)];
    B[X[i].second] = m.first;
  }

  rep(i,N) {
    cout << B[i] << endl;
  }

  return 0;
}
