#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for (int i = 0; i < (int)N; i++)

int main () {
  int a[5],k;
  rep(i,5) cin >> a[i];
  cin >> k;

  for(int i = 0; i < 5; i++) {
    for(int j = i + 1; j < 5; j++) {
      if(a[j] - a[i] > k) {
        cout << ":(" << endl;
        return 0;
      }
    }
  }

  cout << "Yay!" << endl;
  return 0;
}
