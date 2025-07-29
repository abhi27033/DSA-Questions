class SmallestInfiniteSet {
public:
int cnt;
priority_queue<int,vector<int>,greater<int>> ar;
unordered_set<int> pr;
    SmallestInfiniteSet() {
        cnt=1;
    }
    
    int popSmallest() {
        if(ar.size()&&ar.top()<cnt)
        {
            int ans= ar.top();
            pr.erase(ans);
            ar.pop();
            return ans;
        }
        int ans=cnt;
        cnt++;
        return ans;
    }
    
    void addBack(int num) {
        if(cnt>num&&pr.find(num)==pr.end())
        {
        pr.insert(num);
        ar.push(num);
        }
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */