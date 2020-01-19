template <typename T>
class RunLength {
 public:
  struct Element {
    T value;
    int count;
    Element(T value, int count) : value(value), count(count) {}
  };

  static vector<Element> compress(auto& s) {
    vector<Element> res;
    if (s.size() == 0) return res;

    res.emplace_back(s[0], 0);
    for (int i = 0; i < s.size(); ++i) {
      if (res.back().value == s[i]) {
        res.back().count++;
      } else {
        res.emplace_back(s[i], 1);
      }
    }

    return res;
  }
};
