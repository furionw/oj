// Date: 2020-06-13
class Solution {
  public boolean hasValidPath(int[][] grid) {
    int[] left = new int[] {0, -1};
    int[] right = new int[] {0, 1};
    int[] up = new int[] {-1, 0};
    int[] down = new int[] {1, 0};
    int[][][] roadToDirMap = new int[][][] {
      {},
      {left, right},
      {up, down},
      {left, down},
      {right, down},
      {up, left},
      {up, right}
    };
    int m = grid.length, n = grid[0].length;
    boolean[][] visited = new boolean[m][n];
    Queue<int[]> q = new LinkedList<int[]>();
    q.offer(new int[] {0, 0});
    while (!q.isEmpty()) {
      int[] v = q.poll();
      int i = v[0], j = v[1];
      if (i == m - 1 && j == n - 1) {
        return true;
      }
      for (int[] dir : roadToDirMap[grid[i][j]]) {
        int x = i + dir[0], y = j + dir[1];
        if (x < 0 || x >= grid.length || y < 0 || y >= grid[0].length ||
            visited[x][y]) {
          continue;
        }
        for (int[] backDir : roadToDirMap[grid[x][y]]) {
          int backI = x + backDir[0], backJ = y + backDir[1];
          if (i == backI && j == backJ) {
            visited[x][y] = true;
            q.offer(new int[] {x, y});
            break;
          }
        }
      }
    }
    return false;
  }
}