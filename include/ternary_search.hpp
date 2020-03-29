#pragma once

template <typename T>
T argminimal(const function<T(T)>& f, T l, T r) {
  while (r - l > 1) {
    T m = (l + r) / 2;
    if (f(m) - f(m - 1) < 0) {
      l = m;
    } else {
      r = m;
    }
  }
  return l;
}

template <typename T>
T minimal(const function<T(T)>& f, T l, T r) {
  return f(argminimal<T>(f, l, r));
}

template <typename T>
T argmaximal(const function<T(T)>& f, T l, T r) {
  while (r - l > 1) {
    T m = (l + r) / 2;
    if (f(m) - f(m - 1) > 0) {
      l = m;
    } else {
      r = m;
    }
  }
  return l;
}

template <typename T>
T maximal(const function<T(T)>& f, T l, T r) {
  return f(argmaximal<T>(f, l, r));
}

double argminimal(const function<double(double)>& f, double l, double r,
                  int iter = 80) {
  for (int i = 0; i < iter; ++i) {
    double c1 = (l * 2 + r) / 3, c2 = (l + r * 2) / 3;
    if (f(c1) > f(c2)) {
      l = c1;
    } else {
      r = c2;
    }
  }
  return l;
}

double minimal(const function<double(double)>& f, double l, double r,
               int iter = 80) {
  return f(argminimal(f, l, r, iter));
}

double argmaximal(const function<double(double)>& f, double l, double r,
                  int iter = 80) {
  for (int i = 0; i < iter; ++i) {
    double c1 = (l * 2 + r) / 3, c2 = (l + r * 2) / 3;
    if (f(c1) > f(c2)) {
      r = c2;
    } else {
      l = c1;
    }
  }
  return l;
}

double maximul(const function<double(double)>& f, double l, double r,
               int iter = 80) {
  return f(argmaximal(f, l, r, iter));
}
