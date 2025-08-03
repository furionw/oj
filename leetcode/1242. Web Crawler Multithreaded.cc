// 2025-08-01
// This solution actually doesn't have high concurrency because of .get() on
// future call
class Solution {
 public:
  vector<string> crawl(string startUrl, HtmlParser htmlParser) {
    auto hostname = getHostname(startUrl);
    unordered_set<string> visited;
    queue<future<vector<string>>> q;
    q.push(async([&]() { return htmlParser.getUrls(startUrl); }));
    visited.insert(startUrl);
    while (!q.empty()) {
      auto urls = q.front().get();
      q.pop();
      for (const auto& url : urls) {
        if (hostname != getHostname(url) || visited.contains(url)) {
          continue;
        }
        visited.insert(url);
        q.push(async([&, url]() { return htmlParser.getUrls(url); }));
      }
    }
    return vector<string>(visited.begin(), visited.end());
  }

 private:
  string getHostname(const string& url) {
    static const string kPrefix = "http://";
    auto pos = url.find('/', kPrefix.size());
    return url.substr(0, pos);
  }
};
