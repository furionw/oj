// Copyright 2016 Qi Wang
// Date: 2016-10-23
#include <iostream>
#include <string>
#include <memory>
#include <numeric>
#include <vector>

using std::cin;
using std::string;

struct Trie {
  void insert(const string& str, size_t idx) {
    ++cnt;
    if (idx == str.size()) return;
    if (children[str[idx] - 'a'] == nullptr)
      children[str[idx] - 'a'] = std::make_shared<Trie>();
    children[str[idx] - 'a']->insert(str, idx + 1);
  }

  int count() const {
    return cnt <= 5
        ? 1
        : std::accumulate(children.begin(), children.end(), 0,
            [this](int cnt, const std::shared_ptr<Trie>& child) {
              return cnt + (child != nullptr ? child->count() : 0);
            });
  }

  int cnt = 0;
  std::vector<std::shared_ptr<Trie>> children =
      std::vector<std::shared_ptr<Trie>>(26, nullptr);
};

int main() {
  int n;
  cin >> n;
  Trie tree;
  while (n--) {
    string str;
    cin >> str;
    tree.insert(str, 0);
  }
  std::cout << tree.count() << std::endl;
}
