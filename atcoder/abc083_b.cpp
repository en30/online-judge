#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for (int i = 0; i < (int)N; i++)
#define all(a) (a).begin(), (a).end()

int N, A, B;

int digitSum(int n) {
  if(n < 10) return n;
  return (n % 10) + digitSum(n/10);
}

int main () {
  cin >> N >> A >> B;

  int ans = 0;
  for(int i = 1; i <= N; i++){
    int sum = digitSum(i);
    if(A <= sum && sum <= B) ans += i;
  }

  cout << ans << endl;

  return 0;
}
