// Date: 2020-09-07
// Refer to:
//   - http://www.personal.kent.edu/~rmuhamma/Algorithms/MyAlgorithms/GraphAlgor/strongComponent.htm
//   - https://leetcode.com/problems/course-schedule/discuss/249688/Different-O(V%2BE)-solution-using-Kosaraju's-algorithm
class Solution {
  public boolean canFinish(int numCourses, int[][] prerequisites) {
    List<Integer>[] g = new ArrayList[numCourses];
    List<Integer>[] rg = new ArrayList[numCourses];
    for (int i = 0; i < numCourses; ++i) {
      g[i] = new ArrayList<Integer>();
      rg[i] = new ArrayList<Integer>();
    }
    for (int[] pre : prerequisites) {
      g[pre[0]].add(pre[1]);
      rg[pre[1]].add(pre[0]);
    }
    boolean[] visited = new boolean[numCourses];
    Stack<Integer> stk = new Stack<Integer>();
    // 1st dfs on g
    for (int i = 0; i < numCourses; ++i) {
      if (!visited[i]) {
        dfs(i, g, visited, stk);
      }
    }
    // 2nd dfs on reversed graph, rg
    Arrays.fill(visited, false);
    while (!stk.isEmpty()) {
      int u = stk.pop();
      if (!visited[u] && dfs(u, rg, visited) > 1) {
        return false;
      }
    }
    return true;
  }
  
  private void dfs(int u, List<Integer>[] g, boolean[] visited, Stack<Integer> stk) {
    visited[u] = true;
    g[u].stream()
        .filter(v -> !visited[v])
        .forEach(v -> dfs(v, g, visited, stk));
    stk.push(u);
  }
  
  private int dfs(int u, List<Integer>[] g, boolean[] visited) {
    visited[u] = true;
    return g[u].stream()
        .filter(v -> !visited[v])
        .reduce(1, (acc, v) -> acc + dfs(v, g, visited));
  }
}