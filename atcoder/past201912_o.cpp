#include <bits/stdc++.h>
#include "../include/template"

int N;
struct Face {
  int n, dice;
};

int main() {
  cin >> N;

  vector<Face> faces;
  rep(i, N) rep(j, 6) {
    int A;
    cin >> A;
    faces.push_back(Face{A, i});
  }

  sort(all(faces), [&](const Face& a, const Face& b) { return a.n < b.n; });

  int M = faces.size();
  vector<double> E(M + 1, 0);

  vector<double> cum(N, 1.0);
  E[M] = 1.0;
  double best = 0.0;
  for (int i = M - 1; i >= 0; --i) {
    cum[faces[i].dice] += E[i + 1] / 6.0;
    best = max(best, cum[faces[i].dice]);
    E[i] = best;
  }

  cout << setprecision(7) << best << endl;

  return 0;
}
