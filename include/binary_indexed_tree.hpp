/**
 * @brief 要素に対する加算と、区間の和をO(logN)で行えるデータ構造
 * @tparam T
 */
template <typename T>
class BinaryIndexedTree {
  int N;
  vector<T> bit;

 public:
  BinaryIndexedTree(int N) : N(N) { bit.resize(N, 0); };

  /**
   * @brief [0, i)の和を求める
   * @param i
   * @return
   */
  T sum(int i) {
    i -= 1;
    T s = 0;
    while (i > 0) {
      s += bit[i];
      i -= i & -i;
    }
    return s;
  }

  /**
   * @brief [l, r)の和を求める
   * @param l
   * @param r
   * @return
   */
  T sum(int l, int r) { return sum(r) - sum(l); }

  /**
   * @brief i番目の要素にxを加える
   * @param i
   * @param x
   */
  void add(int i, T x) {
    while (i <= N) {
      bit[i] += x;
      i += i & -i;
    }
  }
};
