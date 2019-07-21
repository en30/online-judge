#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for (int i = 0; i < (int)N; i++)

int N;
vector<int> a, b;

int main () {
  cin >> N;
  a.resize(N+1);
  b.resize(N+1, 0);
  rep(i,N) cin >> a[i+1];

  for(int i = N; i >= 1; i--) {
    for(int j = i; j <= N; j += i) b[i] ^= b[j];
    b[i] = (b[i] != a[i]);
  }

  int M = 0;
  vector<int> c;
  for(int i = 1; i <= N; i++) if(b[i]) c.push_back(i);
  cout << c.size() << endl;
  for(int i = 0; i < c.size(); i++) {
    cout << c[i];
    printf(i == c.size() - 1 ? "\n" : " ");
  }

  return 0;
}
