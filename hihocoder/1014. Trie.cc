// Copyright 2016 Qi Wang
// Date: 2016-10-12
#include <iostream>
#include <vector>
#include <memory>
#include <string>
#include <numeric>

using namespace std;

struct Trie {
  void insert(const string& str, size_t i) {
    ++cnt;
    if (i < str.size()) {
      if (children[str[i] - 'a'] == nullptr)
        children[str[i] - 'a'] = make_shared<Trie>();
      children[str[i] - 'a']->insert(str, i + 1);
    }
  }

  int count(const string& str, size_t i) const {
    if (i < str.size()) {
      return children[str[i] - 'a'] == nullptr
          ? 0 : children[str[i] - 'a']->count(str, i + 1);
    } else {
      return cnt;
    }
  }

  int cnt = 0;
  vector<shared_ptr<Trie>> children = vector<shared_ptr<Trie>>(26, nullptr);
};

int main() {
  int num;
  cin >> num;
  auto root = make_shared<Trie>();
  while (num--) {
    string str;
    cin >> str;
    root->insert(str, 0);
  }
  cin >> num;
  while (num--) {
    string str;
    cin >> str;
    cout << root->count(str, 0) << endl;
  }
}
