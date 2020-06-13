// Date: 2020-06-13
class PQNode implements Comparable<PQNode> {
  PQNode(int x, int v) {
    this.x = x;
    this.v = v;
  }
  
  @Override
  public int compareTo(PQNode other) {
    if (x != other.x) {
      return x < other.x ? -1 : 1;
    } else if (v != other.v) {
      return v < other.v ? -1 : 1;
    } else {
      return 0;
    }
  }
  
  public int x;
  public int v;
}

class Solution {
  public List<List<Integer>> verticalTraversal(TreeNode root) {
    Map<Integer, PriorityQueue<PQNode>> map =
        new TreeMap<Integer, PriorityQueue<PQNode>>();
    helper(root, 0, 0, map);
    List<List<Integer>> result = new ArrayList<List<Integer>>();
    for (PriorityQueue<PQNode> pq : map.values()) {
      List<Integer> tmp = new ArrayList<Integer>();
      while (!pq.isEmpty()) {
        tmp.add(pq.poll().v);
      }
      result.add(tmp);
    }
    return result;
  }
  
  private void helper(TreeNode node, int x, int y,
                      Map<Integer, PriorityQueue<PQNode>> map) {
    if (node == null) {
      return;
    }
    if (map.containsKey(y)) {
      map.get(y).add(new PQNode(x, node.val));
    } else {
      PriorityQueue<PQNode> pq = new PriorityQueue<PQNode>();
      pq.add(new PQNode(x, node.val));
      map.put(y, pq);
    }
    helper(node.left, x + 1, y - 1, map);
    helper(node.right, x + 1, y + 1, map);
  }
}
