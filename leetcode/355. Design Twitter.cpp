// Copyright 2016 Qi Wang
// Date: 2016-10-08
class Twitter {
 public:
  /** Compose a new tweet. */
  void postTweet(int userId, int tweetId) {
    tweets.emplace_front(userId, tweetId);
  }
    
  /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
  vector<int> getNewsFeed(int userId) {
    vector<int> res;
    for (auto tweet : tweets)
      if (res.size() < 10 && (tweet.first == userId
          || followees[userId].find(tweet.first) != followees[userId].end()))
        res.push_back(tweet.second);
    return res;
  }
    
  /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
  void follow(int followerId, int followeeId) {
    followees[followerId].insert(followeeId);
  }
    
  /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
  void unfollow(int followerId, int followeeId) {
    followees[followerId].erase(followeeId);
  }

 private:
  unordered_map<int, unordered_set<int>> followees;
  // <userId, tweetId>
  list<pair<int, int>> tweets;
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter obj = new Twitter();
 * obj.postTweet(userId,tweetId);
 * vector<int> param_2 = obj.getNewsFeed(userId);
 * obj.follow(followerId,followeeId);
 * obj.unfollow(followerId,followeeId);
 */
