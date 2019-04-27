# Copyright 2019 Qi Wang
# Date: 2019-04-27
class Solution:
    def twoCitySchedCost(self, costs: List[List[int]]) -> int:
        costs.sort(key=lambda elem: abs(elem[0] - elem[1]), reverse=True)
        result = 0
        first_city_cnt = 0
        second_city_cnt = 0
        city_limit = len(costs) / 2
        for cost in costs:
            if first_city_cnt == city_limit:
                result += cost[1]
            elif second_city_cnt == city_limit:
                result += cost[0]
            elif cost[0] < cost[1]:
                result += cost[0]
                first_city_cnt += 1
            else:
                result += cost[1]
                second_city_cnt += 1
        return result
