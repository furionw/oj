// Date: 2022-10-08
class Solution {
 public:
   int hardestWorker(int n, vector<vector<int>>& logs) {
     int id = 0;
     int maxT = 0;
     int prevT = 0;
     for (const auto& log : logs) {
       int took = log[1] - prevT;
       if (took > maxT) {
         maxT = took;
         id = log[0];
       } else if (took == maxT) {
         id = min(id, log[0]);
       }
       prevT = log[1];
     }
     return id;
   }
};
