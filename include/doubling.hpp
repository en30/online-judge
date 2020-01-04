class Doubling {
  vector<vector<int>> transitions;
  int logMax;

 public:
  Doubling(const vector<int>& transition, int logMax) : logMax(logMax) {
    transitions.resize(logMax + 1, transition);
    int N = transition.size();
    for (int k = 0; k < logMax; ++k) {
      rep(i, N) transitions[k + 1][i] = transitions[k][transitions[k][i]];
    }
  }

  int transition(int i, int n) {
    assert(log2(n) <= logMax);
    int j = i;
    for (int k = log2(n); k >= 0; --k) {
      if ((n >> k) & 1) j = transitions[k][j];
    }
    return j;
  }
};
