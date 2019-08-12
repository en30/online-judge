#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for (int i = 0; i < (int)N; i++)
#define all(a) (a).begin(), (a).end()

int N, K;
int B[200001];

int main () {
  cin >> N >> K;
  vector<int> B(N+1, 0);
  int A;
  rep(i,N) {
    cin >> A;
    B[A]++;
  }

  priority_queue<int, vector<int>, greater<int>> pq;
  rep(i,N+1) {
    if(B[i] != 0) pq.push(B[i]);
  }

  int ans = 0;
  while(pq.size() > K) {
    ans += pq.top();
    pq.pop();
  }

  cout << ans << endl;
  return 0;
}
