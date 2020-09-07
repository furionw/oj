// Date: 2020-09-07
class Solution {
  public boolean equationsPossible(String[] equations) {
    int[] parent = new int[26];
    for (int i = 0; i < 26; ++i) {
      parent[i] = i;
    }
    for (String e : equations) {
      if (e.charAt(1) == '=') {
        int u = e.charAt(0) - 'a';
        int v = e.charAt(3) - 'a';
        int x = unionFind(parent, u);
        int y = unionFind(parent, v);
        parent[y] = x;
      }
    }
    for (String e : equations) {
      if (e.charAt(1) == '!') {
        int u = e.charAt(0) - 'a';
        int v = e.charAt(3) - 'a';
        if (unionFind(parent, u) == unionFind(parent, v)) {
          return false;
        }
      }
    }
    return true;
  }
  
  private int unionFind(int[] p, int u) {
    return p[u] == u ? u : (p[u] = unionFind(p, p[u]));
  }
}
