// Copyright 2020 Qi Wang
// Date: 2020-05-25
class Solution {
  public int[][] merge(int[][] intervals) {
    if (intervals == null || intervals.length == 0) {
      return intervals;
    }
    List<int[]> result = new ArrayList<int[]>();
    Arrays.sort(intervals, (a, b) -> {
      if (a[0] != b[0]) {
        return a[0] < b[0] ? -1 : 1;
      } else if (a[1] != b[1]) {
        return a[1] < b[1] ? -1 : 1;
      } else {
        return 0;
      }
    });
    for (int i = 0; i < intervals.length;) {
      int begin = intervals[i][0], end = intervals[i][1];
      int j = i + 1;
      for (; j < intervals.length; ++j) {
        if (intervals[j][0] <= end) {
          end = Math.max(end, intervals[j][1]);
        } else {
          break;
        }
      }
      i = j;
      result.add(new int[] {begin, end});
    }
    return result.toArray(new int[0][]);
  }
}
