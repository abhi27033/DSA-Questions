class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        unordered_set<int> broke;
        for(auto it:friendships){
            unordered_set<int> s1,s2;
            for(auto itt:languages[it[0]-1])s1.insert(itt);
            for(auto itt:languages[it[1]-1])s2.insert(itt);
            int flg=-1;
            for(auto itt:s1){
                if(s2.find(itt)!=s2.end()){
                    flg=1;
                    break;
                }
            }
            if(flg==-1){
            broke.insert(it[0]);
            broke.insert(it[1]);
            }
        }
        vector<int> langspoken(n+1,0);
        for(auto it:broke){
            for(auto itt:languages[it-1])
            langspoken[itt]++;
        }
        int ma=-1,mai=INT_MIN;
        for(int i=0;i<=n;i++){
            if(mai<langspoken[i]){
                mai=langspoken[i];
                ma=i;
            }
        }
        return broke.size()-mai;
    }
};
// 1 -> 2
//   -> 3
// 2 -> 3