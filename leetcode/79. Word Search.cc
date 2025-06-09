// Copyright 2017 Qi Wang
// 2025-06-05
class Solution {
 public:
  bool exist(vector<vector<char>>& board, string word) {
    m = board.size();
    n = board[0].size();
    visited = vector<vector<bool>>(m, vector<bool>(n, false));
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (exist(board, word, i, j, 0 /*idx*/)) {
          return true;
        }
      }
    }
    return false;
  }

 private:
  // assumption
  //   - x, y are valid index
  //   - board[x][y] not visited before
  //   - don't know if board[x][y] == word[idx]
  bool exist(const vector<vector<char>>& board, const string& word,
      int x, int y, int idx) {
    if (board[x][y] != word[idx]) {
      return false;
    }
    ++idx;
    if (idx == word.size()) {
      return true;
    }
    visited[x][y] = true;
    static vector<vector<int>> deltas = {
      {0, 1}, {0, -1}, {1, 0}, {-1, 0}
    };
    for (const auto& d : deltas) {
      int i = x + d[0];
      int j = y + d[1];
      if (i < 0 || i >= m || j < 0 || j >= n || visited[i][j]) {
        continue;
      }
      if (exist(board, word, i, j, idx)) {
        return true;
      }
    }
    visited[x][y] = false;
    return false;
  }

  vector<vector<bool>> visited;
  int m;
  int n;
};

// 2025-06-05
class Solution {
 public:
  bool exist(vector<vector<char>>& board, string word) {
    m = board.size();
    n = board[0].size();
    visited = vector<vector<bool>>(m, vector<bool>(n, false));
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (board[i][j] == word[0] && exist(board, word, i, j, 1 /*idx*/)) {
          return true;
        }
      }
    }
    return false;
  }

 private:
  bool exist(const vector<vector<char>>& board, const string& word,
      int x, int y, int idx) {
    if (idx == word.size()) {
      return true;
    }
    visited[x][y] = true;
    static vector<vector<int>> deltas = {
      {0, 1}, {0, -1}, {1, 0}, {-1, 0}
    };
    for (const auto& d : deltas) {
      int i = x + d[0];
      int j = y + d[1];
      if (i < 0 || i >= m || j < 0 || j >= n
          || visited[i][j] || board[i][j] != word[idx]) {
        continue;
      }
      if (exist(board, word, i, j, idx + 1)) {
        return true;
      }
    }
    visited[x][y] = false;
    return false;
  }

  vector<vector<bool>> visited;
  int m;
  int n;
};

// Date: 2017-11-07
class Solution {
 public:
  bool exist(vector<vector<char>>& board, string word) {
    if (word.empty()) return true;
    for (int i = 0; i < board.size(); ++i) {
      for (int j = 0; j < board[0].size(); ++j) {
        if (board[i][j] == word.front() && Dfs(&board, i, j, word, 0)) {
          return true;
        }
      }
    }
    return false;
  }
 
 private:
  bool Dfs(vector<vector<char>>* board, int i, int j, const string& word,
           int idx) const {
    if (idx + 1 == word.size()) return true;
    (*board)[i][j] = 0;
    static constexpr int delta[] = {0, 1, 0, -1, 0};
    for (int d = 0; d < 4; ++d) {
      int x = i + delta[d], y = j + delta[d + 1];
      if (0 <= x && x < board->size() && 0 <= y && y < (*board)[0].size() &&
          (*board)[x][y] == word[idx + 1] && Dfs(board, x, y, word, idx + 1)) {
        return true;
      }
    }
    (*board)[i][j] = word[idx];
    return false; 
  }
};

// Date: 2017-08-13
class Solution {
 public:
  bool exist(vector<vector<char>>& board, string word) {
    if (word.empty()) return true;
    for (int i = 0; i < board.size(); ++i) {
      for (int j = 0; j < board[0].size(); ++j) {
        if (board[i][j] == word[0] && F(board, i, j, word, 0)) {
          return true;
        }
      }
    }
    return false;
  }

 private:
  bool F(vector<vector<char>>& board, int x, int y, const string& word,
      int idx) {
    if (idx + 1 == word.size()) return true;
    board[x][y] = '*';
    int delta[] = {0, 1, 0, -1, 0};
    for (int d = 0; d < 4; ++d) {
      int i = x + delta[d], j = y + delta[d + 1];
      if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() ||
          board[i][j] != word[idx + 1]) continue;
      if (F(board, i, j, word, idx + 1)) return true;
    }
    board[x][y] = word[idx];
    return false;
  }
};

// Date: 2017-07-25
class Solution {
 public:
  bool exist(vector<vector<char>>& board, string word) {
    if (board.empty() || board[0].empty()) return word.empty();
    for (int i = 0; i < board.size(); ++i) {
      for (int j = 0; j < board[0].size(); ++j) {
        if (Exist(board, i, j, word, 0)) {
          return true;
        }
      }
    }
    return false;
  }

 private:
  bool Exist(vector<vector<char>>& board, int i, int j,
      const string& word, int idx) const {
    if (board[i][j] == word[idx]) {
      if (idx + 1 == word.size()) return true;
      board[i][j] = -1;
      static constexpr int delta[] = {0, 1, 0, -1, 0};
      for (int d = 0; d < 4; ++d) {
        int x = i + delta[d];
        int y = j + delta[d + 1];
        if (x < 0 || x >= board.size() || y < 0 || y >= board[0].size())
          continue;
        if (Exist(board, x, y, word, idx + 1)) return true;
      }
      board[i][j] = word[idx];
    }
    return false;
  }
};

class Solution 
{
public:
  bool exist(vector<vector<char> > &board, string word) 
  {
    if (board.empty()==true || word.empty()==true)
    {
      return false;
    }
    size_t n=board.size(), m=board[0].size();      
    auto vi = vector<vector<bool>>(n, vector<bool>(m, false));
    for (int i = 0; i < n; ++ i)
    {
      for (int j = 0; j < m; ++ j)
      {
        if (board[i][j] == word[0])
        {
          if (gao(vi, board, i, j, 1, word))
          {
            return true;
          }
        }
      }
    }
    return false;
  }
private:
  bool gao(vector<vector<bool>>& vi, vector<vector<char>>& board,
    int x, int y, size_t cnt, string& word)
  {
    vi[x][y] = true;
    int x_dir[] = {-1, 0, 1, 0};
    int y_dir[] = {0, 1, 0, -1};
    if (cnt == word.size())
    {
      return true;
    }
    for (int i = 0; i < 4; ++ i)
    {
      int x_next = x + x_dir[i];
      int y_next = y + y_dir[i];
      if( x_next>=0 && x_next<board.size()
        && y_next>=0 && y_next<board[0].size()
        && board[x_next][y_next]==word[cnt]
        && vi[x_next][y_next]==false
        && gao(vi, board, x_next, y_next, cnt+1, word) )
      {
        return true;  
      }
    }
    vi[x][y] = false;
    return false;
  }
};