/**
 * @brief <a href="https://scrapbox.io/en30/Convex_Hull_Trick">Convex Hull
 * Trick</a>のためのデータ構造
 * @tparam T x, yの型
 */
template <typename T>
class LiChaoTree {
  class Line {
   public:
    T gradients;
    T intercepts;
    Line(T a, T b) : gradients(a), intercepts(b) {}
    T y(T x) { return gradients * x + intercepts; }
  };

  vector<T> xs;
  vector<Line> nodes;
  int N;

  int V() { return 2 * N - 1; }

  // [l, r)
  void _insert(int i, int l, int r, Line& line) {
    T xl = xs[l], xr = xs[r - 1];
    if (nodes[i].y(xl) <= line.y(xl) && nodes[i].y(xr) <= line.y(xr)) return;
    if (nodes[i].y(xl) > line.y(xl) && nodes[i].y(xr) > line.y(xr)) {
      nodes[i] = line;
      return;
    }

    int m = (l + r) / 2;
    T xm = xs[m];
    if (line.y(xm) < nodes[i].y(xm)) swap(line, nodes[i]);

    if (line.y(xl) < nodes[i].y(xl)) {
      insert(2 * i + 1, l, m, line);
    } else {
      insert(2 * i + 2, m, r, line);
    }
  }

 public:
  /**
   * @param x 直線群の最小値を計算したいx座標
   */
  LiChaoTree(const vector<T>& x) : xs(x) {
    N = 1;
    while (N < xs.size()) N <<= 1;

    while (xs.size() < N) xs.push_back(xs.back() + 1);
    nodes.resize(V(), Line(0, 1e32));
  }

  /**
   * @brief 直線の追加 O(logN)
   * @param gradients 傾き
   * @param intercepts 切片
   */
  void insert(T gradients, T intercepts) {
    Line line = Line(gradients, intercepts);
    _insert(0, 0, N, line);
  }

  /**
   * @brief 初期化時に渡したx[i]での直線群の最小値 O(logN)
   * @param i xのindex
   */
  T y(int i) {
    T x = xs[i];
    i += N - 1;
    T res = nodes[i].y(x);
    while (i > 0) {
      i = (i - 1) / 2;
      res = min(res, nodes[i].y(x));
    }
    return res;
  }
};
