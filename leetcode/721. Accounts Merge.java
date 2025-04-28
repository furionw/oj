// Date: 2020-06-06
class Accounts {
  public String union(String e1, String e2) {
    String p1 = find(e1);
    String p2 = find(e2);
    map.put(p2, p1);
    return p1;
  }

  public List<List<String>> getResult(String name) {
    Map<String, Set<String>> rootToSetMap = new HashMap<String, Set<String>>();
    for (Map.Entry<String, String> entry : map.entrySet()) {
      String p = find(entry.getKey());
      Set<String> set = rootToSetMap.getOrDefault(p, new TreeSet<String>());
      set.add(entry.getKey());
      rootToSetMap.put(p, set);
    }
    List<List<String>> result = new ArrayList<List<String>>();
    for (Map.Entry<String, Set<String>> entry : rootToSetMap.entrySet()) {
      List<String> account = new ArrayList<String>();
      account.add(name);
      account.addAll(entry.getValue());
      result.add(account);
    }
    return result;
  }

  private String find(String email) {
    if (map.containsKey(email)) {
      String parent = map.get(email);
      if (!email.equals(parent)) {
        parent = find(parent);
        map.put(email, parent);
      }
      return parent;
    } else {
      map.put(email, email);
      return email;
    }
  }

  public Map<String, String> map = new HashMap<String, String>();
}

class Solution {
  public List<List<String>> accountsMerge(List<List<String>> accounts) {
    Map<String, Accounts> nameToAccountsMap = new HashMap<String, Accounts>();
    for (List<String> account : accounts) {
      String name = account.get(0);
      List<String> emails = account.subList(1, account.size());
      Accounts set = nameToAccountsMap.getOrDefault(name, new Accounts());
      String p = set.union(emails.get(0), emails.get(0));
      for (int i = 1; i < emails.size(); ++i) {
        p = set.union(p, emails.get(i));
      }
      nameToAccountsMap.put(name, set);
    }
    List<List<String>> result = new ArrayList<List<String>>();
    for (Map.Entry<String, Accounts> entry : nameToAccountsMap.entrySet()) {
      result.addAll(entry.getValue().getResult(entry.getKey()));
    }
    return result;
  }
}