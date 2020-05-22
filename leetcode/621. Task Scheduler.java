// Copyright 2020 Qi Wang
// Date: 2020-05-22
// Refer to Xiaohan's solution
class Solution {
  public int leastInterval(char[] tasks, int n) {
    int[] count = new int[26];
    int round = 0, intraRoundTasks = 0;
    for (char t : tasks) {
      count[t - 'A']++;
      if (count[t - 'A'] > round) {
        round = count[t - 'A'];
        intraRoundTasks = 1;
      } else if (count[t - 'A'] == round) {
        intraRoundTasks++;
      }
    }
    return Math.max(tasks.length, (round - 1) * (n + 1) + intraRoundTasks);
  }
}

// Date: 2020-05-22
// Note that the C++ solution on 2017-08-07 seems more concise.
class Task implements Comparable<Task> {
  public short label;
  public short remain;

  public Task(short l, short r) {
    label = l;
    remain = r;
  }

  public int compareTo(Task other) {
    if (remain != other.remain) {
      return remain < other.remain ? 1 : -1;
    } else {
      return label < other.label ? 1 : (label == other.label ? 0 : -1);
    }
  }
}

class Solution {
  public int leastInterval(char[] tasks, int n) {
    if (tasks.length == 0) {
      return 0;
    }
    short[] charToCntMap = new short[26];
    for (char label : tasks) {
      ++charToCntMap[label - 'A'];
    }
    PriorityQueue<Task> pq = new PriorityQueue<Task>();
    for (short i = 0; i < 26; ++i) {
      if (charToCntMap[i] > 0) {
        pq.add(new Task(i, charToCntMap[i]));
      }
    }
    int[] charToLastExecuteMap = new int[26];
    for (short i = 0; i < 26; ++i) {
      charToLastExecuteMap[i] = -n;
    }
    int t = 0;
    do {
      ++t;
      ArrayList<Task> cooling = new ArrayList<Task>();
      while (!pq.isEmpty()) {
        Task task = pq.poll();
        if (charToLastExecuteMap[task.label] + n >= t) {
          cooling.add(task);
        } else {
          charToLastExecuteMap[task.label] = t;
          if (task.remain - 1 > 0) {
            pq.add(new Task(task.label, (short)(task.remain - 1)));
          }
          break;
        }
      }
      for (Task task : cooling) {
        pq.add(task);
      }
    } while (!pq.isEmpty());
    return t;
  }
}
