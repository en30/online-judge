#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for (int i = 0; i < (int)N; i++)

const int SENTINEL = 1e9 + 1;

int merge(vector<int> &S, int left, int mid, int right) {
  int n1 = mid - left;
  int n2 = right - mid;
  vector<int> L(n1+1), R(n2+1);
  rep(i,n1) L[i] = S[left+i];
  rep(i,n2) R[i] = S[mid+i];
  L[n1] = SENTINEL;
  R[n2] = SENTINEL;
  int i = 0, j = 0;
  for(int k = left; k < right; k++) {
    if(L[i] <= R[j]) {
      S[k] = L[i];
      i++;
    } else {
      S[k] = R[j];
      j++;
    }
  }
  return right - left;
}

int mergeSort(vector<int> &S, int left, int right) {
  if(left + 1 < right) {
    int mid = (left + right) / 2;
    int nl = mergeSort(S, left, mid);
    int nr = mergeSort(S, mid, right);
    int nm = merge(S, left, mid, right);
    return nl + nr + nm;
  }
  return 0;
}



int main () {
  int n;
  cin >> n;
  vector<int> S(n);
  rep(i,n) cin >> S[i];

  int c = mergeSort(S, 0, n);

  for(int i = 0; i < n; i++) {
    if(i != 0) cout << ' ';
    cout << S[i];
  }
  cout << endl << c << endl;

  return 0;
}
