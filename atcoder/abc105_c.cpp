#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for (int i = 0; i < (int)N; i++)

int main () {
  int N;
  cin >> N;

  int i = N;
  stack<int> x;
  if(N == 0) x.push(0);
  while(i != 0) {
    int d = abs(i % 2);
    x.push(d);
    i = (i - d) / -2;
  }

  while(!x.empty()) {
    cout << x.top();
    x.pop();
  }
  cout << endl;

  return 0;
}
