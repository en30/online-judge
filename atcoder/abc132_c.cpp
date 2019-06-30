#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for (int i = 0; i < (int)N; i++)

int main () {
  int N;
  cin >> N;

  vector<int> d(N);
  rep(i,N) cin >> d[i];

  sort(d.begin(), d.end());

  cout << d[N/2] - d[N/2-1] << endl;

  return 0;
}
