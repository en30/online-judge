#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for (int i = 0; i < (int)N; i++)

class DoublyLinkedList {
  struct Element {
    int key;
    Element *prev;
    Element *next;
  };
  Element *nil;
  friend std::ostream& operator<<(std::ostream&, const DoublyLinkedList&);

  void del(Element *e) {
    if(e == nil) return;
    e->prev->next = e->next;
    e->next->prev = e->prev;
    delete e;
  }

public:
  DoublyLinkedList() {
    nil = new Element;
    nil->next = nil;
    nil->prev = nil;
  }

  void insert(int key) {
    Element *e = new Element{key, nullptr, nullptr};
    e->next = nil->next;
    nil->next->prev = e;
    nil->next = e;
    e->prev = nil;
  }

  void deleteFristKey(int key) {
    Element *e = nil->next;
    while(e != nil && e->key != key) e = e->next;
    del(e);
  }

  void deleteFirst() {
    del(nil->next);
  }

  void deleteLast() {
    del(nil->prev);
  }
};

std::ostream& operator<<(std::ostream &strm, const DoublyLinkedList &l) {
  DoublyLinkedList::Element *e = l.nil->next;
  while(true) {
    strm << e->key;
    e = e->next;
    if(e == l.nil) {
      strm << endl;
      break;
    } else {
      strm << " ";
    }
  }
  return strm;
}

int main () {
  int n;
  cin >> n;
  DoublyLinkedList list;
  string c;
  int key;
  rep(i,n) {
    cin >> c;
    if(c == "insert") {
      cin >> key;
      list.insert(key);
    } else if (c == "delete") {
      cin >> key;
      list.deleteFristKey(key);
    } else if (c == "deleteFirst") {
      list.deleteFirst();
    } else if (c == "deleteLast"){
      list.deleteLast();
    }
  }
  cout << list;

  return 0;
}
