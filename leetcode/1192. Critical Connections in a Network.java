// Copyright 2019 Qi Wang
// Date: 2019-10-27
// Refer to: https://www.cnblogs.com/nullzx/p/7968110.html
public class Solution {
  int timestamp = 0;

  public List<List<Integer>> criticalConnections(int n, List<List<Integer>> connections) {
    List<Integer>[] graph = new ArrayList[n];
    for (int i = 0; i < n; ++i) {
      graph[i] = new ArrayList<Integer>();
    }
    for (List<Integer> edge : connections) {
      int x = edge.get(0), y = edge.get(1);
      graph[x].add(y);
      graph[y].add(x);
    }
    int[] parent = new int[n];
    int[] timestamps = new int[n];
    int[] low = new int[n];
    boolean[] visited = new boolean[n];
    List<List<Integer>> result = new ArrayList<List<Integer>>();
    parent[0] = -1;
    dfs(0, graph, parent, timestamps, low, visited, result);
    return result;
  }

  private void dfs(int u, List<Integer>[] graph, int[] parent, int[] timestamps, int[] low,
      boolean visited[], List<List<Integer>> result) {
    timestamps[u] = low[u] = timestamp++;
    visited[u] = true;
    for (int v : graph[u]) {
      if (!visited[v]) {
        parent[v] = u;
        dfs(v, graph, parent, timestamps, low, visited, result);
        low[u] = Math.min(low[u], low[v]);
        if (low[v] > timestamps[u]) {
          List<Integer> edge = new ArrayList<Integer>();
          edge.add(u);
          edge.add(v);
          result.add(edge);
        }
      } else if (parent[u] != v) {
        low[u] = Math.min(low[u], timestamps[v]);
      }
    }
  }
}
