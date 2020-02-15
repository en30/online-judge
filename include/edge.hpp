#pragma once

struct Edge {
  int from, to;
  Edge(){};
  Edge(int from, int to) : from(from), to(to) {}

  void scanFrom(std::istream& strm, int base = 1) {
    strm >> from >> to;
    if (base == 1) --from, --to;
  }

  Edge reverse() const { return Edge(to, from); }
};

inline std::istream& operator>>(std::istream& strm, Edge& t) {
  t.scanFrom(strm);
  return strm;
}
