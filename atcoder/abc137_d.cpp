#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for (int i = 0; i < (int)N; i++)
#define all(a) (a).begin(), (a).end()

int N, M;

struct Work {
  int A, B;
};

vector<Work> works;

int main () {
  cin >> N >> M;
  works.resize(N);
  rep(i,N) cin >> works[i].A >> works[i].B;

  sort(all(works), [&](const Work& a, const Work& b) {
      return a.A < b.A;
    });

  ll ans = 0;
  priority_queue<int> pq;
  for(int i = 1, j = 0; i <= M; i++) {
    while(works[j].A == i) {
      pq.push(works[j].B);
      j++;
    }
    if(pq.empty()) continue;

    ans += pq.top();
    pq.pop();
  }

  cout << ans << endl;
  return 0;
}
