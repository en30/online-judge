/**
 * @brief <a
 * href="https://scrapbox.io/en30/%E5%85%A8%E6%96%B9%E4%BD%8D%E6%9C%A8DP">全方位木DP</a>O(V)
 */
template <typename Result, typename Product>
class ReRooting {
  int V;
  vector<vector<int>> G;
  vector<vector<Product>> lpMemo, rpMemo;
  vector<unordered_map<int, int>> id;
  function<Product(Product, Result)> reduce;
  function<Result(Product, Product)> treeValue;
  Product uninitialized;
  function<Product(int)> identity;

  /**
   * @brief uの部分木[u->0, u->endIndex)までをreduceした値
   * @param u
   * @param endIndex
   */
  Product leftProduct(int u, int endIndex) {
    if (endIndex == 0) return identity(u);
    if (lpMemo[u][endIndex] != uninitialized) return lpMemo[u][endIndex];

    return lpMemo[u][endIndex] = reduce(leftProduct(u, endIndex - 1),
                                        value(G[u][endIndex - 1], u));
  }

  /**
   * @brief uの部分木(u->endIndex, u->G[u].size() - 1]までをreduceした値
   * @param u
   * @param endIndex
   */
  Product rightProduct(int u, int endIndex) {
    if (endIndex == G[u].size() - 1) return identity(u);
    if (rpMemo[u][endIndex] != uninitialized) return rpMemo[u][endIndex];

    return rpMemo[u][endIndex] = reduce(rightProduct(u, endIndex + 1),
                                        value(G[u][endIndex + 1], u));
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
  ReRooting(const vector<vector<int>> &G,
            const function<Product(Product, Result)> &reduce,
            const function<Result(Product, Product)> &treeValue,
            const function<Product(int)> &identity, Product uninitialized)
      : G(G),
        V(G.size()),
        treeValue(treeValue),
        reduce(reduce),
        uninitialized(uninitialized),
        identity(identity) {
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
  Result value(int u, int p) {
    if (p == -1) return treeValue(leftProduct(u, G[u].size()), identity(u));

    return treeValue(leftProduct(u, id[u][p]), rightProduct(u, id[u][p]));
  }
};
