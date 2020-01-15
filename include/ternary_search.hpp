double argminimal(function<double(double)> f, double l, double r,
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

double minimal(function<double(double)> f, double l, double r, int iter = 80) {
  return f(argminimal(f, l, r, iter));
}

double argmaximal(function<double(double)> f, double l, double r,
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

double maximul(function<double(double)> f, double l, double r, int iter = 80) {
  return f(argmaximal(f, l, r, iter));
}
