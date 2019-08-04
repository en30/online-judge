#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for (int i = 0; i < (int)N; i++)
#define all(a) (a).begin(), (a).end()

int A, B, C, D;

int main () {
  cin >> A >> B >> C >> D;
  if(A + B == C + D) {
    cout << "Balanced" << endl;
  } else if(A + B > C + D) {
    cout << "Left" << endl;
  } else {
    cout << "Right" << endl;
  }
  return 0;
}
