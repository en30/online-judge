#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for (int i = 0; i < (int)N; i++)

string s;
int main() {
  cin >> s;
  cout << s[0];
  cout << s.size() - 2;
  cout << s[s.size() - 1];
  cout << endl;
}
