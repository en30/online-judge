#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for (int i = 0; i < (int)N; i++)

int N;
vector<int> a;

bool ok() {
  if(a[0] == 0 && a[0] == a[N-1]) return true;
  if(N % 3) return false;
  int p = N/3;
  return a[0] == a[p-1] && a[p] == a[2*p-1] && a[2*p] == a[N-1] && ((a[0] ^ a[p] ^ a[2*p]) == 0);
}

int main () {
  cin >> N;
  a.resize(N);
  rep(i,N) cin >> a[i];
  sort(a.begin(), a.end());

  cout << (ok() ? "Yes" : "No") << endl;
  return 0;
}
