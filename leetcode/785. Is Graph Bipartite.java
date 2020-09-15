// Copyright 2020-06-06
class Solution {
  public boolean isBipartite(int[][] graph) {
    boolean[] visited = new boolean[graph.length];
    Set<Integer> setA = new HashSet<Integer>();
    Set<Integer> setB = new HashSet<Integer>();
    for (int i = 0; i < graph.length; ++i) {
      if (visited[i] != true && !f(i, visited, graph, setA, setB)) {
        return false;
      }
    }
    return true;
  }
  
  private boolean f(int u, boolean[] visited, int[][] graph,
                    Set<Integer> currentSet, Set<Integer> otherSet) {
    if (visited[u]) {
      return currentSet.contains(u);
    }
    visited[u] = true;
    currentSet.add(u);
    for (int v: graph[u]) {
      if (!f(v, visited, graph, otherSet, currentSet)) {
        return false;
      }
    }
    return true;
  }
}
