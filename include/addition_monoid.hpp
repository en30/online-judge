#pragma once

template <typename T>
struct AdditionMonoid {
  T v;
  bool operator==(const AdditionMonoid& that) const { return v == that.v; }
  bool operator!=(const AdditionMonoid& that) const {
    return !(*(this) == that);
  }

  static AdditionMonoid identity() { return AdditionMonoid(0); }

  AdditionMonoid(T v = 0) : v(v) {}
  AdditionMonoid& operator+=(const AdditionMonoid& that) {
    v += that.v;
    return *this;
  }
  AdditionMonoid operator+(const AdditionMonoid& that) const {
    return AdditionMonoid(*this) += that;
  }
};
