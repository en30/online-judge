#include <bits/stdc++.h>
#include "../include/template"

int main() {
  int W, H;
  cin >> W >> H;
  if (H * 4 == W * 3) {
    cout << "4:3";
  } else {
    cout << "16:9";
  }
  cout << endl;
  return 0;
}
