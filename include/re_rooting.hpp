/**
 * @brief <a
 * href="https://scrapbox.io/en30/%E5%85%A8%E6%96%B9%E4%BD%8D%E6%9C%A8DP">全方位木DP</a>O(V)
 */
template <typename Monoid>
class ReRooting {
  int V;
  vector<vector<int>> G;
  vector<vector<Monoid>> lpMemo, rpMemo;
  vector<unordered_map<int, int>> id;
  Monoid uninitialized;

  /**
   * @brief uの部分木[u->0, u->endIndex)までをreduceした値
   * @param u
   * @param endIndex
   */
  Monoid leftProduct(int u, int endIndex) {
    if (endIndex == 0) return Monoid::identity(u);
    if (lpMemo[u][endIndex] != uninitialized) return lpMemo[u][endIndex];

    return lpMemo[u][endIndex] =
               leftProduct(u, endIndex - 1) + value(G[u][endIndex - 1], u);
  }

  /**
   * @brief uの部分木(u->endIndex, u->G[u].size() - 1]までをreduceした値
   * @param u
   * @param endIndex
   */
  Monoid rightProduct(int u, int endIndex) {
    if (endIndex == G[u].size() - 1) return Monoid::identity(u);
    if (rpMemo[u][endIndex] != uninitialized) return rpMemo[u][endIndex];

    return rpMemo[u][endIndex] =
               value(G[u][endIndex + 1], u) + rightProduct(u, endIndex + 1);
  }

 public:
  /**
   * @brief
   * @param G 木の隣接リスト表現
   * @param reduce 複数の木の結果をまとめる結合的な演算
   * @param treeValue 部分木のまとめられた結果から木の値を計算する関数
   * @param identity Node iにおける単位元
   * @param uninitialized 未計算時の値
   */
  ReRooting(const vector<vector<int>> &G)
      : G(G), V(G.size()), uninitialized(Monoid()) {
    id.resize(V);
    lpMemo.resize(V), rpMemo.resize(V);

    for (int u = 0; u < V; ++u) {
      for (int i = 0; i < G[u].size(); ++i) {
        id[u][G[u][i]] = i;
      }

      lpMemo[u].resize(G[u].size() + 1, uninitialized);
      rpMemo[u].resize(G[u].size() + 1, uninitialized);
    }
  }

  /**
   * @brief uを根とし、u-pを除く部分木での量（p->uに対応する量）を計算
   * @param u 部分木の根
   * @param p 親
   */
  Monoid value(int u, int p) {
    if (p == -1) return leftProduct(u, G[u].size()).addRoot(u);

    return (leftProduct(u, id[u][p]) + rightProduct(u, id[u][p])).addRoot(u);
  }
};
