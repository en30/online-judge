#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for (int i = 0; i < (int)N; i++)

struct task {
  int duration, deadline;
};

int main () {
  int N;
  cin >> N;
  vector<task> T(N);
  rep(i,N) cin >> T[i].duration >> T[i].deadline;

  sort(T.begin(), T.end(), [](const task&a, const task&b) {
      return a.deadline < b.deadline;
    });

  int t = 0;
  rep(i,N) {
    t += T[i].duration;
    if(t > T[i].deadline) {
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;

  return 0;
}
