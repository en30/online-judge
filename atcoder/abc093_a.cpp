#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for (int i = 0; i < (int)N; i++)
#define all(a) (a).begin(), (a).end()

int main () {
  string S;
  cin >> S;
  sort(all(S));
  cout << (S == "abc" ? "Yes" : "No") << endl;
  return 0;
}
