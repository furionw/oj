// Date: 2020-09-15
class Solution {
  int ts = -1;
  
  public List<List<Integer>> criticalConnections(int n, List<List<Integer>> connections) {
    List<Integer>[] g = new ArrayList[n];  // ?
    for (int i = 0; i < n; ++i) {
      g[i] = new ArrayList<Integer>();
    }
    for (List<Integer> connection : connections) {
      int u = connection.get(0), v = connection.get(1);
      g[u].add(v);
      g[v].add(u);
    }
    boolean[] visited = new boolean[n];
    boolean[] inStk = new boolean[n];
    int[] enter = new int[n];
    int[] low = new int[n];
    Stack<Integer> stk = new Stack<Integer>();
    for (int i = 0; i < n; ++i) {
      if (!visited[i]) {
        dfs(i, -1 /*parent*/, g, visited, enter, low, stk, inStk);
      }
    }
    return connections.stream()
        .filter(conn -> low[conn.get(0)] != low[conn.get(1)])
        .collect(Collectors.toList());
    // List<List<Integer>> result = new ArrayList<List<Integer>>();
    // for (List<Integer> connection : connections) {
    //   if (low[connection.get(0)] != low[connection.get(1)]) {
    //     result.add(connection);
    //   }
    // }
    // return result;
  }
  
  private void dfs(
      int u,
      int parent,
      List<Integer>[] g,
      boolean[] visited,
      int[] enter,
      int[] low,
      Stack<Integer> stk,
      boolean[] inStk
  ) {
    visited[u] = true;
    enter[u] = low[u] = ++ts;
    stk.add(u);
    inStk[u] = true;
    g[u].stream()
        .filter(v -> v != parent)
        .forEach(v -> {
          if (!visited[v]) {
            dfs(v, u /*parent*/, g, visited, enter, low, stk, inStk);
          }
          if (inStk[v]) {
            low[u] = Math.min(low[u], low[v]);
          }
        });
    if (enter[u] == low[u]) {
      for (int v = stk.pop(); v != u; v = stk.pop()) {
        inStk[v] = false;
        low[v] = enter[u];
      }
      inStk[u] = false;
    }
  }
}


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
