#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for (int i = 0; i < (int)N; i++)

int A, B;

int main () {
  cin >> A >> B;

  cout << (A <= 8 && B <= 8 ? "Yay!" : ":(") << endl;
  return 0;
}
