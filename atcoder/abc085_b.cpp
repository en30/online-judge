#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for (int i = 0; i < (int)N; i++)
#define all(a) (a).begin(), (a).end()

int N;
set<int> s;

int main () {
  cin >> N;
  rep(i,N) {
    int d;
    cin >> d;
    s.insert(d);
  }

  cout << s.size() << endl;
  return 0;
}
