#pragma once

template <typename Monoid>
class SegmentTree {
  int sz;
  vector<Monoid> node;
  const Monoid identity;

 public:
  SegmentTree(int n) : identity(Monoid::identity()) {
    sz = 1;
    while (sz < n) sz <<= 1;
    node.resize(2 * sz, identity);
  }

  int size() const { return sz; }

  /**
   * @brief iの値をxに変更するO(logN)
   * @param i
   * @param x
   */
  void update(int i, const Monoid &x) {
    i += sz;
    node[i] = x;
    while (i >>= 1) {
      node[i] = node[2 * i + 0] + node[2 * i + 1];
    }
  }

  /**
   * @brief iでの値を返すO(1)
   * @param k
   * @return
   */
  Monoid at(const int &k) const { return node[k + sz]; }

  /**
   * @brief iに、iでの値とxの演算結果を入れるO(logN)
   * @param i
   * @param x
   */
  void add(int i, const Monoid &x) { return update(i, at(i) + x); }

  /**
   * @brief [l, r)での演算結果を取得するO(logN)
   * @param l
   * @param r
   * @return
   */
  Monoid query(int l, int r) {
    Monoid L = identity, R = identity;
    for (l += sz, r += sz; l < r; l >>= 1, r >>= 1) {
      if (l & 1) L += node[l++];
      if (r & 1) R += node[--r];
    }
    return L + R;
  }
};
