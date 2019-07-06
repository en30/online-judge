#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for (int i = 0; i < (int)N; i++)

int main () {
  string S;
  cin >> S;
  if(S[0] == S[1] || S[1] == S[2] || S[2] == S[3]) {
    cout << "Bad";
  } else {
    cout << "Good";
  }
  cout << endl;

  return 0;
}
