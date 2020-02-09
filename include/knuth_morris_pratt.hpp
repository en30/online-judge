#pragma once

/**
 * @brief substring search
 * @tparam T
 */
template <typename T>
class KnuthMorrisPratt {
  int M;
  T pattern;
  vector<int> next;

 public:
  KnuthMorrisPratt(const T& pattern) : pattern(pattern) {
    M = pattern.size();
    next.resize(M);
    next[0] = -1;
    for (int i = 1, j = -1; i < M; ++i) {
      while (j != -1 && pattern[i] != pattern[j + 1]) j = next[j];
      if (pattern[j + 1] == pattern[i]) ++j;
      next[i] = j;
    }
  }

  /**
   * @brief パターンにマッチするすべてのindex
   * @param text
   * @return
   */
  vector<int> matchedIndices(const T& text) {
    int N = text.size();
    vector<int> res;
    for (int i = 0, j = -1; i < N; ++i) {
      while (j != -1 && text[i] != pattern[j + 1]) j = next[j];
      if (pattern[j + 1] == text[i]) ++j;
      if (j == M - 1) {
        res.push_back(i - j);
        j = next[j];
      }
    }
    return res;
  }
};
