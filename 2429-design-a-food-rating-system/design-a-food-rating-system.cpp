class FoodRatings {
public:
struct Comp {
    bool operator()(const pair<int,string>& a, const pair<int,string>& b) const {
        if (a.first == b.first) {
            return a.second > b.second;
        }
        return a.first < b.first;
    }
};
unordered_map<string,int> fmp;
unordered_map<string,string> cs;
unordered_map<string, priority_queue<pair<int,string>, vector<pair<int,string>>, Comp>> hr;
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        for(int i=0;i<foods.size();i++){
            fmp[foods[i]]=ratings[i];
            hr[cuisines[i]].push({ratings[i],foods[i]});
            cs[foods[i]]=cuisines[i];
        }
    }
    
    void changeRating(string food, int newRating) {
        fmp[food]=newRating;
        hr[cs[food]].push({newRating,food});
    }
    
    string highestRated(string cuisine) {
        auto &pq = hr[cuisine];
        while(pq.size()){
            auto pr=pq.top();
            int rating=pr.first;
            string food=pr.second;
            if(fmp[food]==rating)
            return food;
            pq.pop();
        }
        return "";
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */