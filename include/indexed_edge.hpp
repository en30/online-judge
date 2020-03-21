#pragma once

class IndexedEdge {
 public:
  int from, to, index;
  bool reversed;
  IndexedEdge(int from, int to, int index, bool reversed = false)
      : from(from), to(to), index(index), reversed(reversed) {}

  IndexedEdge reverse() const {
    return IndexedEdge(to, from, index, !reversed);
  }
};
