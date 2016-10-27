#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <memory>

using namespace std;

class RuleNode {
public:
  void insert(const string& type, unsigned int ip, int mask_cnt) {
    // the more loose or equivalently strict rule has appeared before.
    if (rule_) { return ; }

    if (mask_cnt == 0) {
      allow_ = type == "allow";
      rule_ = true;
      return;
    }

    if (most_siginificant_bit(ip) == LEFT_) {
      if (left_ == nullptr) left_ = make_shared<RuleNode>();
      left_->insert(type, ip << 1, -- mask_cnt);
    } else {
      if (right_ == nullptr) right_ = make_shared<RuleNode>();
      right_->insert(type, ip << 1, -- mask_cnt);
    }
  }

  bool match(unsigned int ip) {
    if (most_siginificant_bit(ip) == LEFT_) {
      if (left_ != nullptr) {
        if (left_->match(ip << 1)) return true;
      }
    } else {
      if (right_ != nullptr) {
        if (right_->match(ip << 1)) return true;
      }
    }
    if (rule_) {
      cout << (allow_? "YES": "NO") << endl;
      return true;
    } else {
      return false;
    }
  }

  inline unsigned int most_siginificant_bit(unsigned int ip) {
    return (ip & (1 << 31));
  }

private:
  bool allow_ = false;
  bool rule_ = false;
  shared_ptr<RuleNode> left_ = nullptr;
  shared_ptr<RuleNode> right_ = nullptr;
  const static int LEFT_ = 0;
};

unsigned int parse_ip(string& str) {
  unsigned int ip = 0;
  for (int i = 0; i < 3; ++ i) {
    size_t len = str.find('.');
    ip = ip * 256 + stoi(str.substr(0, len));
    str = str.substr(len + 1);
  }
  size_t len = str.find('/');
  ip = ip * 256 + stoi(str.substr(0, len));
  str = len != string::npos? str.substr(len + 1): "";
  return ip;
}

int main() {
  int n, m;
  cin >> n >> m;
  shared_ptr<RuleNode> root(new RuleNode());

  while (n-- != 0) {
    // type
    string type;
    cin >> type;
    // ip and mask
    string ip_and_mask;
    cin >> ip_and_mask;
    unsigned int ip = parse_ip(ip_and_mask);
    // mask_cnt
    unsigned int mask_cnt;
    if (ip_and_mask != "") {
      mask_cnt = stoi(ip_and_mask);
    } else {
      mask_cnt = 32;
    }
    // insert
    root->insert(type, ip, mask_cnt);
  }

  while (m -- != 0) {
    string str;
    cin >> str;
    if (! root->match(parse_ip(str))) { cout << "YES" << endl; }
  }
}