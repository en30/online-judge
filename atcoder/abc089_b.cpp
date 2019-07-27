#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for (int i = 0; i < (int)N; i++)
#define all(a) (a).begin(), (a).end()

int main () {
  int N;
  cin >> N;

  bool four = false;
  rep(i,N) {
    char s;
    cin >> s;
    if(s == 'Y') four = true;
  }

  cout << (four ? "Four" : "Three") << endl;
  return 0;
}
