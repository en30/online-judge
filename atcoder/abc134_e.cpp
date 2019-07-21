#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for (int i = 0; i < (int)N; i++)

int N;
vector<int> A;

int main () {
  cin >> N;
  A.resize(N);
  rep(i,N) cin >> A[i];

  multiset<int> v;

  v.insert(A[0]);
  for(int i = 1; i < N; i++) {
    if(*v.begin() < A[i]) {
      auto it = v.lower_bound(A[i]);
      it--;
      v.erase(it);
    }
    v.insert(A[i]);
  }

  cout << v.size() << endl;

  return 0;
}
