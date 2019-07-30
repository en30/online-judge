#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for (int i = 0; i < (int)N; i++)
#define all(a) (a).begin(), (a).end()

int A, B;
string S;

bool ok() {
  for(int i = 0; i < A; i++){
    if(S[i] < '0' || S[i] > '9') return false;
  }
  if(S[A] != '-') return false;
  for(int i = A+1; i < A+B+1; i++) {
    if(S[i] < '0' || S[i] > '9') return false;
  }
  return true;
}

int main () {
  cin >> A >> B >> S;

  cout << (ok() ? "Yes" : "No") << endl;
  return 0;
}
