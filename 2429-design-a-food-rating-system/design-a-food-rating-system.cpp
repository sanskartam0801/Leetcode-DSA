class FoodRatings {
public:
    struct Comp {
        bool operator()(const pair<int,string>& a, const pair<int,string>& b) const {
            if (a.first == b.first) return a.second > b.second; 
            return a.first < b.first; 
        }
    };

    unordered_map<string, priority_queue<pair<int,string>, vector<pair<int,string>>, Comp>> cuisine_map;
    unordered_map<string,string> food_cuisine;   // food -> cuisine
    unordered_map<string,int> food_rating;       // food -> rating
    
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        int n = foods.size();
        for(int i=0; i<n; i++){
            cuisine_map[cuisines[i]].push({ratings[i], foods[i]});
            food_cuisine[foods[i]] = cuisines[i];
            food_rating[foods[i]] = ratings[i];
        }
    }
    
    void changeRating(string food, int newRating) {
        string c = food_cuisine[food];
        food_rating[food] = newRating;
        cuisine_map[c].push({newRating, food}); // push new entry, old one stays (lazy deletion)
    }
    
    string highestRated(string cuisine) {
        auto &pq = cuisine_map[cuisine];
        while (!pq.empty()) {
            auto [rating, food] = pq.top();
            if (food_rating[food] == rating) {
                return food; // valid entry
            }
            pq.pop(); // remove outdated entry
        }
        return ""; // shouldn't happen
    }
};
