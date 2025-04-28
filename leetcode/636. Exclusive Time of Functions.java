// Date: 2020-06-03
class Solution {
  public int[] exclusiveTime(int n, List<String> logs) {
    int[] result = new int[n];
    while (idx < logs.size()) {
      helper(parseTimestamp(logs.get(idx++)), logs, result);
    }
    return result;
  }

  private int helper(Timestamp startTs, List<String> logs, int[] result) {
    int deduct = 0;
    while (idx < logs.size()) {
      if (logs.get(idx).indexOf('s') != -1) {
        deduct += helper(parseTimestamp(logs.get(idx++)), logs, result);
      } else {
        int endTime = parseTimestamp(logs.get(idx++)).timestamp;
        int inc = endTime - startTs.timestamp + 1 - deduct;
        result[startTs.id] += inc;
        return endTime - startTs.timestamp + 1;
      }
    }
    return -1; // comfort the compiler
  }

  Timestamp parseTimestamp(String log) {
    return new Timestamp(Integer.valueOf(log.substring(0, log.indexOf(':'))),
        Integer.valueOf(log.substring(log.lastIndexOf(':') + 1)));
  }

  class Timestamp {
    Timestamp(int id, int timestamp) {
      this.id = id;
      this.timestamp = timestamp;
    }

    int id;
    int timestamp;
  }

  private int idx = 0;
}

// Not used. too complicated
class Process implements Comparable<Process> {
  Process(int id, int start, int end) {
    this.id;
    this.start = start;
    this.end = end;
    subProcesses = new ArrayList<Process>();
  }
  
  public void insert(Process p) {
    bool inserted = false;
    for (Process subP : subProcesses) {
      if (subP.end >= p.end) {
        subP.insert(p);
        inserted = true;
        break;
      }
    }
    if (!inserted) {
      subProcesses.add(p);
    }
  }
  
  public void set(int[] result) {
    result[id] = subProcesses
        .stream()
        .reduce(time(), (acc, elem) -> acc + elem.time());
    subProcesses.parallelStream(p -> p.set(result));
  }
  
  public void time() {
    return end - start + 1;
  }
  
  @Override
  public int compareTo(Process other) {
    return start < other.start ? -1 : 1;
  }
  
  public int id;
  public int start;
  public int end;
  public List<Process> subProcesses;
}

class Solution {
  public int[] exclusiveTime(int n, List<String> logs) {
    PriorityQueue<Process> pq = new PriorityQueue<Process>
    
    int[] result = new int[n];
  }
}
