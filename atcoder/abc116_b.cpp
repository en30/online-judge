#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for (int i = 0; i < (int)N; i++)

int s;
vector<int> used(1000001, 0);

int collatz(int i, int v) {
  if(used[v]) return i;
  used[v] = 1;
  int x = (v % 2 == 0 ? v/2 : 3*v+1);
  return collatz(i+1, x);
}

int main () {
  cin >> s;

  cout << collatz(1, s) << endl;

  return 0;
}
