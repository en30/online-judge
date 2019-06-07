#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for (int i = 0; i < (int)N; i++)

bool isConsistent(vector<int> &a, int N) {
  sort(a.begin(), a.end());
  if(a[N-1] - a[0] > 1) return false;
  if(a[0] == a[N-1]) {
    return a[0] == N - 1 || (1 <= a[0] && a[0] <= N/2);
  } else {
    int i = 0;
    while(a[i] == a[0]) i++;
    return i <= a[0] && a[0] <= i - 1 + (N-i)/2;
  }
}

int main () {
  int N;
  scanf("%d", &N);
  vector<int> a(N, 0);
  rep(i,N) scanf("%d", &a[i]);

  printf(isConsistent(a, N) ? "Yes\n" : "No\n");
  return 0;
}
