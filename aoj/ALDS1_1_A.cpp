#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for (int i = 0; i < (int)N; i++)

void printVector(vector<int> &a, int n) {
  rep(i,n) {
    cout << a[i];
    if(i == n -1) {
      cout << endl;
    } else {
      cout << ' ';
    }
  }
}

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i,n) cin >> a[i];

  printVector(a, n);
  for(int i = 1; i < n ; i++){
    int key = a[i];
    int j = i - 1;
    while(j >= 0 && a[j] > key) {
      a[j+1] = a[j];
      j--;
    }
    a[j+1] = key;
    printVector(a, n);
  }
}
