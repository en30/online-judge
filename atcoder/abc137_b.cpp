#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for (int i = 0; i < (int)N; i++)
#define all(a) (a).begin(), (a).end()

int K, X;

int main () {
  cin >> K >> X;

  for(int i =  X - K + 1; i < X+K; i++) {
    if(i != X - K + 1) cout << " ";
    cout << i;
  }
  cout << endl;

  return 0;
}
