#pragma once

/**
 * @brief 素集合を扱うためのデータ構造
 */
class UnionFindTree {
  vector<int> parent, rank, sz;

 public:
  int find(int x) {
    if (parent[x] != x) {
      parent[x] = find(parent[x]);
    }
    return parent[x];
  }

  UnionFindTree(int size) {
    parent.resize(size);
    rank.resize(size, 0);
    sz.resize(size, 1);
    for (int i = 0; i < size; i++) parent[i] = i;
  }

  /**
   * @brief 要素x, yの属する集合を併合する
   * @param x
   * @param y
   * @return 併合した場合にはtrue, 併合済みだった場合にはfalseを返す
   */
  bool unite(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) return false;

    if (rank[x] < rank[y]) {
      parent[x] = y;
      sz[y] += sz[x];
    } else {
      parent[y] = x;
      sz[x] += sz[y];
      if (rank[x] == rank[y]) rank[x]++;
    }
    return true;
  }

  /**
   * @brief 要素x, yが同一の集合に属するか
   * @param x
   * @param y
   * @return
   */
  bool same(int x, int y) { return find(x) == find(y); }

  /**
   * @brief 要素xの属する集合の大きさ
   * @param x
   * @return
   */
  int size(int x) { return sz[find(x)]; }
};
