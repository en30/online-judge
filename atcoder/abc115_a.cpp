#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for (int i = 0; i < (int)N; i++)

int main () {
  int d;
  cin >> d;

  cout << "Christmas";
  rep(i,25-d) cout << " Eve";

  cout << endl;
  return 0;
}
