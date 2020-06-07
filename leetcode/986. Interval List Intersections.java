// Date: 2020-06-07
class Solution {
  public int[][] intervalIntersection(int[][] A, int[][] B) {
    List<int[]> result = new ArrayList<int[]>();
    int[] candidate = null;
    for (int i = 0, j = 0; i < A.length && j < B.length; ) {
      if (A[i][1] == B[j][1]) {
        result.add(new int[] { Math.max(A[i][0], B[j][0]), A[i][1]});
        ++i;
        ++j;
      } else if (A[i][1] < B[j][1]) {
        if (A[i][1] >= B[j][0]) {
          result.add(new int[] { Math.max(B[j][0], A[i][0]), A[i][1] });
        }
        ++i;
      } else {
        if (B[j][1] >= A[i][0]) {
          result.add(new int[] { Math.max(A[i][0], B[j][0]), B[j][1] });
        }
        ++j;
      }
    }
    return result.toArray(new int[0][]);
  }
}
