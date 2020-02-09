#pragma once

template <typename T>
class Grid {
  struct Pos {
    int i, j;
    Pos(int i, int j) : i(i), j(j) {}
  };

  int H, W;
  vector<vector<T>> G;

  vector<int> di8 = {1, 1, 0, -1, -1, -1, 0, 1},
              dj8 = {0, 1, 1, 1, 0, -1, -1, -1};
  vector<int> di4 = {1, 0, -1, 0}, dj4 = {0, 1, 0, -1};

  vector<Pos> neighbor(int i, int j, const vector<int>& dis,
                       const vector<int>& djs) const {
    vector<Pos> res;
    for (int di : dis)
      for (int dj : djs)
        if (in(i + di, j + dj)) res.emplace_back(i + di, j + dj);
    return res;
  }

 public:
  Grid(int H, int W) : H(H), W(W) { G.resize(H, vector<T>(W)); }

  vector<T>& operator[](int i) { return G[i]; }

  bool in(int i, int j) const { return (0 <= i && i < H && 0 <= j && j < W); }

  vector<Pos> neighbor8(int i, int j) const { return neighbor(i, j, di8, dj8); }

  vector<Pos> neighbor4(int i, int j) const { return neighbor(i, j, di4, dj4); }

  void scanFrom(istream& strm) { rep(i, H) rep(j, W) strm >> G[i][j]; }

  void outputTo(ostream& strm) {
    rep(i, H) {
      rep(j, W) cout << G[i][j];
      strm << endl;
    }
  }
};

template <typename T>
inline istream& operator>>(istream& strm, Grid<T>& g) {
  g.scanFrom(strm);
  return strm;
}

template <typename T>
inline ostream& operator<<(ostream& strm, Grid<T>& g) {
  g.outputTo(strm);
  return strm;
}
