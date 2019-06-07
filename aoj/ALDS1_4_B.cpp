#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for (int i = 0; i < (int)N; i++)

template<typename T>
int my_binary_search(vector<T> &sorted, T key) {
  int left = 0;
  int right = sorted.size();
  while(left < right) {
    int mid = (left + right) / 2;
    if(sorted[mid] == key) return mid;
    if(sorted[mid] > key) {
      right = mid;
    } else {
      left = mid + 1;
    }
  }
  return -1;
}

int main () {
  int n, q;

  cin >> n;
  vector<int> S(n);
  rep(i,n) cin >> S[i];

  cin >> q;
  vector<int> T(q);
  rep(i,q) cin >> T[i];

  int ans = 0;
  rep(i,q) {
    if(my_binary_search(S, T[i]) != -1) ans++;
  }
  cout << ans << endl;
  return 0;
}
