// 2019-10-23
class Solution {
  class Stop {
    int cost;
    int prev;
    int name;
    int stop;
    public Stop(int n, int p, int c, int s) {
      name = n;
      prev = p;
      cost = c;
      stop = s;
    }
  }
  
  public int findCheapestPrice(int n, int[][] flights, int src, int dst, int K) {
    Map<Integer, Map<Integer, Integer>> map = new HashMap<Integer, Map<Integer, Integer>>();
    Map<Integer, Stop> stopMap = new HashMap<Integer, Stop>(); 
    for (int[] flight : flights) {
      map.putIfAbsent(flight[0], new HashMap<Integer, Integer>());
      map.putIfAbsent(flight[1], new HashMap<Integer, Integer>());
      stopMap.putIfAbsent(flight[0], new Stop(flight[0], -1, Integer.MAX_VALUE, 0));
      stopMap.putIfAbsent(flight[1], new Stop(flight[1], -1, Integer.MAX_VALUE, 0));
      map.get(flight[0]).put(flight[1], flight[2]);
    }
    Queue<Stop> queue = new LinkedList<Stop>();
    Stop start = stopMap.get(src);
    start.cost = 0;
    queue.offer(start);
    int min = Integer.MAX_VALUE;
    while (!queue.isEmpty()) {
      Stop curr = queue.poll();
      if (curr.name == dst) {
        if (curr.cost < min) {
          min = curr.cost;
          continue;
        }
      }
      for (Map.Entry<Integer, Integer> edge : map.get(curr.name).entrySet()) {
        int name = edge.getKey();
        int newCost = edge.getValue() + curr.cost;
        int newStop = curr.stop + 1;
        if (newStop > K + 1) {
          break;
        }
        if (newCost > stopMap.get(name).cost) {
          continue;
        }
        stopMap.get(name).cost = newCost;
        stopMap.get(name).prev = curr.name;
        queue.offer(new Stop(name, curr.name, newCost, newStop));
      }
    }
    // print path
    StringBuilder path = new StringBuilder();
    int pre = dst;
    while (pre != -1) {
      path.append(pre + ",");
      pre = stopMap.get(pre).prev;
    }
    System.out.println(path.reverse().toString().substring(1));
    return min == Integer.MAX_VALUE? - 1: min;
  }
}
