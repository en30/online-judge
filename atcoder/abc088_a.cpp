#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for (int i = 0; i < (int)N; i++)

int main () {
  int N, A;
  cin >> N >> A;
  cout << (N % 500 <= A ? "Yes" : "No") << endl;
  return 0;
}
