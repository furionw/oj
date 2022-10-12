// Date: 2022-10-11
class Restaurant {
 public:
  Restaurant(int id, int rating): id(id), rating(rating) {}
  
  bool operator<(const Restaurant& other) const {
    return rating != other.rating
      ? rating > other.rating
      : id > other.id;
  }
  
  int id;
  int rating;
};

class Solution {
public:
    vector<int> filterRestaurants(vector<vector<int>>& restaurants, int veganFriendly, int maxPrice, int maxDistance) {
      vector<Restaurant> restaurantsVt;
      for (size_t i = 0; i < restaurants.size(); ++i) {
        const auto& r = restaurants[i];
        if (r[2] - veganFriendly < 0 || r[3] > maxPrice || r[4] > maxDistance) {
          continue;
        }
        restaurantsVt.emplace_back(r[0], r[1]);
      }
      sort(restaurantsVt.begin(), restaurantsVt.end());
      vector<int> result;
      result.resize(restaurantsVt.size());
      for (int i = 0; i < restaurantsVt.size(); ++i) {
        result[i] = restaurantsVt[i].id;
      }
      return result;
    }
};