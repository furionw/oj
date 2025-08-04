// 2019-10-23
class Solution {
  // Dijkstra 求 single source shortest path
  // 这道题是求 single source 到其余所有点的 shortest path, 然后取最大值
  public int networkDelayTime(int[][] times, int N, int src) {
    int[][] map = new int[N + 1][N + 1];
    for (int i = 1; i <= N; ++i) {
      // 标记从点 i 到任何点都是不可达的
      Arrays.fill(map[i], Integer.MAX_VALUE);
    }
    for (int[] edge : times) {
      // 使用 Math.min 处理输入 (times) 中含有平行边（两条长度不同，但都是从点 a 到点 b）
      // 的情况 —— 我们总是取最短的边
      map[edge[0]][edge[1]] = Math.min(map[edge[0]][edge[1]], edge[2]);
    }
    int[] dist = new int[N + 1];
    // 标记所有点离起始点都无穷远
    Arrays.fill(dist, Integer.MAX_VALUE);
    dist[src] = 0;
    boolean[] visited = new boolean[N + 1];
    Arrays.fill(visited, false);
    while (true) {
      int u = -1;
      int min = Integer.MAX_VALUE;
      for (int i = 1; i <= N; ++i) {
        if (!visited[i] && dist[i] < min) {
          u = i;
          min = dist[i];
        }
      }
      // 再也找不到“未访问过” (!visited[i]) 并且“可达” (dist[i] < Integer.MAX_VALUE) 的点了
      if (u == -1) {
        break;
      }
      visited[u] = true; // 千万别忘了这行哦
      for (int v = 1; v <= N; ++v) {
        // 不要丢了 map[u][v] != Integer.MAX_VALUE，不然 Integer.MAX_VALUE + min 会溢出的
        if (map[u][v] != Integer.MAX_VALUE && min + map[u][v] < dist[v]) {
          dist[v] = min + map[u][v];
        }
      }
    }
    return getResult(dist);
  }

  private int getResult(int[] dist) {
    // copyOfRange: 剔除第 0 个元素，取 dist[1, ..., N]
    int max = Arrays.stream(Arrays.copyOfRange(dist, 1, dist.length + 1)).max().getAsInt();
    return max != Integer.MAX_VALUE ? max : -1;
  }
}
