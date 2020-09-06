// Date: 2020-09-05
class Solution {
  public int[] findRedundantConnection(int[][] edges) {
    int n = edges.length;
    int[] p = new int[n + 1];
    for (int i = 1; i <= n; ++i) {
      p[i] = i;
    }
    for (int[] edge : edges) {
      int u = edge[0];
      int v = edge[1];
      int x = parent(p, u);
      int y = parent(p, v);
      if (x == y) {
        return new int[] {u, v};
      } else {
        p[y] = x;
      }
    }
    return new int[]{0, 0};
  }

  private int parent(int[] p, int n) {
    return p[n] == n ? n : (p[n] = parent(p, p[n]));
  }
}
