#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for (int i = 0; i < (int)N; i++)

int main() {
  stack<int> s;
  int a, b;
  string token;
  while(cin >> token) {
    if(token == "+") {
      b = s.top(); s.pop();
      a = s.top(); s.pop();
      s.push(a+b);
    } else if (token == "-") {
      b = s.top(); s.pop();
      a = s.top(); s.pop();
      s.push(a-b);
    } else if (token == "*") {
      b = s.top(); s.pop();
      a = s.top(); s.pop();
      s.push(a*b);
    } else {
      s.push(stoi(token));
    }
  }
  cout << s.top() << endl;
  return 0;
}
