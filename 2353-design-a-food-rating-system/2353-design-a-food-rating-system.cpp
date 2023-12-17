class FoodRatings {
public:
    unordered_map<string,set<pair<int,string>>>rt;//cuisines,rating,food
    unordered_map<string,pair<int,string>>mp;//food,rating,cuisines
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        int n=foods.size();
        for(int i=0;i<n;i++){
            string food=foods[i],cuisine=cuisines[i];
            int rate=ratings[i];
            rt[cuisine].insert({-rate,food});
            mp[food]={-rate,cuisine};
        }
    }
    void changeRating(string food, int newRating) {
        string cuisine=mp[food].second;
        int r=mp[food].first;
        mp[food]={-newRating,cuisine};
        rt[cuisine].erase({r,food});
        rt[cuisine].insert({-newRating,food});
    }
    
    string highestRated(string cuisine) {
        return rt[cuisine].begin()->second;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */